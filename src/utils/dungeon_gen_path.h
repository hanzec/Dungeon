//
// Created by 陈瀚泽 on 2019-02-14.
//

#ifndef DUNGEON_COMS327_F19_DUNGEON_GEN_PATH_H
#define DUNGEON_COMS327_F19_DUNGEON_GEN_PATH_H


#include "game.h"
#include "monster.h"

void dijkstra_tunnelling(dungeon_t *d, pair_t from, monster_t * monster);
void dijkstra_no_tunnelling(dungeon_t *d, pair_t from, monster_t * monster);


#endif //DUNGEON_COMS327_F19_DUNGEON_GEN_PATH_H
