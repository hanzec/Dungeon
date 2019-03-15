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
    static int closeScreen();
    static int initScreen(dungeon_t * dungeon, npc_t * pc, monsterNode_t * monsterNode);

    //special screen function
    static int showDiedScreen();

    //panel realated Function
    static int showMonsterList();

    //update screen function
    static int updateNPCLocation();
    static int updateDungeonScreen();
    static int updateMonsterLocation(monster_t * monster);

private:
    static npc_t * npcPtr;
    static dungeon_t * dungeonPtr;
    static monsterList * monsterListPtr;
    static monsterNode_t * monsterNodePtr;
    static gameWindow * windowStack[num_windows];
};
#endif //DUNGEON_V1_01_DISPLAY_H
