file(GLOB SOURCE_FILES
        "*.h"
        "*.c"
        )

add_executable(${PROJECT_NAME} ${SOURCE_FILES} file.cpp file.h characters/pc.c characters/pc.h characters/monster.c)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} utils/ display_io ./)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})