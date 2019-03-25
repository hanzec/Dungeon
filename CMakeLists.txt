cmake_minimum_required(VERSION 3.10)

PROJECT(dungeon-coms327-f19)
ADD_SUBDIRECTORY(src)

include_directories(${CMAKE_BINARY_DIR}/include)
include_directories(${PROJECT_BINARY_DIR}/include)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


