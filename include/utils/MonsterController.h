//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
#define COMS327_S19_DUNGEON_MONSTERCONTROLLER_H

#include "../GameCommon.h"
#include "../GameContant/Monster.h"

class monsterController{
private:
    dungeon_t * dungeon;
    int numberOfMonster;
public:
    MonsterNode_t * currentNode;
    int getNumberOfMonster();
    void cleanMonsterQueue();
    Monster * popMinMonster();
    int seeMinMonsterTime();
    void addMonsterToQueue(uint32_t number);
    monsterController(dungeon_t * dungeon = nullptr);
    void addSingleMonster(Monster * monster, int weight);
};
#endif //COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
