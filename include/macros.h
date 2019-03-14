//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef DUNGEON_COMS327_F19_MACROS_H
#define DUNGEON_COMS327_F19_MACROS_H

#define checkLocation(x,y) (x > 0 && x < DUNGEON_X) && (y > 0 && y < DUNGEON_Y)
#define nextMonster(monster) ((corridor_node_t *) monster->path[monster->location[dim_y]][monster->location[dim_x]].prev_node)


#endif //DUNGEON_COMS327_F19_MACROS_H
