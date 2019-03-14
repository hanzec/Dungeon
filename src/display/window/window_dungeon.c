//
// Created by chen_ on 2019/1/31.
//

#include "displayCommon.h"
#include "window_dungeon.h"
#include "charactersCommon.h"
#include "gameCommon.h"

WINDOW * initDungeonDisplay(dungeon_t * dungeon){
    WINDOW * dungeonWindow = newwin(21,DUNGEON_X,1,0);

    wbkgd(dungeonWindow,COLOR_PAIR(PAIR_DUNGEON_WINDOW));
    updateDungeon(dungeonWindow,dungeon);
    return dungeonWindow;
}

int updateDungeon(WINDOW * dungeonWindow, dungeon_t * dungeon){

    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            mvwaddch(dungeonWindow,i,j,getTerChar(dungeon, i, j));
        }
    }
}

int updatePc(WINDOW * dungeonWinodw, pc_t * pc){
    if (pc->prevLocation != NULL){
        mvwaddch(dungeonWinodw,
                 pc->prevLocation[dim_y],
                 pc->prevLocation[dim_x],
                 getTerChar(pc->dungeon,
                            pc->prevLocation[dim_y],
                            pc->prevLocation[dim_x])
        );
        mvwaddch(dungeonWinodw,pc->location[dim_y], pc->location[dim_x],'@');
        return 0;
    } else
        return -1;
}

int updateMonster(WINDOW * dungeonWinodw, monster_t * monster){
    if (monster->prev_location != NULL){
        mvwaddch(dungeonWinodw,
                 monster->prev_location[dim_x],
                 monster->prev_location[dim_y],
                 getTerChar(monster->dungeon,
                            monster->prev_location[dim_x],
                            monster->prev_location[dim_y])
        );
        mvwaddch(dungeonWinodw,monster->location[dim_y], monster->location[dim_x],'D');
        return 0;
    } else
        return -1;
}

const chtype getTerChar(dungeon_t * dungeon, int y, int x){
    switch (dungeon->map[y][x]) {
        case ter_wall:
        case ter_wall_immutable:
            return ' ';
        case ter_floor:
        case ter_floor_room:
            return '.';
        case ter_floor_hall:
            return '#';
        case ter_debug:
            return '*';
        case ter_stairs_up:
            return '<';
        case ter_stairs_down:
            return '>';
        default:
            return ' ';
    }
}
