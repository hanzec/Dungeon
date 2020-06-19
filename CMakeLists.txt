cmake_minimum_required(VERSION 3.10)

PROJECT(dungeon-coms327-f19)

#set c++ VERSION
SET(CMAKE_CXX_STANDARD 17)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#add src folder
add_subdirectory(src)

#ser project wide include
include_directories("${CMAKE_SOURCE_DIR}/include/")

# add RapidJson Dependency
include_directories("${CMAKE_SOURCE_DIR}/thirdparty/rapidjson/include")
