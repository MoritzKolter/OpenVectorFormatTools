add_executable(test_ex main.cc)

target_include_directories(test_ex
    PUBLIC
        ${PROJECT_SOURCE_DIR}/reader_writer/inc
)

target_link_libraries(test_ex
    PRIVATE
        ${OVF_READER_WRITER_LIBRARY_STATIC}
)

# add defines for building static library
target_compile_definitions(test_ex
    PRIVATE
        OVF_READER_WRITER_STATIC_DEFINE
)

# add defines for architecture
target_compile_definitions(test_ex
    PRIVATE
        ${TARGET_ARCHITECTURE}
)