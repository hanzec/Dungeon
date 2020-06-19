#ifndef DUNGEON_COMS327_F19_ITEM_H
#define DUNGEON_COMS327_F19_ITEM_H

#include <vector>
#include "GameObjects/GameContent.h"
#include <unordered_map>
#include "../GameCommon.h"

class Item : public GameContent
{
private:
    bool isTake;
public:
    Item generateNewGameContant();
    Item(std::unordered_map<std::string, std::string> base);
};

#endif
