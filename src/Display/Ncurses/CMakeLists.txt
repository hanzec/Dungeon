# add source code for display library
aux_source_directory(panel DISPLAY_SRCS_PANEL)
aux_source_directory(window DISPLAY_SRCS_WINDOW)

#add header files to display library
include_directories("${PROJECT_SOURCE_DIR}/include")


#---------------------- Ncurses ---------------------------
set(CURSES_NEED_WIDE true) # required unicode support
list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/ncurses/lib") #include homebew verison of curses

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
#-------------------- END Ncurses -------------------------

#set library name
add_library (libdisplay-ncurses SHARED ${DISPLAY_SRCS_PANEL} ${DISPLAY_SRCS_WINDOW} Display.cpp)

#link deps
target_link_libraries(libdisplay-ncurses ${CURSES_LIBRARIES})

#set library version and api version
SET_TARGET_PROPERTIES(libdisplay-ncurses PROPERTIES VERSION 0.9 SOVERSION 1)