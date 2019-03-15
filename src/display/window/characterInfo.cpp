//
// Created by 陈瀚泽 on 2019-03-14.
//

#include "../../../include/display/displayCommon.h"
#include "../../../include/display/window/characterInfo.h"

characterInfo::characterInfo() {
    this->windowPtr = newwin(3,DUNGEON_X,22,0);
    wbkgd(this->windowPtr,COLOR_PAIR(PAIR_CHARACTER_STATUS));
}
