//
// Created by 陈瀚泽 on 2019-03-11.
//

#ifndef DUNGEON_COMS327_F19_GAMECOMMON_H
#define DUNGEON_COMS327_F19_GAMECOMMON_H

#include <vector>
#include <stdint.h>
#include "macros.h"

class Monster;

    typedef struct MonsterNode{
        int time;
        Monster * monster;
        struct MonsterNode * nextNode;
        struct MonsterNode * prevNode;
    }MonsterNode_t;

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
            return this->prev.dimy;
        else
            return this->prev.dimy;
    }
    void operator=(struct location pair){
        this->prev = this->current;
        this->current.dimx = pair[curr_x];
        this->current.dimy = pair[curr_y];
    }
}location_t;

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
    terrain_type_t terrain_type;
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
    uint8_t num_rooms;
    location_t pcInitLocation; //need to remove 
    MonsterNode * monsterArray;
    std::vector<room_t *> rooms;
    std::vector<location_t> upStairs;
    std::vector<location_t> downStairs;
    map_block_t map[DUNGEON_Y][DUNGEON_X];
} dungeon_t;
#endif //DUNGEON_COMS327_F19_GAMECOMMON_H
