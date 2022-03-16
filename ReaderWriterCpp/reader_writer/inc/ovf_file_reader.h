#pragma once

#include <optional>
#include <fstream>
#include <optional>

#ifdef WIN32
#  include "memory_mapping_win32.h"
#else
#  error POSIX
#endif

#include "open_vector_format.pb.h"
#include "ovf_lut.pb.h"
#include "ovf_reader_writer_export.h"


namespace open_vector_format::reader_writer {


class OvfFileReader
{
public:
    // 64MiB
    OvfFileReader(uint64_t auto_cache_threshold = 67108864);
    OvfFileReader(const OvfFileReader&) = delete;
    OvfFileReader& operator=(const OvfFileReader&) = delete;
    ~OvfFileReader();

    void OpenFile(const std::string path, Job& job);

    void GetWorkPlane(const int i_work_plane, WorkPlane& wp);
    void GetWorkPlane(const int i_work_plane, WorkPlane *wp);
    void GetWorkPlaneShell(const int i_work_plane, WorkPlane& wp);
    void GetWorkPlaneShell(const int i_work_plane, WorkPlane *wp);
    void GetVectorBlock(const int i_work_plane, const int i_vector_block, VectorBlock& vb);
    void GetVectorBlock(const int i_work_plane, const int i_vector_block, VectorBlock *vb);

    void CacheFullJob();
    void CacheWorkPlaneShells();

private:
    std::optional<std::string> path_;
    std::optional<MemoryMapping> mapping_;

    std::optional<JobLUT> job_lut_;
    std::optional<std::vector<uint64_t>> work_plane_lut_offsets_;

    uint64_t auto_cache_threshold_;
};

}