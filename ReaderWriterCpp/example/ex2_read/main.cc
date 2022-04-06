#include <iostream>
#include "ovf_reader_writer_export.h"
#include "open_vector_format.pb.h"
#include "ovf_file_reader.h"

namespace ovf = open_vector_format;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Please specify a path to the .ovf file to read" << std::endl;
        return -1;
    }

    ovf::reader_writer::OvfFileReader reader{};

    ovf::Job job{};

    std::string path{argv[1]};

    reader.OpenFile(path, job);

    std::cout << job.DebugString();
    std::cout << "-------------------------------------------" << std::endl;


    ovf::WorkPlane wp{};
    reader.GetWorkPlaneShell(1, wp);

    std::cout << wp.DebugString();
    std::cout << "-------------------------------------------" << std::endl;

    reader.GetWorkPlane(1, wp);

    std::cout << wp.ShortDebugString() << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    ovf::VectorBlock vb{};
    reader.GetVectorBlock(1, 1, vb);

    std::cout << vb.ShortDebugString() << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Finished" << std::endl;
    return 0;
}
