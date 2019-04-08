
#include <cstring>
#include "../../include/macros.h"
#include "../../include/GameContant/Pc.h"

Pc::Pc(dungeon_t * dungeon){
    this->range = 3;
    this->speed = 10;
    this->dungeon = dungeon;
}

int Pc::movePC(direction_t direction){
    
}

int Pc::setPcLocation(pair_t location) {
    if ((this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_floor_room) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_floor_hall) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_stairs_up)  ||  
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_stairs_down)   ){
                this->prevLocation[dim_x] = this->currentLocation[dim_x];
                this->prevLocation[dim_y] = this->currentLocation[dim_y];
                this->currentLocation[dim_x] = location[dim_x];
                this->currentLocation[dim_y] = location[dim_y];
                return 0;
        }else
         return 1;
}

int Pc::movePC(direction_t direction){
    pair_t location;
    pair_t prev_location;

    location[dim_x] = this->currentLocation[dim_x];
    location[dim_y] = this->currentLocation[dim_y];

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
        if ((this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_floor_room) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_floor_hall) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_stairs_up)  ||  
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_stairs_down)   ){
                this->prevLocation[dim_x] = this->currentLocation[dim_x];
                this->prevLocation[dim_y] = this->currentLocation[dim_y];
                this->currentLocation[dim_x] = location[dim_x];
                this->currentLocation[dim_y] = location[dim_y];
                return 0;
        }else
            return -1;
    } else
        return -1;
}
