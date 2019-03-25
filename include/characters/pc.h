//
// Created by 陈瀚泽 on 2019/2/26.
//

#ifndef DUNGEON_COMS327_F19_PC_H
#define DUNGEON_COMS327_F19_PC_H

#include "characters.h"
#include "../gameCommon.h"

class pc : public character{
private:
public:
    pc(dungeon_t * dungeon);
    int movePC(direction_t direction);
};

#endif //DUNGEON_COMS327_F19_PC_H
