//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_DISPLAY_UTILS_H
#define DUNGEON_V1_01_DISPLAY_UTILS_H
#include <curses.h>

void destroy_win(WINDOW *local_win);
WINDOW *create_basic_windo_center(int height, int width);

#endif //DUNGEON_V1_01_DISPLAY_UTILS_H
