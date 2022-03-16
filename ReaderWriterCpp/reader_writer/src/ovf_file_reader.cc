#include <optional>
#include <mutex>
#include <fstream>
#include <algorithm>

#include "google/protobuf/util/delimited_message_util.h"

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

    // memory map the file
    mapping_ = MemoryMapping(path);

    if (mapping_->file_size() < 12)
    {
        throw std::runtime_error("File \"" + path + "\" is empty");
    }

    auto header_view = mapping_->CreateView(0, kMagicBytes.size() + 8);
    
    if (!std::equal(kMagicBytes.begin(), kMagicBytes.end(), header_view.data()))
    {
        throw std::runtime_error("File does not appear to be an ovf file");
    }

    // read job lut offset
    
/*
    auto ifs = std::ifstream{path};

    uint8_t buffer[kMagicBytes.size()];
    ifs.read((char*)buffer, kMagicBytes.size());
    if (!std::equal(kMagicBytes.begin(), kMagicBytes.end(), buffer))
        throw std::runtime_error("File does not appear to be an ovf file");

    // read job lut offset
    uint64_t job_lut_offset;
    util::ReadFromLittleEndian(job_lut_offset, ifs);

    ifs.close();
*/
    // read job lut
    // not that usage of IstreamInputStream for this is discouraged, but probably okay
    // as we continue using the ifstream afterwards and only read one small object
    job_lut_ = JobLUT{};
    /* util::ManagedFileInputStream pb_ifs{path};
    pb_ifs.stream()->Skip(job_lut_offset);
    google::protobuf::util::ParseDelimitedFromZeroCopyStream(
        &*job_lut_,
        pb_ifs.stream(),
        nullptr
    ); */
}



}