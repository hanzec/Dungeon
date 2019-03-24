//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_DUNGEONWINDOW_H
#define DUNGEON_COMS327_F19_DUNGEONWINDOW_H

#include "gameWindow.h"
#include "../../gameCommon.h"
#include "../../characters/npc.h"
#include "../../characters/Monster.h"

class dungeonWindow : public gameWindow {
public:
    int updateMap();
    int updateNPC(npc * npc);
    int updateMonster(monster * monster);
    explicit dungeonWindow(dungeon_t * dungeon);

private:
    dungeon_t * dungeonPtr;
    const chtype getTerFromChar(int x, int y);
};


#endif //DUNGEON_COMS327_F19_DUNGEONWINDOW_H
