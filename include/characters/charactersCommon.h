//
// Created by 陈瀚泽 on 2019-03-11.
//
#ifndef DUNGEON_COMS327_F19_CHARACTERSCOMMON_H
#define DUNGEON_COMS327_F19_CHARACTERSCOMMON_H

#include "gameCommon.h"
#include "heap.h"

typedef struct pc{
    pair_t location;
    pair_t prevLocation;
    dungeon_t * dungeon;
}pc_t;

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
    pc_t * pc;
    uint8_t speed;
    uint8_t range;
    pair_t location;
    pair_t prev_location;
    dungeon_t * dungeon;
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
