//
// Created by 陈瀚泽 on 2019-03-14.
//

#include "../../../../include/GameCommon.h"
#include "../displayCommon.h"
#include "window/statusBar.h"

statusBar::statusBar() {
    this->windowPtr = newwin(1,DUNGEON_X,0,0);
    wbkgd(this->windowPtr,COLOR_PAIR(PAIR_STATUS_BAR));

}
