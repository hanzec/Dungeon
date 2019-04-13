//
// Created by chen_ on 2019/1/31.
//

#ifndef DUNGEON_V1_01_DISPLAY_H
#define DUNGEON_V1_01_DISPLAY_H

#include <panel.h>
#include <ncurses.h>
#include "../GameCommon.h"
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

class Display{
public:
    //screen operation
    static int initDisplayEnv();
    static int closeDislaySystem();
    static int initDisplaySystem(dungeon_t * dungeon);

    //spectcial game mode
    static void setFOWStatus(bool flag);
    static void setTeleportStatus(bool flag);

    //special screen function
    static int showDiedScreen();

    //panel realated Function
    static int showMonsterList();

    //update screen function
    static void updateDungeonMap();
    static void updatePlayer(location_t location);
    static void updateGameContent(location_t location, int color, char symbol);

private:
    static dungeon_t * dungeonPtr;
    static monsterList * monsterListPtr;
    static gameWindow * windowStack[num_windows];

};
#endif //DUNGEON_V1_01_DISPLAY_H
