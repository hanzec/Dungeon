//
// Created by 陈瀚泽 on 2019-03-14.
//

#include "../../../include/display/window/diedScreen.h"

diedScreen::diedScreen() {
    mvaddstr(0,0,tombstone);
    refresh();
    getch();
    return;
}
