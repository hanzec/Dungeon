//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_WINDOS_DUNGEON_H
#define DUNGEON_V1_01_WINDOS_DUNGEON_H
#include <ncurses.h>
#include "gameCommon.h"
#include "charactersCommon.h"

WINDOW * initDungeonDisplay(dungeon_t * dungeon);


const chtype getTerChar(dungeon_t * dungeon1, int x, int y);
int updatePc(WINDOW * dungeonWinodw, pc_t * pc);
int updateDungeon(WINDOW * dungeonWindow, dungeon_t * dungeon);
int updateMonster(WINDOW * dungeonWinodw, monster_t * monster);

#endif //DUNGEON_V1_01_WINDOS_DUNGEON_H
