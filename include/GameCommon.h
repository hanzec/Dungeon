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
    dim_x,
    dim_y,
    num_dims
} dim_t;

typedef struct pair{
private:
    int dimx;
    int dimy;
public:
    int& operator[](int i){
        if (i == dim_x)
            return dimx;
        else
            return dimy;
    }
    void operator=(struct pair pair){
        this->dimx = pair.dimx;
        this->dimy = pair.dimy;
    }
}pair_t;

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
    pair_t position;
    pair_t size;
}room_t;

typedef enum direction{
    Upper,      UpperLeft,      UpperRight,
    Left,       Right,          Down,
    DownLeft,   DownRight,
}direction_t;

typedef struct dungeon {
    uint8_t num_rooms;
    pair_t pcInitLocation;
    MonsterNode * monsterArray;
    std::vector<room_t *> rooms;
    std::vector<pair_t *> upStairs;
    std::vector<pair_t *> downStairs;
    map_block_t map[DUNGEON_Y][DUNGEON_X];
} dungeon_t;
#endif //DUNGEON_COMS327_F19_GAMECOMMON_H
