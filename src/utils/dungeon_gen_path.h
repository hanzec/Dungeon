//
// Created by 陈瀚泽 on 2019-02-14.
//

#ifndef DUNGEON_COMS327_F19_DUNGEON_GEN_PATH_H
#define DUNGEON_COMS327_F19_DUNGEON_GEN_PATH_H

#include "../../../../Downloads/chen_hanze-assignment-1.03 2/heap.h"
#include "../../../../Downloads/chen_hanze-assignment-1.03 2/dungeon_map_generate.h"

typedef struct corridor_node {
    pair_t pos;
    int32_t cost;
    heap_node_t *hn;
    void * prev_node;

} corridor_node_t;

void dijkstra_tunnelling(dungeon_t *d, pair_t from);
void dijkstra_no_tunnelling(dungeon_t *d, pair_t from);


#endif //DUNGEON_COMS327_F19_DUNGEON_GEN_PATH_H
