#include <iostream>
#include "ovf_reader_writer_export.h"
#include "open_vector_format.pb.h"
#include "ovf_file_writer.h"

namespace ovf = open_vector_format;

int main(int argc, char const *argv[])
{
    ovf::Job j{};

    ovf::reader_writer::OvfFileWriter writer{};

    //writer.WriteFullJob(j, "test.ovf");

    writer.StartWritePartial(j, "test.ovf");

    ovf::WorkPlane wp{};
    writer.AppendWorkPlane(wp);
    
    ovf::VectorBlock vb{};
    writer.AppendVectorBlock(vb);

    writer.FinishWrite();

    std::cout << "Finished" << std::endl;
    return 0;
}
