#pragma once

#include "google/protobuf/message.h"
#include <fcntl.h>
#include <iostream>
#include <functional>

namespace open_vector_format::util {

void CopyField(const google::protobuf::Message& source,
               google::protobuf::Message& target,
               const google::protobuf::FieldDescriptor* const& field);


void CopyRepeatedField(const google::protobuf::Message& source,
                       google::protobuf::Message& target,
                       const google::protobuf::FieldDescriptor* const& field);


template <class UnaryPredicate>
void MergeExcluding(const google::protobuf::Message& source,
                    google::protobuf::Message& target,
                    UnaryPredicate pred)
{
    const auto source_desc = source.GetDescriptor();
    const auto target_desc = target.GetDescriptor();

    if (source_desc->full_name() != target_desc->full_name())
        throw std::runtime_error("Can't merge message type '" + source_desc->full_name() +
                                 "' into message type '" + target_desc->full_name() + "'");
    
    const auto source_refl = source.GetReflection();
    const auto target_refl = target.GetReflection();

    std::vector<const google::protobuf::FieldDescriptor*> source_fields;
    source_refl->ListFields(source, &source_fields);

    for (auto const field : source_fields)
    {
        if (pred(*field))
            continue;

        auto field_number = field->number();

        if (!field->is_repeated() && !field->is_map())
        {
            CopyField(source, target, field);
        }
        else
        {
            CopyRepeatedField(source, target, field);
        }
    }
}

inline bool IsSystemBigEndian()
{
    // if first byte is 0x00, least significant byte is first, i.e. BE
    uint16_t num{0x00FF};
    return (((uint8_t*)&num)[0] == 0x00);
}

template <typename T>
inline void WriteAsLittleEndian(T integer, std::ostream& os)
{
    std::cout << sizeof(integer) << std::endl;

    if (IsSystemBigEndian())
    {
        uint8_t buf[sizeof(integer)];
        for (int i = 0; i < sizeof(integer); i++)
            buf[i] = ((uint8_t*)(&integer))[sizeof(integer) - i - 1];
        
        os.write((char*)buf, sizeof(integer));
    }
    else
    {
        os.write((char*)(&integer), sizeof(integer));
    }
}

template <typename T>
inline void ReadFromLittleEndian(T& integer, std::istream& is)
{
    if (IsSystemBigEndian())
    {
        uint8_t buf[sizeof(integer)];
        is.read((char*)buf, sizeof(integer));

        for (int i = 0; i < sizeof(integer); i++)
            ((uint8_t*)(&integer))[i] = buf[sizeof(integer) - i - 1];
    }
    else
    {
        is.read((char*)(&integer), sizeof(integer));
    }
}

template <typename T>
inline void ReadFromLittleEndian(T& integer, uint8_t *in)
{
    if (IsSystemBigEndian())
    {
        for (int i = 0; i < sizeof(integer); i++)
            ((uint8_t*)(&integer))[i] = in[sizeof(integer) - i - 1];
    }
    else
    {
        memcpy((uint8_t*)(&integer), in, sizeof(integer))
    }
}

}