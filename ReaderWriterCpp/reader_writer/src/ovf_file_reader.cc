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

    wp_luts_.resize(job_lut_->workplanepositions_size());

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
    //GetWorkPlane(i_work_plane, &wp);
}

void OvfFileReader::GetWorkPlaneShell(const int i_work_plane, WorkPlane& wp)
{
    CheckIsFileOpened();
    
    uint64_t start_offset;
    auto work_plane_view = GetWorkPlaneFileView(i_work_plane, &start_offset);
    
    GetWorkPlaneLut(work_plane_view.data(), work_plane_view.size(), wpl);
    
    // offset from start of work plane
    auto shell_position = wpl.workplaneshellposition - start_offset;

    wp.Clear();
    google::protobuf::io::ArrayInputStream zcs{
        work_plane_view.data() + shell_position,
        (int)work_plane_view.size() - shell_position
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

    // TODO
}



void OvfFileReader::GetWorkPlaneLut(const int i_work_plane, WorkPlaneLUT& wpl)
{
    google::protobuf::io::ArrayInputStream zcs{buffer, (int)size};
    google::protobuf::util::ParseDelimitedFromZeroCopyStream(
        &wpl,
        &zcs,
        nullptr
    );
}

}