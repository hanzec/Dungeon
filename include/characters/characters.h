#ifndef DUNGEON_COMS327_F19_CHARACTER_H
#define DUNGEON_COMS327_F19_CHARACTER_H

#include "../gameCommon.h"

class character{
protected:
    uint8_t range;
    uint8_t speed;
    dungeon_t * dungeon;
    pair_t prevLocation;
    typedef enum direction{
        Upper,      UpperLeft,      UpperRight,
        Left,       Right,          Down,       
        DownLeft,   DownRight,
    }direction_t;
public:
    pair_t currentLocation;

    character(/* args */);
    ~character();
    int getSpeed();
    int getRange();
    int move(direction_t direction);
};

#endif