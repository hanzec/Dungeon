//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_WINDOS_DUNGEON_H
#define DUNGEON_V1_01_WINDOS_DUNGEON_H
#include <curses.h>
#include "../../game.h"
#include "../../characters/pc.h"
#include "../../characters/MonsterController.h"

typedef struct gameArea{
    pc_t pc;
    WINDOW * window;
    dungeon_t * dungeon;
    monsterNode_t * monsterNode
}gameArea_t;


int updateAll(gameArea_t * gameArea);
int updateArea(gameArea_t * gameArea, uint8_t x, uint8_t y);
gameArea_t initDungeonDisplay(dungeon_t * dungeon,monsterNode_t * monsterNode,pc_t * pc);

#endif //DUNGEON_V1_01_WINDOS_DUNGEON_H
