//
// Created by 陈瀚泽 on 2019-02-27.
//

#ifndef COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
#define COMS327_S19_DUNGEON_MONSTERCONTROLLER_H

#include "gameCommon.h"
#include "charactersCommon.h"

int getNumberOfMonster(monsterNode_t monsterNode);
void cleanMonsterQueue(monsterNode_t * monsterNode);
monster_t * popMinMonster(monsterNode_t * monsterNode);
monsterNode_t * seeFrontMonsterNode(monsterNode_t * monsterNode);
void pushSingleMonster(monsterNode_t * monsterNode, monster_t * monster, uint32_t weight);
void pushMonsterToQueue(uint32_t number, dungeon_t * dungeon, pc_t * pc , monsterNode_t * monsterNode);
#endif //COMS327_S19_DUNGEON_MONSTERCONTROLLER_H
