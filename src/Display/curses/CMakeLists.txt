# add source code for display library
aux_source_directory(panel DISPLAY_SRCS_PANEL)
aux_source_directory(window DISPLAY_SRCS_WINDOW)

#add header files to display library
include_directories("${PROJECT_SOURCE_DIR}/include/Display")
file (GLOB_RECURSE DISPLAY_HEADERS "${CMAKE_SOURCE_DIR}/include/Display")

#set dependence ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#set output location
SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

#set library name
add_library (libdisplay-ncurses SHARED ${DISPLAY_SRCS_PANEL} ${DISPLAY_SRCS_WINDOW} ${DISPLAY_HEADERS} Display.cpp window/CursesWindow.h)

# link ncurses lib
target_link_libraries(libdisplay-ncurses ${CURSES_LIBRARIES})

#set library version and api version
SET_TARGET_PROPERTIES(libdisplay-ncurses PROPERTIES VERSION 0.9 SOVERSION 1)