#ifndef DUNGEON_COMS327_F19_MONSTERFACTORY_H
#define DUNGEON_COMS327_F19_MONSTERFACTORY_H

#include <iostream>
#include "Monster.h"
#include "GameContent.h"
#include "GameContantFactory.h"

class MonsterFactory : public GameContantFactory{
private:
    void updateGameItemPool();
public:
    static Monster generateNewGameContant();
    MonsterFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList);
};

#endif