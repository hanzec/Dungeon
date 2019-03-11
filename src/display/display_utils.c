//
// Created by chen_ on 2019/1/31.
//

#include "../../include/display/display_utils.h"

int destroy_win(WINDOW *local_win) {
    box(local_win, ' ', ' ');
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    return delwin(local_win);
}