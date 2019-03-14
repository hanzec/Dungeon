//
// Created by 陈瀚泽 on 2019/3/10.
//

#include "displayCommon.h"
#include "window_characterInfo.h"
#include "gameCommon.h"
#include "charactersCommon.h"

WINDOW * initCharacterInfo(pc_t * pc){
    WINDOW * statusBar = newwin(3,DUNGEON_X,22,0);

    wbkgd(statusBar,COLOR_PAIR(PAIR_CHARACTER_STATUS));

    wrefresh(statusBar);
}
