//
// Created by 陈瀚泽 on 2019-03-14.
//

#include "../../../include/gameCommon.h"
#include "../../../include/display/displayCommon.h"
#include "../../../include/display/window/statusBarWindow.h"

statusBarWindow::statusBarWindow() {
    this->windowPtr = newwin(1,DUNGEON_X,0,0);
    wbkgd(this->windowPtr,COLOR_PAIR(PAIR_STATUS_BAR));

}
