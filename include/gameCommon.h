//
// Created by 陈瀚泽 on 2019-03-11.
//

#ifndef DUNGEON_COMS327_F19_GAMECOMMON_H
#define DUNGEON_COMS327_F19_GAMECOMMON_H

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
#define mappair(pair) (d->map[pair[dim_y]][pair[dim_x]])
#define mapxy(x, y) (d->map[y][x])
#define hardnesspair(pair) (d->hardness[pair[dim_y]][pair[dim_x]])
#define hardnessxy(x, y) (d->hardness[y][x])
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

typedef struct room{
    pair_t position;
    pair_t size;
}room_t;

typedef struct dungeon {
    uint8_t num_rooms;
    pair_t pc_location;
    uint8_t num_up_stairs;
    room_t rooms[MAX_ROOMS];
    uint8_t num_down_stairs;
    uint8_t hardness[DUNGEON_Y][DUNGEON_X];
    terrain_type_t map[DUNGEON_Y][DUNGEON_X];
} dungeon_t;


#endif //DUNGEON_COMS327_F19_GAMECOMMON_H
