//
// Created by 陈瀚泽 on 2019/3/10.
//

#include "../../../include/display/window/window_statusBar.h"

WINDOW * initStatusBar(){
    WINDOW * statusBar = newwin(1,DUNGEON_X,0,0);


    init_pair(1,COLOR_WHITE, COLOR_BLACK);
    wbkgd(statusBar,COLOR_PAIR(1));
}
