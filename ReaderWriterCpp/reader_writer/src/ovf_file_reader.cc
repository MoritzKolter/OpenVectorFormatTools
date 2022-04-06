#include <optional>
#include <mutex>
#include <fstream>
#include <algorithm>

#include "google/protobuf/util/delimited_message_util.h"
#include "google/protobuf/io/zero_copy_stream_impl_lite.h"

#include "ovf_file_reader.h"
#include "open_vector_format.pb.h"
#include "consts.h"
#include "util.h"

#ifdef WIN32
#  include "memory_mapping_win32.h"
#else
#  error POSIX
#endif

namespace open_vector_format::reader_writer {


OvfFileReader::OvfFileReader(uint64_t auto_cache_threshold)
    : auto_cache_threshold_{auto_cache_threshold}
{
}

OvfFileReader::~OvfFileReader()
{
}

void OvfFileReader::OpenFile(const std::string path, Job& job)
{
    path_ = path;
    mapping_.emplace(path);

    if (mapping_->file_size() < 12)
    {
        throw std::runtime_error("File \"" + path + "\" is empty");
    }

    uint64_t job_lut_offset;
    {
        auto header_view = mapping_->CreateView(0, kMagicBytes.size() + 8);
        if (!std::equal(kMagicBytes.begin(), kMagicBytes.end(), header_view.data()))
        {
            throw std::runtime_error("File does not appear to be an ovf file");
        }

        // read job lut offset
        util::ReadFromLittleEndian(job_lut_offset, header_view.data() + kMagicBytes.size());
    }

    // read job lut
    job_lut_ = JobLUT{};
    {
        auto job_lut_view = mapping_->CreateView(job_lut_offset, 0); // offset up until EOF
        google::protobuf::io::ArrayInputStream zcs{job_lut_view.data(), (int)job_lut_view.size()};
        google::protobuf::util::ParseDelimitedFromZeroCopyStream(
            &*job_lut_,
            &zcs,
            nullptr
        );
    }

    // read work plane luts
    wp_luts_.resize(job_lut_->workplanepositions_size());
    for (int i = 0; i < job_lut_->workplanepositions_size(); i++)
    {
        size_t wp_offset_abs;
        auto wp_view = GetWorkPlaneFileView(i, &wp_offset_abs);
        
        int64_t wp_lut_offset_raw;
        util::ReadFromLittleEndian(wp_lut_offset_raw, wp_view.data());
        size_t wp_lut_offset_abs = (size_t)wp_lut_offset_raw;
        size_t wp_lut_offset_local = wp_lut_offset_abs - wp_offset_abs;

        google::protobuf::io::ArrayInputStream zcs{
            wp_view.data() + wp_lut_offset_local,
            (int)(wp_view.size() - wp_lut_offset_local)
        };
        google::protobuf::util::ParseDelimitedFromZeroCopyStream(
            &wp_luts_[i],
            &zcs,
            nullptr
        );
    }

    // read job shell
    job.Clear();
    {
        auto job_shell_view = mapping_->CreateView((uint64_t)job_lut_->jobshellposition(), 0);
        google::protobuf::io::ArrayInputStream zcs{job_shell_view.data(), (int)job_shell_view.size()};
        google::protobuf::util::ParseDelimitedFromZeroCopyStream(
            &job,
            &zcs,
            nullptr
        );
    }
}

void OvfFileReader::GetWorkPlane(const int i_work_plane, WorkPlane& wp)
{
    CheckIsFileOpened();

    size_t wp_offset_abs;
    auto work_plane_view = GetWorkPlaneFileView(i_work_plane, &wp_offset_abs);
    
    const auto wpl = wp_luts_[i_work_plane];
    
    // offset from start of work plane
    size_t shell_position = (size_t)wpl.workplaneshellposition() - wp_offset_abs;

    wp.Clear();
    google::protobuf::io::ArrayInputStream zcs{
        work_plane_view.data() + shell_position,
        (int)(work_plane_view.size() - shell_position)
    };
    google::protobuf::util::ParseDelimitedFromZeroCopyStream(
        &wp,
        &zcs,
        nullptr
    );

    // populate work plane with vector blocks
    for (int i = 0; i < wpl.vectorblockspositions_size(); i++)
    {
        auto vb_pos = (size_t)wpl.vectorblockspositions(i);
        auto vb_offset = vb_pos - wp_offset_abs;

        VectorBlock *vb = wp.add_vector_blocks();

        // this array stream is longer than the vector block alone.
        // as the protobuf streams are all buffered, and the messages
        // are delimited, that should be fine.
        google::protobuf::io::ArrayInputStream zcs{
            work_plane_view.data() + vb_offset,
            (int)(work_plane_view.size() - vb_offset)
        };
        google::protobuf::util::ParseDelimitedFromZeroCopyStream(
            vb,
            &zcs,
            nullptr
        );
    }
}

void OvfFileReader::GetWorkPlaneShell(const int i_work_plane, WorkPlane& wp)
{
    CheckIsFileOpened();
    
    uint64_t start_offset;
    auto work_plane_view = GetWorkPlaneFileView(i_work_plane, &start_offset);
    
    const auto wpl = wp_luts_[i_work_plane];
    
    // offset from start of work plane
    auto shell_position = (uint64_t)wpl.workplaneshellposition() - start_offset;

    wp.Clear();
    google::protobuf::io::ArrayInputStream zcs{
        work_plane_view.data() + shell_position,
        (int)(work_plane_view.size() - shell_position)
    };
    google::protobuf::util::ParseDelimitedFromZeroCopyStream(
        &wp,
        &zcs,
        nullptr
    );
}

void OvfFileReader::GetVectorBlock(const int i_work_plane, const int i_vector_block, VectorBlock& vb)
{
    CheckIsFileOpened();

    size_t start_offset;
    auto work_plane_view = GetWorkPlaneFileView(i_work_plane, &start_offset);
    
    const auto wpl = wp_luts_[i_work_plane];

    auto vb_pos = (size_t)wpl.vectorblockspositions(i_vector_block);
    auto vb_offset = vb_pos - start_offset;

    // this array stream is longer than the vector block alone.
    // as the protobuf streams are all buffered, and the messages
    // are delimited, that should be fine.
    google::protobuf::io::ArrayInputStream zcs{
        work_plane_view.data() + vb_offset,
        (int)(work_plane_view.size() - vb_offset)
    };
    google::protobuf::util::ParseDelimitedFromZeroCopyStream(
        &vb,
        &zcs,
        nullptr
    );
}

}