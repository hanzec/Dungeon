//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H


#include "Pc.h"
#include "GameContent.h"
#include "../utils/data_stucture/heap.h"

typedef struct corridor_node {
    int cost;
    pair_t pos;
    heap_node_t *hn;
    void * prev_node;
} corridor_node_t;

class Monster : public GameContent{
private:
    Pc * user;
    dungeon_t * dungeon;
    uint8_t characteristics;
public:
    pair_t lastPcLocation ;
    corridor_node_t path[DUNGEON_Y][DUNGEON_X];

    int moveMonster();
    bool meetWithNPC();
    void dijkstra_tunnelling();
    void dijkstra_no_tunnelling();
    Monster(dungeon_t *dungeon, Pc * pc);
};

#endif //DUNGEON_COMS327_F19_MONSTER_H
