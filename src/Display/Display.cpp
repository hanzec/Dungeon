//
// Created by 陈瀚泽 on 2019-03-14.
//d

#include <ncurses.h>
#include "../../include/Display/Display.h"
#include "../../include/Display/tombstone.h"
#include "../../include/Display/displayCommon.h"
#include "../../include/Display/window/statusBar.h"
#include "../../include/Display/panel/monsterList.h"
#include "../../include/Display/window/dungeonWindow.h"
#include "../../include/Display/window/characterInfo.h"

dungeon_t * Display::dungeonPtr;
monsterList * Display::monsterListPtr;
gameWindow * Display::windowStack[num_windows];

int Display::initDisplayEnv() {
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

    //init color pair of monster
    init_pair(PAIR_RED, COLOR_RED, COLOR_BLACK );
    init_pair(PAIR_BLUE, COLOR_BLUE,COLOR_BLACK);
    init_pair(PAIR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(PAIR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(PAIR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(PAIR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(PAIR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PAIR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);

    refresh();

    return 0;
}

int Display::initScreen(dungeon_t *dungeon) {
    // FIXME bug here statusWindow and pcInfoWindow have same memory address for no reason
    // update 3-14-2019 may fix bug but need testing

    //init internal dungeon env ptr
    dungeonPtr = dungeon;

    //inital the main window of the dungeon game
    windowStack[statusBar_win] = new statusBar();
    windowStack[characterInfo_win] = new characterInfo();
    windowStack[dungeonScreen_win] = new dungeonWindow(dungeon);

    //initial monster list panel
    // FIXME monsterList class as abstract class
    monsterListPtr = new monsterList(dungeon->monsterArray);
    PANEL * tmpPanel = new_panel((windowStack[dungeonScreen_win])->windowPtr);

    // set up monsterList
    set_panel_userptr(tmpPanel,monsterListPtr->panel);
    set_panel_userptr(monsterListPtr->panel,tmpPanel);

    //refreash screen
    update_panels();
    doupdate();

    return 0;
}

int Display::closeScreen() {
    return 0;
}

void Display::setFOWStatus(bool flag){((dungeonWindow *)windowStack[dungeonScreen_win])->setFOWStatus(flag);}

void Display::setTeleportStatus(bool flag){((dungeonWindow *)windowStack[dungeonScreen_win])->setTeleportStatus(flag);}

int Display::showDiedScreen() {

    mvaddstr(0,0,tombstone);
    refresh();
    getch();
    return 0;
}

int Display::showMonsterList() {
    monsterListPtr->updatePanel();
    monsterListPtr->displayPanel();

    //wait for user press any key
    getch();
    monsterListPtr->hidePanel();
    return 0;
}

int Display::updatePlayerLocation(pair_t location, pair_t prevLocation) {
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updatePlayer(location,prevLocation);
    return 0;
}

int Display::updateMonsterLocation() {
    return 0;
}

int Display::updateDungeonMap(dungeon_t *dungeon) {
    Display::dungeonPtr = dungeon;
    monsterListPtr->updateMonsterNode(dungeon->monsterArray);
    return 0;
}
int Display::updateMonsterLocation(pair_t location, pair_t prevLocation, int color, char symbol){
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updateGameItem(location,prevLocation,color,symbol);
    return 0;
}

int Display::updateItemLocation(pair_t location, pair_t prevLocation, int color, char symbol){
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updateGameItem(location,prevLocation,color,symbol);
    return 0;
}
