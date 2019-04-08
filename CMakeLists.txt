cmake_minimum_required(VERSION 3.10)

PROJECT(dungeon-coms327-f19)

if(APPLE)
    SET(CMAKE_C_COMPILER "/Library/Developer/CommandLineTools/usr/bin/cc")
    SET(CMAKE_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/c++")
endif()

ADD_SUBDIRECTORY(src)
include_directories("${CMAKE_SOURCE_DIR}/include")
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

