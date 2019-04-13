//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef DUNGEON_COMS327_F19_MACROS_H
#define DUNGEON_COMS327_F19_MACROS_H

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
#define mappair(pair) (d->map[pair[curr_y]][pair[curr_x]].terrain_type)
#define mapxy(x, y) (d->map[y][x].terrain_type)
#define hardnesspair(pair) (d->map[pair[curr_y]][pair[curr_x]].hardness)
#define hardnessxy(x, y) (d->map[y][x].hardness)
#define DUNGEON_KEY_CONF_LOC "~/.rlg327/keyBind.conf"


#define checkLocation(x,y) (x > 0 && x < DUNGEON_X) && (y > 0 && y < DUNGEON_Y)


#define dungeonHardness this->dungeon->hardness
#define dungeonMapTer(x,y) this->dungeon->map[y][x].terrain_type

#endif //DUNGEON_COMS327_F19_MACROS_H
