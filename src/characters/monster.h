//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H

#include <stdint.h>
#include "../game.h"
#include "pc.h"

#define IS_MONSTER_SEEN_PC (monster->lastPcLocation [dim_y] == 0) && (monster->lastPcLocation[dim_x] == 0)

typedef struct monster{
    pc_t * pc;
    uint8_t speed;
    uint8_t range;
    pair_t location;
    dungeon_t * dungeon;
    pair_t lastPcLocation;
    uint8_t characteristics;
} monster_t;
#endif //DUNGEON_COMS327_F19_MONSTER_H
