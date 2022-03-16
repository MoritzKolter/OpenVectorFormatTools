add_executable(test_ex main.cc)

target_include_directories(test_ex PUBLIC
                           ${PROJECT_SOURCE_DIR}/reader_writer/inc)

target_link_libraries(test_ex PRIVATE ${LIBRARY_NAME})