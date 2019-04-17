//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H


#include <string>
#include <vector>
#include <unordered_map>
#include "GameContent.h"
#include "../Utils/data_stucture/heap.h"




using namespace std;

class Monster : public GameContent{
private:
    dungeon_t * dungeon;
public:
    uint8_t characteristics;
    location_t lastPcLocation ;
    int healthPoint, nextMoveTime;
    int moveMonster(location_t playerLocation);
    bool meetWithPlayer(location_t playerLocation);
    Monster(std::unordered_map<std::string, std::string> base, dungeon_t * dungeon);
};

#endif //DUNGEON_COMS327_F19_MONSTER_H
