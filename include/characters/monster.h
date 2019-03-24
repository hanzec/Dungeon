//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H

#include "npc.h"
#include "monster.h"

#include "../gameCommon.h"

typedef struct corridor_node {
    int cost;
    pair_t pos;
    heap_node_t *hn;
    void * prev_node;
} corridor_node_t;

class monster
{
private:
    npc::npc * npc;
    uint8_t range;
    dungeon_t * dungeon;
    pair_t lastPcLocation ;
    uint8_t characteristics;
public:
    uint8_t speed;
    pair_t prevLocation;
    pair_t currentLocation;
    corridor_node_t path[DUNGEON_Y][DUNGEON_X];
    
    int moveMonster();
    bool meetWithNPC();
    void dijkstra_tunnelling();
    void dijkstra_no_tunnelling();
    monster(dungeon_t *dungeon, npc::npc * pc);
};

#endif //DUNGEON_COMS327_F19_MONSTER_H
