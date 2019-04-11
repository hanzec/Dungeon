
#include <string>
#include <cstring>
#include "../include/Player.h"

Player::Player(dungeon_t * dungeon){
    this->speed = 10;
    this->dungeon = dungeon;
}

int Player::getSpeed(){ return this->speed;}
int Player::setPcLocation(pair_t location) {
    if ((this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_floor_room) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_floor_hall) ||
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_stairs_up)  ||  
            (this->dungeon->map[location[dim_y]][location[dim_x]].terrain_type == ter_stairs_down)   ){
                this->prevLocation = this->currentLocation;
                this->currentLocation = location;
                return 0;
        }else
         return 1;
}

int Player::movePC(direction_t direction){
    pair_t location;
    pair_t prev_location;

    location = this->currentLocation;

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
                this->prevLocation = this->currentLocation;
                this->currentLocation = location;
                return 0;
        }else
            return -1;
    } else
        return -1;
}
