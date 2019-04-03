
#include <cstring>
#include "../../include/macros.h"
#include "../../include/characters/pc.h"

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



