//
// Created by 陈瀚泽 on 2019-03-11.
//

#ifndef DUNGEON_COMS327_F19_GAMECOMMON_H
#define DUNGEON_COMS327_F19_GAMECOMMON_H

#include <vector>
#include <stdint.h>

#define DUNGEON_X              80
#define DUNGEON_Y              21
#define MIN_ROOMS              6
#define ROOM_MAX_X             20
#define ROOM_MAX_Y             15
#define ROOM_MIN_X             4
#define ROOM_MIN_Y             3
#define MAX_ROOM_RATIO         90
#define DUNGEON_VERSION        0
#define MAX_ROOMS              10
#define MONSTER_RANGE           3
#define mappair(pair) (d->map[pair[dim_y]][pair[dim_x]].terrain_type)
#define mapxy(x, y) (d->map[y][x].terrain_type)
#define hardnesspair(pair) (d->map[pair[dim_y]][pair[dim_x]].hardness)
#define hardnessxy(x, y) (d->map[y][x].hardness)
#define DUNGEON_KEY_CONF_LOC "~/.rlg327/keyBind.conf"

typedef enum dim {
    dim_x,
    dim_y,
    num_dims
} dim_t;

typedef int16_t pair_t[num_dims];

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

typedef struct dungeon {
    uint8_t num_rooms;
    pair_t pcInitLocation;
    std::vector<room_t *> rooms;
    std::vector<pair_t *> upStaris;
    std::vector<pair_t *> downStaris;
    map_block_t map[DUNGEON_Y][DUNGEON_X];
} dungeon_t;

#endif //DUNGEON_COMS327_F19_GAMECOMMON_H
