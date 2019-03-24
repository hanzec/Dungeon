
#include <cstring>
#include "../../include/macros.h"
#include "../../include/characters/npc.h"

npc::npc(dungeon_t * dungeon){this->dungeon = dungeon;}

int npc::movePC(direction_t direction){
    pair_t location;
    pair_t prev_location;

    memcpy(&location,this->currentLocation, sizeof(pair_t));
    memcpy(&prev_location,this->prevLocation, sizeof(pair_t));

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
        if ((this->dungeon->map[location[dim_y]][location[dim_x]] == ter_floor_room) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]] == ter_floor_hall) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]] == ter_stairs_up)  ||  
            (this->dungeon->map[location[dim_y]][location[dim_x]] == ter_stairs_down)   ){
                memcpy(this->currentLocation, &location, sizeof(pair_t));
                memcpy(this->prevLocation, &prev_location, sizeof(pair_t));
                return 0;
        }else
            return -1;
    } else
        return -1;
}



