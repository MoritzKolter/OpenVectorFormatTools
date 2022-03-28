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
    void GetWorkPlaneShell(const int i_work_plane, WorkPlane& wp);
    void GetVectorBlock(const int i_work_plane, const int i_vector_block, VectorBlock& vb);

    void CacheFullJob();
    void CacheWorkPlaneShells();

private:
    std::optional<std::string> path_;
    std::optional<MemoryMapping> mapping_;

    std::optional<JobLUT> job_lut_;
    std::optional<std::vector<uint64_t>> work_plane_lut_offsets_;

    uint64_t auto_cache_threshold_;
    std::vector<WorkPlaneLut> wp_luts_;


    void GetWorkPlaneLut(uint8_t *buffer, size_t size, WorkPlaneLUT& wpl);

    inline void CheckIsFileOpened()
    {
        if (!path_.has_value() || !mapping_.has_value() || !job_lut_.has_value())
            throw std::runtime_error("Can't read data without opening a file first");
    }

    inline MemoryMapping::FileView GetWorkPlaneFileView(const int i_work_plane, uint64_t *start_offset = nullptr, uint64_t *end_offset = nullptr)
    {
        auto count_work_planes = job_lut_->workplanepositions_size();
    
        if (i_work_plane < 0 || i_work_plane > count_work_planes - 1)
            throw std::runtime_error("Invalid work plane index");
        
        uint64_t lower_offset = job_lut_->workplanepositions(i_work_plane);
        uint64_t upper_offset = i_work_plane < count_work_planes - 1
            ? job_lut_->workplanepositions(i_work_plane + 1)
            : job_lut_->jobshellposition();

        if (start_offset != nullptr) *start_offset = lower_offset;
        if (end_offset != nullptr) *end_offset = upper_offset;

        return mapping_->CreateView(lower_offset, (upper_offset - lower_offset));
    }
};

}