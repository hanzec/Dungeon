#ifndef DUNGEON_COMS327_F19_GAMECONTENT_H
#define DUNGEON_COMS327_F19_GAMECONTENT_H

#include <string>
#include <unordered_map>
#include "../../GameCommon.h"

using namespace std;
class GameContent{
protected:
public:
    char symbol;
    int color,range;
    string description, name,speed, damage;

    int itemID;
    string getName();
    double getSpeed();
    double getRange();
    double getDamage();
    string getDescription();
    static double diceToDouble(const string str);
    GameContent(unordered_map<string, string> base);

private:

};
#endif