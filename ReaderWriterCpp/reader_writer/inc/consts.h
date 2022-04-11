#pragma once

#include <array>

namespace open_vector_format::reader_writer {

/** Magic bytes at the beginning of open vector format files. */
const std::array<uint8_t, 4> kMagicBytes{ { 0x4c, 0x56, 0x46, 0x21 } };

/** Default offset to write while real offset is unknown. */
const int64_t kDefaultLutOffset = 0;

}