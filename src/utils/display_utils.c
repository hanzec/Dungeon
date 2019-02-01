//
// Created by chen_ on 2019/1/31.
//

#include <curses.h>
#include "display_utils.h"

WINDOW *create_basic_windo_center(int height, int width) {
    WINDOW *tmp_window;
    int center_x = (COLS - width) / 2;
    int center_y = (LINES - height) / 2;
    tmp_window = newwin(height, width, center_y, center_x);
    return tmp_window;
}

void destroy_win(WINDOW *local_win) {
    box(local_win, ' ', ' ');
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    delwin(local_win);

}