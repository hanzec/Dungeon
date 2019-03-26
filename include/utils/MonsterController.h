//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
#define COMS327_S19_DUNGEON_MONSTERCONTROLLER_H

#include "../gameCommon.h"
#include "../characters/pc.h"
#include "../characters/monster.h"

typedef struct monsterNode{
    uint32_t time;
    monster * monster;
    struct monsterNode * nextNode;
    struct monsterNode * prevNode;
}monsterNode_t;


class monsterController{
private:
    pc * pc;
    dungeon_t * dungeon;
    int numberOfMonster = 0;
public:
    monsterNode_t * currentNode;

    int getNumberOfMonster();
    void cleanMonsterQueue();
    monster * popMinMonster();
    void addMonsterToQueue(uint32_t number);
    monsterController(dungeon_t * dungeon, class pc * pc);
    void addSingleMonster(monster * monster, int weight);
};
#endif //COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
