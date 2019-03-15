//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_DISPLAY_H
#define DUNGEON_V1_01_DISPLAY_H

#include <panel.h>
#include <ncurses.h>
#include "../gameCommon.h"
#include "../characters/charactersCommon.h"
#include "window/gameWindow.h"
#include "panel/monsterList.h"

typedef enum windowList{
    dungeonScreen_win,      statusBar_win,      characterInfo_win,
    num_windows
}windowList_t;

typedef enum panelList{
    monsterList_pan,
    num_panel
}panelList_T;

class display{
public:
    //screen operation
    display();
    int closeScreen();
    int initScreen(dungeon_t * dungeon, npc_t * pc, monsterNode_t * monsterNode);

    //special screen function
    int showDiedScreen();

    //panel realated Function
    int showMonsterList();

    //update screen function
    int updateNPCLocation();
    int updateDungeonScreen();
    int updateMonsterLocation();

private:
    npc_t * npcPtr;
    dungeon_t * dungeonPtr;
    monsterList * monsterListPtr;
    monsterNode_t * monsterNodePtr;
    gameWindow * windowStack[num_windows];
};
#endif //DUNGEON_V1_01_DISPLAY_H
