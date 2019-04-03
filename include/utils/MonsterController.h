//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
#define COMS327_S19_DUNGEON_MONSTERCONTROLLER_H

#include "../gameCommon.h"
#include "../characters/pc.h"
#include "../characters/monster.h"

class monsterController{
private:
    Pc * user;
    dungeon_t * dungeon;
    int numberOfMonster = 0;
public:
    MonsterNode_t * currentNode;

    int getNumberOfMonster();
    void cleanMonsterQueue();
    Monster * popMinMonster();
    int seeMinMonsterTime();
    void addMonsterToQueue(uint32_t number);
    monsterController(dungeon_t * dungeon = nullptr, Pc * user = nullptr);
    void addSingleMonster(Monster * monster, int weight);
};
#endif //COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
