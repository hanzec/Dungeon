//
// Created by 陈瀚泽 on 2019/2/26.
//

#ifndef DUNGEON_COMS327_F19_PLAYER_H
#define DUNGEON_COMS327_F19_PLAYER_H

#include <vector>
#include <unordered_map>
#include "GameContant/GameObjects/Item.h"
#include "GameContant/GameObjects/GameContent.h"

using namespace std;

typedef enum wearSlot{
    WEAPONL,    WEAPONR,    OFFHANDL,   OFFHANDR,
    RANGED,     ARMOR,      HELMET,     CLOAK,
    GLOVES,     BOOTS,      RINGL,      RINGR,
    AMULET,     LIGHT,      numberSlot
}wearSlot_t;

class Player{
private:
    vector<Item> bag;
    location_t location;
    Item wearSlot[numberSlot];
    int base_healthPoint = 0, base_damagePoint = 0, base_speed = 0;
protected:
    int getSpeed();
    int getVision();
    int getWeight();
    int getHealthPoint();
    int getDamagePoint();
public:
    int movePC(direction_t direction);
    int setPcLocation(location_t location);
    Player();
};

#endif //DUNGEON_COMS327_F19_PC_H
