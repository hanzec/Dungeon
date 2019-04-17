
#include <string>
#include <cstring>
#include "../include/Player.h"
#include "../include/Utils/DungeonUtils.h"

Player::Player(dungeon_t * dungeon){
    this->speed = 10;
    this->dungeon = dungeon;
}

int Player::getSpeed(){ return this->speed;}

int Player::setPcLocation(location_t location) {
    if ((this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_floor_room) ||
        (this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_floor_hall) ||
        (this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_stairs_up)  ||  
        (this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_stairs_down)){
            this->location = location;
            return 0;
        }else
            return 1;
}

int Player::movePC(direction_t direction){
    location_t location;
    location = this->location;

    switch (direction){
        case Upper:
            location[curr_y] -= 1;
            break;
        case UpperLeft:
            location[curr_y] -= 1;
            location[curr_x] -= 1;
            break;
        case UpperRight:
            location[curr_y] -= 1;
            location[curr_x] += 1;
            break;
        case Right:
            location[curr_x] += 1;
            break;
        case Left:
            location[curr_x] -= 1;
            break;
        case Down:
            location[curr_y] += 1;
            break;
        case DownLeft:
            location[curr_y] += 1;
            location[curr_x] -= 1;
            break;
        case DownRight:
            location[curr_y] += 1;
            location[curr_x] += 1;
            break;        
        default:
            return -1;
    }

    if (checkLocation(location[curr_x],location[curr_y])){
        if ((this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_floor_room) ||
            (this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_floor_hall) ||
            (this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_stairs_up)  ||  
            (this->dungeon->map[location[curr_y]][location[curr_x]].terrain_type == ter_stairs_down)   ){
                this->location = location;
                DungeonUtils::Path::dijkstra_tunnelling(dungeon, this->location);
                DungeonUtils::Path::dijkstra_no_tunnelling(dungeon, this->location);
        }else
            return -1;
    } else
        return -1;
}
