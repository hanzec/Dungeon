//
// Created by 陈瀚泽 on 2019-03-11.
//

#ifndef DUNGEON_COMS327_F19_GAMECOMMON_H
#define DUNGEON_COMS327_F19_GAMECOMMON_H

#include <list>
#include <memory>
#include <vector>
#include <cstdint>
#include "macros.h"

class Item;
class Monster;

typedef enum dim {
    curr_x,     curr_y,
    prev_x,     prev_y
} dim_t;

typedef struct location{
private:
    struct pair {
        int dimx = 0;
        int dimy = 0;
    }pair_t;
    struct pair prev;
    struct pair current;
public:
    int& operator[](int i){
        if (i == curr_x)
            return this->current.dimx;
        else if (i == curr_y)
            return this->current.dimy;
        else if (i == prev_x)
            return this->prev.dimx;
        else
            return this->prev.dimy;
    }
    void operator=(struct location pair){
        this->prev = this->current;
        this->current.dimx = pair[curr_x];
        this->current.dimy = pair[curr_y];
    }
}location_t;

typedef struct corridor_node {
    int cost;
    location_t pos;
    void * prev_node;
} corridor_node_t;

typedef enum __attribute__ ((__packed__)) terrain_type {
    ter_debug,
    ter_wall,
    ter_wall_immutable,
    ter_floor,
    ter_floor_room,
    ter_floor_hall,
    ter_stairs,
    ter_stairs_up,
    ter_stairs_down
} terrain_type_t;

typedef struct map_block{
    bool visable;
    uint8_t hardness;
    std::shared_ptr<Item> item;
    terrain_type_t terrain_type;
    std::shared_ptr<Monster> monster;
} map_block_t;

typedef struct room{
    location_t position;
    location_t size;
}room_t;

typedef enum direction{
    Upper,      UpperLeft,      UpperRight,
    Left,       Right,          Down,
    DownLeft,   DownRight,
}direction_t;

typedef struct dungeon {
    map_block_t map[DUNGEON_Y][DUNGEON_X];
    corridor_node_t tunnel[DUNGEON_Y][DUNGEON_X];
    corridor_node_t nontunnel [DUNGEON_Y][DUNGEON_X];

    std::vector<room_t> rooms;
    std::vector<location_t> upStairs;
    std::vector<location_t> downStairs;
    std::list<std::shared_ptr<Item> > items;
    std::list<std::shared_ptr<Monster> > monsters;
} dungeon_t;

#endif //DUNGEON_COMS327_F19_GAMECOMMON_H
