//
// Created by chen_ on 2019/1/31.
//

#ifndef COMS327_S19_DUNGEON_DUNGEON_MAP_GENERATE_H
#define COMS327_S19_DUNGEON_DUNGEON_MAP_GENERATE_H

#include "heap.h"


typedef struct corridor_path {
    heap_node_t *hn;
    uint8_t pos[2];
    uint8_t from[2];
    int32_t cost;
} corridor_path_t;


void generate_dungon(dungeon_t *dunegeon);

#endif //COMS327_S19_DUNGEON_DUNGEON_MAP_GENERATE_H
