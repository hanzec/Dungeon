//
// Created by chen_ on 2019/1/31.
//

#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DUNGEON_V1_01_GAME_H
#define DUNGEON_V1_01_GAME_H


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

typedef enum dim {
    dim_x,
    dim_y,
    num_dims
} dim_t;

/* Returns true if random float in [0,1] is less than *
 * numerator/denominator.  Uses only integer math.    */
# define rand_under(numerator, denominator) \
  (rand() < ((RAND_MAX / denominator) * numerator))

/* Returns random integer in [min, max]. */
# define rand_range(min, max) ((rand() % (((max) + 1) - (min))) + (min))
# define UNUSED(f) ((void) f)

#define malloc(size) ({        \
  void *_tmp;                  \
  assert(_tmp = malloc(size)); \
  _tmp;                        \
})
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
    uint16_t num_rooms;
    pair_t pc_position;
    uint16_t num_up_stairs;
    room_t rooms[MAX_ROOMS];
    uint16_t num_down_stairs;
    uint8_t hardness[DUNGEON_Y][DUNGEON_X];
    terrain_type_t map[DUNGEON_Y][DUNGEON_X];
} dungeon_t;


dungeon_t* dump_dungeon();
void start_new(bool cli_mode);
void close_dungeon(bool cli_mode);
void load_dungeon(bool cli_mode);

#endif //DUNGEON_V1_01_GAME_H
