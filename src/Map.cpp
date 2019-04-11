#include <vector>
#include <unordered_map>
#include "../include/Map.h"

int Map::headIndex = 1;
std::vector<int> Map::avaliableIndex;
std::vector<locationPair_t> Map::changedPixel;
std::unordered_map<int,locationPair_t> Map::locationPairMap;

int Map::updatePlayer(pair_t location){ return updateGameItem(0,location); }

pair_t Map:: getPlayerLocation(){ return locationPairMap[0].currentLocation; }

int Map::getGameItemColor(int itemID){ return locationPairMap[itemID].color; }

char Map::getGameItemSymbol(int itemID){return locationPairMap[itemID].symbol; }

pair_t Map::getPrevLocation(int itemID){ return locationPairMap[0].prevLocation; }

pair_t Map::getCurrentLocation(int itemID){ return locationPairMap[0].currentLocation; }

int Map::updateGameItem(int itemID, pair_t location){
    locationPair_t tmpLocation;
    
    if (locationPairMap.find(itemID) != locationPairMap.end())
        tmpLocation = locationPairMap[itemID];
    else
        return -1;

    tmpLocation.prevLocation = tmpLocation.currentLocation;
    tmpLocation.currentLocation = location;

    changedPixel.push_back(tmpLocation);
    locationPairMap[itemID] = tmpLocation;

    return 0;
}

int Map::deleteGameItem(int itemID){
    locationPair_t tmpLocation;
    
    if (locationPairMap.find(itemID) != locationPairMap.end())
        tmpLocation = locationPairMap[itemID];
    else
        return -1;
    
    tmpLocation.prevLocation = tmpLocation.currentLocation;
    tmpLocation.currentLocation[dim_x] = 0;
    tmpLocation.currentLocation[dim_y] = 0;

    locationPairMap.erase(itemID);
    avaliableIndex.push_back(itemID);
    changedPixel.push_back(tmpLocation);

    return 0; 
}

int Map::addNewGameItem(pair_t location, char symbol, int color){
    int index;
    locationPair_t tmpLocation;

    tmpLocation.color = color;
    tmpLocation.symbol = symbol;
    tmpLocation.prevLocation[dim_x] = 0;
    tmpLocation.prevLocation[dim_y] = 0;
    tmpLocation.currentLocation = location;

    if (avaliableIndex.size() != 0) {
        index = avaliableIndex.back();
        avaliableIndex.pop_back();
    }
    else{
        index = headIndex;
        headIndex += 1;
    }
    
    locationPairMap[index] = tmpLocation;

    return index;
}

std::vector<locationPair_t> Map::getChangedItem(){
    std::vector<locationPair_t> result = changedPixel;
    changedPixel.clear();
    return result;
}