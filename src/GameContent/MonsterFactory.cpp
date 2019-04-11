#include "../../include/GameContant/MonsterFactory.h"

MonsterFactory::MonsterFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList){
    index = 0;
    this->attributeList = attributeList;
    updateGameItemPool();
}

Monster MonsterFactory::generateNewGameContant(dungeon * dungeon){
    std::unordered_map<std::string, std::string> tmpAttr;

    if (attributeList.size() < 10) {
        updateGameItemPool();
    }

    if (uniqueMonster.size() != 0) {
        tmpAttr = uniqueMonster.at(0);
        uniqueMonster.erase(uniqueMonster.begin());
    }else{
        tmpAttr = contentPool[index];
        contentPool.erase(contentPool.begin() + index);
    }
    
    
    Monster monster(tmpAttr,dungeon);
    monster.symbol = tmpAttr["SYMB"].at(0);
    monster.healthPoint = monster.diceToDouble(tmpAttr["HP"]);
    monster.currentLocation = dungeon->rooms[rand()%dungeon->rooms.size()]->position;
    
    uint8_t tmp = 0;
    if (tmpAttr["SYMB"].find("ERRATIC"))
        tmp +=1;
    if (tmpAttr["SYMB"].find("TUNNEL"))
        tmp +=2;
    if (tmpAttr["SYMB"].find("TELE"))
        tmp +=4;
    if (tmpAttr["SYMB"].find("SMART"))
        tmp +=8;
    
    monster.characteristics = tmp;
    return monster;
}

void MonsterFactory::updateGameItemPool(){
    std::unordered_map<std::string, std::string> tmpAttribute;

    for(size_t j = 0; j < 10; j++){
        for(size_t i = 0; i < attributeList.size (); i++){
            tmpAttribute = attributeList.at(i);
            if (rand()%100 < stoi(tmpAttribute["RRTY"])) {
                contentPool.push_back(tmpAttribute);
            }
            if (tmpAttribute["ABIL"].find("UNIQ")) {
                uniqueMonster.push_back(tmpAttribute);
                attributeList.erase(attributeList.begin() + i);
            }
            
        } 
    }
    
}