//
// Created by 陈瀚泽 on 2019/2/26.
//

#include "pc.h"
#include "macros.h"
#include "charactersCommon.h"

int movePC(direction_t direction, pc_t * pc){
    pair_t location;
    pair_t prev_location;

    memcpy(&location,pc->location, sizeof(pair_t));
    memcpy(&prev_location,pc->location, sizeof(pair_t));

    switch (direction){
        case Upper:
            location[dim_y] -= 1;
            break;
        case UpperLeft:
            location[dim_y] -= 1;
            location[dim_x] -= 1;
            break;
        case UpperRight:
            location[dim_y] -= 1;
            location[dim_x] += 1;
            break;
        case Right:
            location[dim_x] += 1;
            break;
        case Left:
            location[dim_x] -= 1;
            break;
        case Down:
            location[dim_y] += 1;
            break;
        case DownLeft:
            location[dim_y] += 1;
            location[dim_x] -= 1;
            break;
        case DownRight:
            location[dim_y] += 1;
            location[dim_x] += 1;
            break;        
        default:
            return -1;
    }

    if (checkLocation(location[dim_x],location[dim_y])){
        if ((pc->dungeon->map[location[dim_y]][location[dim_x]] == ter_floor_room) ||
            (pc->dungeon->map[location[dim_y]][location[dim_x]] == ter_floor_hall) ||
            (pc->dungeon->map[location[dim_y]][location[dim_x]] == ter_stairs_up)  ||  
            (pc->dungeon->map[location[dim_y]][location[dim_x]] == ter_stairs_down)   ){
                memcpy(pc->location, &location, sizeof(pair_t));
                memcpy(pc->prevLocation, &prev_location, sizeof(pair_t));
                return 0;
        }else
            return -1;
    } else
        return -1;
}

