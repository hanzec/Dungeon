#include <ctime>
#include <cmath>
#include <unordered_map>
#include "../../include/GameContant/Monster.h"
#include "../../include/Utils/data_stucture/heap.h"

#define getCurrentHardness dungeon->map[this->location[curr_y]][this->location[curr_x]].hardness
#define nextTunnel ((corridor_node_t *) dungeon->tunnel[this->location[curr_y]][this->location[curr_x]].prev_node)
#define nextNonTunnel ((corridor_node_t *) dungeon->nontunnel[this->location[curr_y]][this->location[curr_x]].prev_node)


Monster::Monster(std::unordered_map<std::string, std::string> base, dungeon_t * dungeon):GameContent(base){
    this->itemID = 0;
    this->dungeon = dungeon;
    this->range = (uint8_t) (rand() % 3);
    this->nextMoveTime = this->getSpeed();
}

bool Monster::meetWithPlayer(location_t location){
    for (int i = -1 * this->range; i < this->range + 1 ; ++i) {
        for (int j = -1 * this->range; j < this->range + 1 ; ++j) {
            uint8_t x = (uint8_t) (this->location[curr_x] + i);
            uint8_t y = (uint8_t) (this->location[curr_y] + j);

            if (checkLocation(x,y)){
                if ((x == location[curr_x]) && (y == location[curr_y])){
                    this->lastPcLocation[curr_y] = y;
                    this->lastPcLocation[curr_x] = x;
                    return true;
                }
            }
        }
    }
    return false;
}

int Monster::moveMonster(location_t playerLocation){
    srand(time(NULL));
    location_t nextParh;
    if (this->characteristics & 0x1){
        bool flag = true;
        if ((rand() % 2 ) == 1){
            while(flag){
                int x = this->location[curr_x] + rand()%3 - 1;
                int y = this->location[curr_y] + rand()%3 - 1;
                if (checkLocation(x,y)){
                    if ((dungeonMapTer(x,y) == ter_floor_room) ||
                        (dungeonMapTer(x,y)  == ter_floor_hall))
                    {
                        flag = false;
                        nextParh[curr_y] = (int16_t) y;
                        nextParh[curr_x] = (int16_t) x;
                    }
                }
            }
            goto update;
        }
    }

    if (this->characteristics & 0x4){
        if(this->characteristics & 0x8){
            if(this->characteristics & 0x2){
                if ( getCurrentHardness == 0){
                    nextParh = nextTunnel->pos;
                    goto update;
                } else{
                    if (getCurrentHardness <= 85)
                        getCurrentHardness = 0;
                    else{
                        getCurrentHardness -= 85;
                    }
                    return 0;
                }
            }else{
                nextParh = nextNonTunnel->pos;
                goto update;
            }
        }else{
            double shortestDistance = UINT32_MAX;
            for (int i = -1; i <2 ; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int16_t y = (int16_t) (this->location[curr_y] + j);
                    int16_t x = (int16_t) (this->location[curr_x] + i);
                    if (checkLocation(x,y)){
                        double distance = sqrt(abs(this->location[curr_y] + j - playerLocation[curr_y])) +
                                            sqrt(abs(this->location[curr_x] + i - playerLocation[curr_x]));
                        if (distance < shortestDistance){
                            shortestDistance = distance;
                            nextParh[curr_x] = x;
                            nextParh[curr_y] = y;
                        }
                    }
                }
            }
            goto update;
        }
    } else if (this->meetWithPlayer(playerLocation)){
        if(this->characteristics & 0x8){
            if(this->characteristics & 0x2){
                if (getCurrentHardness == 0){
                    nextParh = nextTunnel->pos;
                    goto update;
                } else{
                    if (getCurrentHardness <= 85)
                        getCurrentHardness = 0;
                    else{
                        getCurrentHardness -= 85;
                    }
                    return 0;
                }
            }else{
                nextParh = nextNonTunnel->pos;
                goto update;
            }
        } else
            return 0;
    } else
        return 0;

    update:
    this->location = nextParh;

    return 0;
}