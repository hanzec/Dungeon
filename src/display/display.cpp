//
// Created by 陈瀚泽 on 2019-03-14.
//


#include <ncurses.h>
#include "../../include/display/display.h"
#include "../../include/display/displayCommon.h"
#include "../../include/display/window/characterInfo.h"
#include "../../include/display/window/statusBar.h"
#include "../../include/display/window/dungeonWindow.h"
#include "../../include/display/panel/monsterList.h"

display::display() {
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

int display::initScreen(dungeon_t *dungeon, npc *pc, monsterNode_t * monsterNode) {
    // FIXME bug here statusWindow and pcInfoWindow have same memory address for no reason
    // update 3-14-2019 may fix bug but need testing

    //init internal dungeon env ptr
    npcPtr = pc;
    dungeonPtr = dungeon;
    monsterNodePtr = monsterNode;

    //inital the main window of the dungeon game
    windowStack[statusBar_win] = new statusBar();
    windowStack[characterInfo_win] = new characterInfo();
    windowStack[dungeonScreen_win] = new dungeonWindow(dungeon);

    //initial monster list panel

    // FIXME monsterList class as abstract class
    monsterListPtr = new monsterList(monsterNodePtr);
    PANEL * tmpPanel = new_panel((windowStack[dungeonScreen_win])->windowPtr);

    // set up monsterList
    set_panel_userptr(tmpPanel,monsterListPtr->panel);
    set_panel_userptr(monsterListPtr->panel,tmpPanel);

    //update npc location
    updateNPCLocation();

    //refreash screen
    update_panels();
    doupdate();
}

int display::closeScreen() {
    return 0;
}


int display::showDiedScreen() {

    mvaddstr(0,0,tombstone);
    refresh();
    getch();
}

int display::showMonsterList() {
    monsterListPtr->updatePanel();
    monsterListPtr->displayPanel();

    //wait for user press any key
    getch();
    monsterListPtr->hidePanel();
}

int display::updateNPCLocation() {
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updateNPC(npcPtr);
}

int display::updateDungeonScreen() {
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updateMap();
}

int display::updateMonsterLocation(monster::monster * monster) {
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updateMonster(monster);
}
