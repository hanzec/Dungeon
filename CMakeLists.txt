cmake_minimum_required(VERSION 3.10)

PROJECT(dungeon-coms327-f19)

#set c++ VERSION
SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage")
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#add src folder
add_subdirectory(src)