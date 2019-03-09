//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
#define COMS327_S19_DUNGEON_MONSTERCONTROLLER_H

#include "monster.h"

typedef struct monsterNode{
    uint32_t time;
    monster_t * monster;
    struct monsterNode * prevNode;
    struct monsterNode * nextNode;
} monsterNode_t ;

void pushSingleMonster(monsterNode_t * monsterNode, monster_t * monster, uint32_t weight);
void pushMonsterToQueue(uint32_t number, dungeon_t * dungeon, pc_t * pc , monsterNode_t * monsterNode);
monster_t * popMinMonster(monsterNode_t * monsterNode);
monster_t * seeFrontMonster(monsterNode_t * monsterNode);
void cleanMonsterQueue(monsterNode_t * monsterNode);
#endif //COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
