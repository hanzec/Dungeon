//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H

#include "gameCommon.h"
#include "charactersCommon.h"

int moveMonster(monster_t * monster);
void newMonster(dungeon_t *dungeon, pc_t * pc, monster_t * monster);
void dijkstra_tunnelling(dungeon_t *d, pair_t from, monster_t * monster);
void dijkstra_no_tunnelling(dungeon_t *d, pair_t from, monster_t * monster);

#endif //DUNGEON_COMS327_F19_MONSTER_H
