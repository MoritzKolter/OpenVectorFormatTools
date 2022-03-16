#pragma once

#ifndef WIN32
#  error win32 headers included for non-win32 build 
#endif

#include <string>
#include <stdexcept>
#include <winbase.h>
#include <fileapi.h>
#include <sysinfoapi.h>

namespace open_vector_format::reader_writer {

class MemoryMapping
{
public:
    class FileView
    {
    public:
        FileView(uint8_t *base_addr, uint8_t *start_addr)
            : base_addr_{base_addr}, start_addr_{start_addr}
        {}
        FileView(const FileView&) = delete;
        FileView& operator=(const FileView&) = delete;
        ~FileView()
        {
            UnmapViewOfFile(base_addr_);
        }

        uint8_t *data()
        {
            return start_addr_;
        }
    private:
        uint8_t *base_addr_;
        uint8_t *start_addr_;
    };


    MemoryMapping(const std::string path)
    {
        GetSystemInfo(&system_info_);
        
        file_ = CreateFileA(
            path.c_str(),
            GENERIC_READ,
            FILE_SHARE_READ,
            nullptr,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
            nullptr
        );

        if (file_ == INVALID_HANDLE_VALUE)
        {
            throw std::runtime_error("Opening file \"" + path + "\" failed");
        }

        DWORD low, high;
        low = GetFileSize(file_, &high);
        file_size_ = (((uint64_t)high) << 32) | ((uint64_t)low);

        file_mapping_ = CreateFileMappingA(
            file_,
            nullptr,
            PAGE_READONLY,
            0,
            0,
            nullptr
        );

        if (file_mapping_ == INVALID_HANDLE_VALUE)
        {
            throw std::runtime_error("Creating file mapping for file \"" + path + "\" failed");
            CloseHandle(file_);
        }
    }

    MemoryMapping(const MemoryMapping&) = delete;
    MemoryMapping& operator=(const MemoryMapping&) = delete;
    ~MemoryMapping()
    {
        CloseHandle(file_mapping_);
        CloseHandle(file_);
    }

    FileView CreateView(const uint64_t offset, const uint64_t min_size)
    {
        DWORD granularity = system_info_.dwAllocationGranularity;
        uint64_t granularized_offset = (offset / granularity) * granularity;

        DWORD offset_low = static_cast<DWORD>(granularized_offset & 0xFFFFFFFFul);
        DWORD offset_high = static_cast<DWORD>((granularized_offset >> 32) & 0xFFFFFFFFul);

        uint64_t corrected_min_size = ((offset - granularized_offset) + min_size);
        uint64_t granularized_min_size = (((corrected_min_size + 1) / granularity) * granularity);
        if (granularized_offset + granularized_min_size >= file_size_)
        {
            granularized_min_size = 0; // up to EOF
        }

        auto view = static_cast<uint8_t*>(MapViewOfFile(
            file_mapping_,
            FILE_MAP_READ,
            offset_high,
            offset_low,
            min_size == 0 ? 0 : (SIZE_T)granularized_min_size
        ));
        
        return FileView{view, view + (offset - granularized_offset)};
    }

    uint64_t file_size() const
    {
        return file_size_;
    }

private:
    HANDLE file_;
    HANDLE file_mapping_;
    uint64_t file_size_;
    SYSTEM_INFO system_info_;
};


}