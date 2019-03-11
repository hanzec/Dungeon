//
// Created by 陈瀚泽 on 2019-02-14.
//
#include "../../include/utils/dungeon_gen_path.h"

static int32_t corridor_node_cmp(const void *key, const void *with) {
    return ((corridor_node_t *) key)->cost - ((corridor_node_t *) with)->cost;
}

void dijkstra_no_tunnelling(dungeon_t *d, pair_t from, monster_t * monster)
{

    heap_t h;
    corridor_node_t *prev_node;

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            monster->path[y][x].pos[dim_y] = y;
            monster->path[y][x].pos[dim_x] = x;
            monster->path[y][x].cost = INT32_MAX;

        }
    }

    monster->path[from[dim_y]][from[dim_x]].cost = 0;

    heap_init(&h, corridor_node_cmp, NULL);

    heap_insert(&h,&monster->path[from[dim_y]][from[dim_x]]);

    while (h.size != 0){
        prev_node = heap_remove_min(&h);
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[dim_x];
                uint16_t y = i + prev_node->pos[dim_y];

                if (checkLocation(x,y)){
                    if (d->map[y][x] != ter_wall){
                        if (prev_node->cost + 1 < monster->path[y][x].cost){
                            monster->path[y][x].prev_node = prev_node;
                            monster->path[y][x].cost = prev_node->cost + 1;

                            heap_insert(&h,&monster->path[y][x]);
                        }
                    }
                }
            }
        }
    }
    heap_delete(&h);
}

void dijkstra_tunnelling(dungeon_t *d, pair_t from, monster_t * monster)
{

    heap_t h;
    corridor_node_t *prev_node;

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            monster->path[y][x].pos[dim_y] = y;
            monster->path[y][x].pos[dim_x] = x;
            monster->path[y][x].cost = INT32_MAX;

        }
    }


    monster->path[from[dim_y]][from[dim_x]].cost = 0;

    heap_init(&h, corridor_node_cmp, NULL);

    heap_insert(&h,&monster->path[from[dim_y]][from[dim_x]]);

    while (h.size != 0){
        prev_node = heap_remove_min(&h);
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[dim_x];
                uint16_t y = i + prev_node->pos[dim_y];

                if (checkLocation(x,y)){
                    int weight_tmp = 0;

                    if (d->map[y][x] == ter_wall_immutable)
                        break;

                    if (d->hardness[y][x] == 0){
                        weight_tmp = 1 + prev_node->cost;
                    }else{
                        weight_tmp = 1 + (d->hardness[y][x]/85) + prev_node->cost;
                    }

                    if (weight_tmp < monster->path[y][x].cost){

                        monster->path[y][x].prev_node = prev_node;
                        monster->path[y][x].cost = weight_tmp;

                        heap_insert(&h,&monster->path[y][x]);
                    }
                }
            }
        }
    }
    heap_delete(&h);
}