//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
#define COMS327_S19_DUNGEON_MONSTERCONTROLLER_H

#include "../gameCommon.h"
#include "../characters/pc.h"
#include "../characters/Monster.h"

typedef struct monsterNode{
    uint32_t time;
    monster::monster * monster;
    struct monsterNode * nextNode;
    struct monsterNode * prevNode;
}monsterNode_t;


class monsterController{
private:
    npc::npc * npc;
    dungeon_t * dungeon;
    int numberOfMonster = 0;
    monsterNode_t * currentNode;
public:
    int getNumberOfMonster();
    void cleanMonsterQueue();
    monster::monster * popMinMonster();
    void addMonsterToQueue(uint32_t number);
    monsterController(dungeon_t * dungeon, npc::npc * pc);
    void addSingleMonster(monster::monster * monster, int weight);
};
#endif //COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
