//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_WINDOS_DUNGEON_H
#define DUNGEON_V1_01_WINDOS_DUNGEON_H
#include <curses.h>
#include "../../game.h"
#include "../../characters/pc.h"
#include "../../characters/MonsterController.h"

WINDOW * initDungeonDisplay(dungeon_t * dungeon, monsterNode_t * monster, pc_t * pc);


#endif //DUNGEON_V1_01_WINDOS_DUNGEON_H
