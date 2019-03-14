//
// Created by chen_ on 2019/1/31.
//

//WINDOW *menu  todo: menu need to add;

#include "display.h"
#include "displayCommon.h"
#include "window_statusBar.h"
#include "window_characterInfo.h"
#include "window_dungeon.h"
#include "panel_monsterList.h"
#include "display_utils.h"

void initDisplayEnv(){
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

baseScreen_t * initScreen(dungeon_t * dungeon, pc_t * pc, monsterNode_t monsterNode){
    baseScreen_t * screen = malloc(sizeof(baseScreen_t));
    bzero(screen,sizeof(baseScreen_t));
    // FIXME bug here statusWindow and pcInfoWindow have same memory address for no reason
    screen->statusWindow = initStatusBar();
    screen->pcInfoWindow = initCharacterInfo(pc);
    screen->dungeonWindow = initDungeonDisplay(dungeon);
    screen->monsterListPanel[0] = initMonsterList(&monsterNode);
    screen->monsterListPanel[1] = new_panel(screen->dungeonWindow);

    //update pc location
    updatePc(screen->dungeonWindow,pc);

    // set up monsterList
    set_panel_userptr(screen->monsterListPanel[0],screen->monsterListPanel[1]);
    set_panel_userptr(screen->monsterListPanel[1],screen->monsterListPanel[0]);

    update_panels();
    doupdate();
    return screen;
}

int showMonsterList(baseScreen_t * screen,monsterNode_t * monsterNode){
    top_panel(screen->monsterListPanel[0]);
    updateMonsterList(panel_window(screen->monsterListPanel[0]),monsterNode);
    update_panels();
    doupdate();
    getch();
    top_panel(screen->monsterListPanel[1]);
    update_panels();
    doupdate();
}

int closeScreen(baseScreen_t * screen){
    destroy_win(screen->pcInfoWindow);
    destroy_win(screen->statusWindow);
    destroy_win(screen->dungeonWindow);
    return 0;
}

int updatePCLocation(baseScreen_t * screen,pc_t * pc){
    updatePc(screen->dungeonWindow,pc);
    wrefresh(screen->dungeonWindow);
}

int updateMonsterLocation(baseScreen_t * screen, monster_t * monster){
    updateMonster(screen->dungeonWindow,monster);
    wrefresh(screen->dungeonWindow);
}

int updateDungeonScreen(baseScreen_t * screen, dungeon_t *dungeon){
    updateDungeon(screen->dungeonWindow,dungeon);
    wrefresh(screen->dungeonWindow);
}

int showDiedScreen(baseScreen_t * screen){
    //closeScreen(screen);
    DiedScreen();
    endwin();
}