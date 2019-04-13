//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H


#include <string>
#include <vector>
#include <unordered_map>
#include "GameContent.h"
#include "../utils/data_stucture/heap.h"


typedef struct corridor_node {
    int cost;
    location_t pos;
    heap_node_t *hn;
    void * prev_node;
} corridor_node_t;

using namespace std;

class Monster : public GameContent{
private:
    dungeon_t * dungeon;
public:
    int healthPoint;
    uint8_t characteristics;
    location_t lastPcLocation ;
    corridor_node_t path[DUNGEON_Y][DUNGEON_X];
    int moveMonster(location_t playerLocation);
    bool meetWithPlayer(location_t playerLocation);
    void dijkstra_tunnelling(location_t playerLocation);
    void dijkstra_no_tunnelling(location_t playerLocation); // TODO write as private class
    Monster(unordered_map<string, string> base, dungeon_t * dungeon);
};

#endif //DUNGEON_COMS327_F19_MONSTER_H
