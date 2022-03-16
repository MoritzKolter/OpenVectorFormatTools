#pragma once

#include <array>

namespace open_vector_format::reader_writer {
    const std::array<uint8_t, 4> kMagicBytes{ { 0x4c, 0x56, 0x46, 0x21 } };
}