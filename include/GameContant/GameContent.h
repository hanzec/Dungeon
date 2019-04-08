#ifndef DUNGEON_COMS327_F19_GAMECONTENT_H
#define DUNGEON_COMS327_F19_GAMECONTENT_H

#include <string>
#include <unordered_map>
#include "../gameCommon.h"

class GameContent{
protected:
    double range, speed, damage;
    std::string description, name;
public:
    pair_t prevLocation;
    pair_t currentLocation;

    double getSpeed();
    double getRange();
    double getDamage();
    std::string getName();
    std::string getDescription();
    static double diceToDouble(const std::string str);
    GameContent(std::unordered_map<std::string, std::string> base);

};
#endif