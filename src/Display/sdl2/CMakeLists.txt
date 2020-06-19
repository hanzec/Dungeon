# add source code for display library
aux_source_directory(panel DISPLAY_SRCS_PANEL)
aux_source_directory(window DISPLAY_SRCS_WINDOW)

#add header files to display library
include_directories("${PROJECT_SOURCE_DIR}/include/Display")
file (GLOB_RECURSE DISPLAY_HEADERS "${CMAKE_SOURCE_DIR}/include/Display")

#set output location
SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

#set library name
add_library (libdisplay-sdl2 SHARED ${DISPLAY_SRCS_PANEL} ${DISPLAY_SRCS_WINDOW} ${DISPLAY_HEADERS} Display.cpp)

#set library version and api version
SET_TARGET_PROPERTIES(libdisplay-sdl2 PROPERTIES VERSION 0.9 SOVERSION 1)