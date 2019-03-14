
# add source code for display library
aux_source_directory(panel DIR_DISPLAY_SRCS_PANEL)
aux_source_directory(window DIR_DISPLAY_SRCS_WINDOW)

#set dependence ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#set output location
SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

#set library name
add_library (DisplayLib SHARED ${DIR_DISPLAY_SRCS_PANEL} ${DIR_DISPLAY_SRCS_WINDOW} display.c display_utils.c)

# link ncurses lib
target_link_libraries(DisplayLib ${CURSES_LIBRARIES})

#set library version and api version
SET_TARGET_PROPERTIES(DisplayLib PROPERTIES VERSION 0.9 SOVERSION 1)
