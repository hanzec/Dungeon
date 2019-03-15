//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_DISPLAY_H
#define DUNGEON_V1_01_DISPLAY_H

#include <panel.h>
#include <ncurses.h>
#include "../gameCommon.h"
#include "../characters/charactersCommon.h"

typedef struct baseScreen{
    WINDOW * pcInfoWindow;
    WINDOW * statusWindow;
    WINDOW * dungeonWindow;
    PANEL * monsterListPanel[2];
} baseScreen_t;

void initDisplayEnv();
int closeScreen(baseScreen_t * screen);
baseScreen_t * initScreen(dungeon_t * dungeon, npc_t * pc, monsterNode_t monsterNode);

//update screen 
int updatePCLocation(baseScreen_t * screen, npc_t * pc);
int updateDungeonScreen(baseScreen_t * screen, dungeon_t *dungeon);
int updateMonsterLocation(baseScreen_t * screen, monster_t * monster);


//panel related function
int showMonsterList(baseScreen_t * screen,monsterNode_t * monsterNode);

//end game screeen
int showDiedScreen(baseScreen_t * screen);

#endif //DUNGEON_V1_01_DISPLAY_H
