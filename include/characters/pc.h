//
// Created by 陈瀚泽 on 2019/2/26.
//

#ifndef DUNGEON_COMS327_F19_PC_H
#define DUNGEON_COMS327_F19_PC_H

#include "characters.h"

class Pc : public Character{
private:
public:
    Pc(dungeon_t * dungeon = NULL);
    int movePC(direction_t direction);
    int setPcLocation(pair_t location);
};

#endif //DUNGEON_COMS327_F19_PC_H
