//
// Created by chen_ on 2019/1/31.
//

#include "../../include/display/display.h"

//WINDOW *menu  todo: menu need to add;

baseScreen_t initScreen(dungeon_t * dungeon, monsterNode_t * monsterNode, pc_t * pc){
    baseScreen_t * screen = malloc(sizeof(baseScreen_t));

    cbreak();
    initscr();
    start_color();

    screen->pc = pc;
    screen->dungeon = dungeon;
    screen->monsterNode = monsterNode;
    screen->statusWindow = initStatusBar();
    screen->pcInfoWindow = initCharacterInfo(pc);
    screen->dungeonWindow = initDungeonDisplay(dungeon, monsterNode, pc);
}

int closeScreen(baseScreen_t * screen){
    destroy_win(screen->pcInfoWindow);
    destroy_win(screen->statusWindow);
    destroy_win(screen->dungeonWindow);
    return 0;
}