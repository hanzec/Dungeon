//
// Created by 陈瀚泽 on 2019-03-14.
//d

#include <ncurses.h>
#include "../../include/display/display.h"
#include "../../include/display/tombstone.h"
#include "../../include/display/displayCommon.h"
#include "../../include/display/window/statusBar.h"
#include "../../include/display/panel/monsterList.h"
#include "../../include/display/window/dungeonWindow.h"
#include "../../include/display/window/characterInfo.h"


Pc * display::npcPtr;
dungeon_t * display::dungeonPtr;
monsterList * display::monsterListPtr;
gameWindow * display::windowStack[num_windows];

int display::initDisplayEnv() {
    initscr();
    cbreak();
    noecho();
    start_color();
    keypad(stdscr, TRUE);

    //init color pair for display
    init_pair(PAIR_PANEL, COLOR_WHITE,COLOR_YELLOW);
    init_pair(PAIR_STATUS_BAR, COLOR_WHITE, COLOR_CYAN);
    init_pair(PAIR_DUNGEON_WINDOW, COLOR_WHITE, COLOR_BLACK);
    init_pair(PAIR_CHARACTER_STATUS, COLOR_BLACK, COLOR_WHITE);

    refresh();
}

int display::initScreen(dungeon_t *dungeon, Pc *pc) {
    // FIXME bug here statusWindow and pcInfoWindow have same memory address for no reason
    // update 3-14-2019 may fix bug but need testing

    //init internal dungeon env ptr
    npcPtr = pc;
    dungeonPtr = dungeon;

    //inital the main window of the dungeon game
    windowStack[statusBar_win] = new statusBar();
    windowStack[characterInfo_win] = new characterInfo();
    windowStack[dungeonScreen_win] = new dungeonWindow(dungeon,npcPtr);

    //initial monster list panel
    // FIXME monsterList class as abstract class
    monsterListPtr = new monsterList(dungeon->monsterArray);
    PANEL * tmpPanel = new_panel((windowStack[dungeonScreen_win])->windowPtr);

    // set up monsterList
    set_panel_userptr(tmpPanel,monsterListPtr->panel);
    set_panel_userptr(monsterListPtr->panel,tmpPanel);

    //update npc location
    updatePCLocation();

    //refreash screen
    update_panels();
    doupdate();

    return 0;
}

int display::closeScreen() {
    return 0;
}

void display::setFOWStatus(bool flag){((dungeonWindow *)windowStack[dungeonScreen_win])->setFOWStatus(flag);}

void display::setTeleportStatus(bool flag){((dungeonWindow *)windowStack[dungeonScreen_win])->setTeleportStatus(flag);}

int display::showDiedScreen() {

    mvaddstr(0,0,tombstone);
    refresh();
    getch();
    return 0;
}

int display::showMonsterList() {
    monsterListPtr->updatePanel();
    monsterListPtr->displayPanel();

    //wait for user press any key
    getch();
    monsterListPtr->hidePanel();
    return 0;
}

int display::updatePCLocation() {
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updateNPC();
    return 0;
}

int display::updateMonsterLocation() {
    return 0;
}

int display::updateDungeonMap(dungeon_t *dungeon) {
    display::dungeonPtr = dungeon;
    monsterListPtr->updateMonsterNode(dungeon->monsterArray);
}
