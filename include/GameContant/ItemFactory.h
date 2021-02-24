#ifndef DUNGEON_COMS327_F19_ITEMFACTORY_H
#define DUNGEON_COMS327_F19_ITEMFACTORY_H
#include <vector>
#include <unordered_map>
#include "Item.h"
class ItemFactory
{
private:
    void updateGameItemPool();
    int index, poolSize;
    std::vector<std::unordered_map<std::string, std::string> > contentPool;
    std::vector<std::unordered_map<std::string, std::string> > attributeList;
public:
    void generateNewGameContant(Dungeon * dungeon);
    ItemFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList);
    ~ItemFactory();
};
#endif