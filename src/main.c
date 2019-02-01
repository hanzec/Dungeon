//
// Created by chen_ on 2019/1/31.
//
#import <stdio.h>
#include<ncurses.h>
#include <curses.h>
#include "main.h"

const int base_width = 80;
const int base_height = 21;

int main(int argc, char *argv[]) {
    WINDOW *my_win;
    int startx, starty;
    int ch;
    initscr(); /* 初始化并进入 curses模式 */
    cbreak(); /* 行缓冲禁止，传递所有控制信息 */
    starty = (LINES - base_height) / 2; /*计算窗口中心位置的行数 */
    startx = (COLS - base_width) / 2; /*计算窗口中心位置的列数 */
    printw("PressF1toexit");
    refresh();
    my_win = create_newwin(base_height, base_width, starty, startx);
    while ((ch = getch()) != KEY_F(1)) {

    }
    endwin();/*结束 curses模式 */
    return 0;
}

W

//todo add welcome menu here;


