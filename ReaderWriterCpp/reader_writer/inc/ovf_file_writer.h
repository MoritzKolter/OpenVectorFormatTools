#pragma once

#include <fstream>
#include <optional>

#include "open_vector_format.pb.h"
#include "ovf_lut.pb.h"
#include "ovf_reader_writer_export.h"

namespace open_vector_format::reader_writer {

class OVF_READER_WRITER_EXPORT OvfFileWriter
{
public:
    OvfFileWriter();
    OvfFileWriter(const OvfFileWriter&) = delete;
    OvfFileWriter& operator=(const OvfFileWriter&) = delete;

    void StartWritePartial(const Job& job_shell, const std::string path);
    void AppendWorkPlane(const WorkPlane& wp);
    void AppendVectorBlock(const VectorBlock& vb);
    void FinishWrite();

    void WriteFullJob(const Job& job, const std::string path);

private:
    enum class FileOperationState
    {
        kNone,
        kPartialWrite,
        kCompleteWrite,
        kUndefined
    };

    FileOperationState operation_;
    
    std::optional<std::ofstream> ofs_;
    
    std::optional<WorkPlane> current_wp_;
    std::optional<Job> job_shell_;
    std::optional<JobLUT> job_lut_;
    std::optional<uint64_t> job_lut_offset_offset_;


    void WriteHeader(const Job& job);
    void WriteFullWorkPlane(const WorkPlane& wp);
    void WriteFooter();

    inline void CheckFsHealth()
    {
        if (!ofs_.has_value())
            throw std::runtime_error("Output file stream was not set");

        if (!ofs_->is_open())
            throw std::runtime_error("Output file stream closed unexpectedly");

        if (!ofs_->good())
            throw std::runtime_error("Output file stream encountered an error");
    }

    inline void CheckIsWriting()
    {
        if (operation_ != FileOperationState::kPartialWrite && operation_ != FileOperationState::kCompleteWrite)
            throw std::runtime_error("Trying to write while no write operation is active");
    }
};

}