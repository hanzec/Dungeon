//
// Created by 陈瀚泽 on 2019/2/26.
//

#ifndef DUNGEON_COMS327_F19_PC_H
#define DUNGEON_COMS327_F19_PC_H

#include "../gameCommon.h"

class npc{
private:
    dungeon_t * dungeon;
public:
    pair_t prevLocation;
    pair_t currentLocation;
    npc(dungeon_t * dungeon);
    int movePC(direction_t direction);
};

#endif //DUNGEON_COMS327_F19_PC_H
