#ifndef DUNGEON_COMS327_F19_MAP_H
#define DUNGEON_COMS327_F19_MAP_H

#include <vector>
#include "GameCommon.h"
#include <unordered_map>

//TODO need to change the name
typedef struct locationPair{
    int color;
    char symbol;
    pair_t prevLocation;
    pair_t currentLocation;
}locationPair_t;

class Map{
private:
    Map();
    static int headIndex;
    static std::vector<int> avaliableIndex;
    static std::vector<locationPair_t> changedPixel;
    static std::unordered_map<int,locationPair_t> locationPairMap;
public:    
    static pair_t getPlayerLocation();
    static int deleteGameItem(int itemID);
    static int updatePlayer(pair_t lcation);
    static int getGameItemColor(int itemID);
    static pair_t getPrevLocation(int itemID);
    static char getGameItemSymbol(int itemID);
    static pair_t getCurrentLocation(int itemID);
    static std::vector<locationPair_t> getChangedItem();
    static int updateGameItem(int itemID, pair_t location);
    static int addNewGameItem(pair_t location, char symbol, int color);

};

#endif