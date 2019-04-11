#ifndef DUNGEON_COMS327_F19_GAMECONTENT_H
#define DUNGEON_COMS327_F19_GAMECONTENT_H

#include <string>
#include <unordered_map>
#include "../GameCommon.h"

using namespace std;
class GameContent{
protected:
    int color;
    char symbol;
    double range, speed, damage;
    string description, name;
public:
    int itemID;
    string getName();
    double getSpeed();
    double getRange();
    double getDamage();
    string getDescription();
    static double diceToDouble(const string str);
    GameContent(unordered_map<string, string> base);
};
#endif