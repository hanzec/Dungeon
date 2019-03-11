//
// Created by chen_ on 2019/1/31.
//

#include "../../include/utils/display_utils.h"

void destroy_win(WINDOW *local_win) {
    box(local_win, ' ', ' ');
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    delwin(local_win);
}