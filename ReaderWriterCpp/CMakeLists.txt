cmake_minimum_required(VERSION 3.16)

set(PROJECT "ReaderWriterCpp")

project("${PROJECT}_Project"
        VERSION 0.0.1
        LANGUAGES CXX)


set(OVF_READER_WRITER_LIBRARY_NAME OvfReaderWriter)
set(OVF_READER_WRITER_LIBRARY_STATIC  ${OVF_READER_WRITER_LIBRARY_NAME}_Static)
set(OVF_READER_WRITER_LIBRARY_DYNAMIC ${OVF_READER_WRITER_LIBRARY_NAME}_Dll)


# Global variables
set(CMAKE_CXX_STANDARD                  17)
set(CMAKE_CXX_STANDARD_REQUIRED         ON)
set(CMAKE_CXX_EXTENSIONS                OFF)

# Options
option(ENABLE_WARNINGS  "Enable to add warnings to a target."   ON)
option(ENABLE_TESTING   "Enable unit testing."                  ON)
option(ENABLE_LTO       "Enable link-time optimization (LTO)." OFF)
option(ENABLE_CCACHE    "Enable ccache."                       OFF)

# Cmake modules
include(GenerateExportHeader)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(config_safe_guards)
#include(warnings)
#include(documentation)
if (ENABLE_TESTING)
  #include(test)
endif()
if (ENABLE_LTO)
#  include(lto)
#  find_lto(CXX)
endif()
if (ENABLE_CCACHE)
#  include(ccache)
endif()


# Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake OPTIONAL
        RESULT_VARIABLE CONAN_FOUND)
if (CONAN_FOUND)
  conan_basic_setup()
else()
  message(WARNING "Conan build information was not found. Libraries resolution will be against system include paths.")
endif()

# First-party library
add_subdirectory(reader_writer)

# Example applications
#add_subdirectory(example)

# Unit test
if (ENABLE_TESTING OR ENABLE_COVERAGE)
  #enable_testing()
  #add_subdirectory(tests)
endif()

# Installation
install(TARGETS ${OVF_READER_WRITER_LIBRARY_STATIC}
        ARCHIVE DESTINATION ${CMAKE_BINARY_DIR}/lib/static
        LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/lib/static
        RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/lib/static
        PUBLIC_HEADER DESTINATION ${CMAKE_BINARY_DIR}/lib/static)

install(TARGETS ${OVF_READER_WRITER_LIBRARY_DYNAMIC}
        ARCHIVE DESTINATION ${CMAKE_BINARY_DIR}/lib/dll
        LIBRARY DESTINATION ${CMAKE_BINARY_DIR}/lib/dll
        RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/lib/dll
        PUBLIC_HEADER DESTINATION ${CMAKE_BINARY_DIR}/lib/dll)