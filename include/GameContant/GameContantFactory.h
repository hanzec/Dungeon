#ifndef DUNGEON_COMS327_F19_GAMECONTENTFACTORY_H
#define DUNGEON_COMS327_F19_GAMECONTENTFACTORY_H

#include <vector>
#include <unordered_map>
#include "GameContent.h"

class GameContantFactory{
protected:
    std::vector<std::unordered_map<std::string, std::string> > attributeList;
public:
    virtual GameContent generateNewGameContant() = 0;
    GameContantFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList);
};
#endif