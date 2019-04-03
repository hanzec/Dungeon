//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_DUNGEONWINDOW_H
#define DUNGEON_COMS327_F19_DUNGEONWINDOW_H

#include "gameWindow.h"
#include "../../gameCommon.h"
#include "../../characters/pc.h"
#include "../../characters/monster.h"

class dungeonWindow : public gameWindow {
public:
    int updateNPC();
    void setFOWStatus(bool flag);
    void setTeleportStatus(bool flag);
    int updateMonster(Monster * monster);
    explicit dungeonWindow(dungeon_t * dungeon, Pc * npc);

private:
    Pc * npc;
    bool fow;
    bool teleport;
    void updateMap();
    dungeon_t * dungeonPtr;
    int updateMapByPixel(int x, int y);
    const chtype getTerFromChar(int x, int y);
};


#endif //DUNGEON_COMS327_F19_DUNGEONWINDOW_H
