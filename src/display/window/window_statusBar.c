//
// Created by 陈瀚泽 on 2019/3/10.
//

#include <ncurses.h>
#include "gameCommon.h"
#include "displayCommon.h"
#include "window_statusBar.h"

WINDOW * initStatusBar(){
    WINDOW * statusBar = newwin(1,DUNGEON_X,0,0);

    wbkgd(statusBar,COLOR_PAIR(PAIR_STATUS_BAR));

    return statusBar;
}
