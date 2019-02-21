file(GLOB SOURCE_FILES
        "*.h"
        "*.c"
        )

add_executable(${PROJECT_NAME} ${SOURCE_FILES} utils/display_utils.c utils/display_utils.h io_display/window/windos_dungeon.c io_display/window/windos_dungeon.h game.c game.h io_file.c io_file.h utils/dungeon_map_generate.c utils/dungeon_utils.c utils/dungeon_utils.h utils/dungeon_gen_path.c utils/dungeon_gen_path.h)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} utils/ display_io ./)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})