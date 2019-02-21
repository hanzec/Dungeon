//
// Created by 陈瀚泽 on 2019-02-14.
//

#include "../../../../Downloads/chen_hanze-assignment-1.03 2/game.h"
#include <limits.h>
#include "dungeon_gen_path.h"
#include "../../../../Downloads/chen_hanze-assignment-1.03 2/heap.h"
#include "math.h"

static int32_t corridor_node_cmp(const void *key, const void *with) {
    return ((corridor_node_t *) key)->cost - ((corridor_node_t *) with)->cost;
}

void dijkstra_no_tunnelling(dungeon_t *d, pair_t from)
{

    heap_t h;
    corridor_node_t *prev_node;
    static corridor_node_t path[DUNGEON_Y][DUNGEON_X];

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            path[y][x].pos[dim_y] = y;
            path[y][x].pos[dim_x] = x;
            path[y][x].cost = INT32_MAX;

        }
    }

    path[from[dim_y]][from[dim_x]].cost = 0;

    heap_init(&h, corridor_node_cmp, NULL);

    heap_insert(&h,&path[from[dim_y]][from[dim_x]]);

    while (h.size != 0){
        prev_node = heap_remove_min(&h);
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[dim_x];
                uint16_t y = i + prev_node->pos[dim_y];

                if ((x > 0 && x < DUNGEON_X) && (y > 0 && y < DUNGEON_Y)){
                    if (d->map[y][x] != ter_wall){
                        if (prev_node->cost + 1 < path[y][x].cost){
                            path[y][x].prev_node = prev_node;
                            path[y][x].cost = prev_node->cost + 1;

                            heap_insert(&h,&path[y][x]);
                        }
                    }
                }
            }
        }
    }

    heap_delete(&h);

    for (int k = 0; k < DUNGEON_Y; ++k) {
        for (int i = 0; i < DUNGEON_X; ++i) {
            if (path[k][i].cost == INT32_MAX)
                printf(" ");
            else
                printf("%d",path[k][i].cost%10);
        }
        printf("\n");
    }

}

void dijkstra_tunnelling(dungeon_t *d, pair_t from)
{

    heap_t h;
    corridor_node_t *prev_node;
    int weight[DUNGEON_Y][DUNGEON_X];
    static corridor_node_t path[DUNGEON_Y][DUNGEON_X];

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            path[y][x].pos[dim_y] = y;
            path[y][x].pos[dim_x] = x;
            path[y][x].cost = INT32_MAX;

        }
    }


    path[from[dim_y]][from[dim_x]].cost = 0;

    heap_init(&h, corridor_node_cmp, NULL);

    heap_insert(&h,&path[from[dim_y]][from[dim_x]]);

    while (h.size != 0){
        prev_node = heap_remove_min(&h);
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[dim_x];
                uint16_t y = i + prev_node->pos[dim_y];

                if ((x > 0 && x < DUNGEON_X) && (y > 0 && y < DUNGEON_Y)){
                    int weight_tmp = 0;

                    if (d->map[y][x] == ter_wall_immutable)
                        break;

                    if (d->hardness[y][x] == 0){
                        weight_tmp = 1 + prev_node->cost;
                    }else{
                        weight_tmp = 1 + (d->hardness[y][x]/85) + prev_node->cost;
                    }

                    if (weight_tmp < path[y][x].cost){

                        path[y][x].prev_node = prev_node;
                        path[y][x].cost = weight_tmp;

                        heap_insert(&h,&path[y][x]);
                    }
                }
            }
        }
    }

    heap_delete(&h);

    for (int k = 0; k < DUNGEON_Y; ++k) {
        for (int i = 0; i < DUNGEON_X; ++i) {
            if (d->hardness[k][i] == 255)
                printf("x");
            else
                printf("%d",path[k][i].cost%10);
        }
        printf("\n");
    }

}