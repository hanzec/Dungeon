//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H

#include "pc.h"
#include <time.h>
#include <math.h>
#include <strings.h>
#include "../game.h"
#include "../macros.h"
#include "../utils/data_stucture/heap.h"
#define monsterNext(monster) ((corridor_node_t *) monster->path[monster->location[dim_y]][monster->location[dim_x]].prev_node)

typedef struct corridor_node {
    pair_t pos;
    int32_t cost;
    heap_node_t *hn;
    void * prev_node;

} corridor_node_t;

typedef struct monster{
    pc_t * pc;
    uint8_t speed;
    uint8_t range;
    pair_t location;
    dungeon_t * dungeon;
    pair_t lastPcLocation ;
    uint8_t characteristics;
    corridor_node_t path[DUNGEON_Y][DUNGEON_X];
} monster_t;

int moveMonster(monster_t * monster);
void newMonster(dungeon_t *dungeon, pc_t * pc, monster_t * monster);
void dijkstra_tunnelling(dungeon_t *d, pair_t from, monster_t * monster);
void dijkstra_no_tunnelling(dungeon_t *d, pair_t from, monster_t * monster);

#endif //DUNGEON_COMS327_F19_MONSTER_H
