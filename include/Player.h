//
// Created by 陈瀚泽 on 2019/2/26.
//

#ifndef DUNGEON_COMS327_F19_PLAYER_H
#define DUNGEON_COMS327_F19_PLAYER_H

#include <unordered_map>
#include "GameContant/Item.h"
#include "GameContant/GameContent.h"

typedef enum wearSlot{
    WEAPONL,    WEAPONR,    OFFHANDL,   OFFHANDR,
    RANGED,     ARMOR,      HELMET,     CLOAK,
    GLOVES,     BOOTS,      RINGL,      RINGR,
    AMULET,     LIGHT,      numberSlot
}wearSlot_t;

class Player{
protected:
    dungeon_t *dungeon;
    int healthPoint, damgaePoint, speed;
    std::unordered_map<std::string,Item> itemCollection;
public:
    pair_t currentLocation,prevLocation;
    int getSpeed();
    int movePC(direction_t direction);
    int setPcLocation(pair_t location);
    Player(dungeon_t * dungeon = nullptr);
};

#endif //DUNGEON_COMS327_F19_PC_H
