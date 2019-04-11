
#include "MonsterFactory.h"

MonsterFactory::MonsterFactory(std::vector<std::unordered_map<std::string, std::string> > attributeList){
    int index = 0;
    this->attributeList = attributeList;
    updateGameItemPool();
}

static Monster generateNewGameContant(){
    Monster result();
    
}

void MonsterFactory::updateGameItemPool(){
    std::unordered_map<std::string, std::string> tmpAttribute;

    while(index < this->contentPool->size){
        for(size_t i = 0; i < attributeList.size ; i++){
            tmpAttribute = attributeList.at(i);
            if (rand()%100 < stoi(tmpAttribute["RRTY"])) {
                this->contentPool[index] = tmpAttribute;
                index ++;
                this->index ++;
                this->poolSize ++;
            }     
        }       
    }   
}