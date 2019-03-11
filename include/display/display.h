//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_DISPLAY_H
#define DUNGEON_V1_01_DISPLAY_H
#include <stdlib.h>
#include <curses.h>
#include "../game.h"
#include "display_utils.h"
#include "../characters/monster.h"
#include "window/window_dungeon.h"
#include "window/window_statusBar.h"
#include "window/window_characterInfo.h"
#include "../characters/MonsterController.h"

typedef struct baseScreen{
    pc_t * pc;
    dungeon_t * dungeon;
    WINDOW * pcInfoWindow;
    WINDOW * statusWindow;
    WINDOW * dungeonWindow;
    monsterNode_t * monsterNode;
} baseScreen_t;

int closeScreen(baseScreen_t * screen);
baseScreen_t initScreen(dungeon_t * dungeon, monsterNode_t * monster, pc_t * pc);

#endif //DUNGEON_V1_01_DISPLAY_H
