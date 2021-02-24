#ifndef DUNGEON_COMS327_F19_MONSTERFACTORY_H
#define DUNGEON_COMS327_F19_MONSTERFACTORY_H

#include <iostream>
#include "Monster.h"
#include "GameObjects/GameContent.h"

class MonsterFactory{
private:
    void updateGameItemPool();
    int index, poolSize;
    std::vector<std::unordered_map<std::string, std::string> > contentPool;
    std::vector<std::unordered_map<std::string, std::string> > attributeList;
    std::vector<std::unordered_map<std::string, std::string> > uniqueMonster;
public:
    Monster * generateNewGameContant(Dungeon * dungeon);
    MonsterFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList);
};

#endif