#ifndef DUNGEON_COMS327_F19_CHARACTER_H
#define DUNGEON_COMS327_F19_CHARACTER_H

#include "../gameCommon.h"

class Character{
protected:
    uint8_t range;
    uint8_t speed;
    dungeon_t * dungeon;
public:
    pair_t prevLocation;
    pair_t currentLocation;

    int getSpeed();
    int getRange();
    int move(direction_t direction);
};

#endif