#include "../../include/Utils/MonsterListUtils.h"

void MonsterListUtils::insertMonster(std::list<Monster> * monsters, Monster monster){
    for ( auto i = monsters->begin(); i != monsters->end(); i++){
        if(i->nextMoveTime > monster.nextMoveTime){
            monsters->insert(i,monster);
            return;
        }
    }
    monsters->push_back(monster);
}

void MonsterListUtils::removeMinMonster(std::list<Monster> * monsters){ monsters->pop_front();}
