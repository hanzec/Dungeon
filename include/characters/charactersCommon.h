//
// Created by 陈瀚泽 on 2019-03-11.
//
#ifndef DUNGEON_COMS327_F19_CHARACTERSCOMMON_H
#define DUNGEON_COMS327_F19_CHARACTERSCOMMON_H

#include "../utils/data_stucture/heap.h"

typedef struct npc{
    pair_t location;
    pair_t prevLocation;
    dungeon_t * dungeon;
}npc_t;

typedef enum direction{
    Upper,      UpperLeft,      UpperRight,
    Left,       Right,          Down,       
    DownLeft,   DownRight,
}direction_t;

typedef struct corridor_node {
    int cost;
    pair_t pos;
    heap_node_t *hn;
    void * prev_node;
} corridor_node_t;

typedef struct monster{
    npc_t * pc;
    uint8_t speed;
    uint8_t range;
    pair_t location;
    pair_t prev_location;
    pair_t lastPcLocation ;
    uint8_t characteristics;
    corridor_node_t path[DUNGEON_Y][DUNGEON_X];
} monster_t;

typedef struct monsterNode{
    uint32_t time;
    monster_t * monster;
    struct monsterNode * prevNode;
    struct monsterNode * nextNode;
} monsterNode_t ;

#endif //DUNGEON_COMS327_F19_CHARACTERSCOMMON_H
