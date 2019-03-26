//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <ncurses.h>
#include "../../../include/display/displayCommon.h"
#include "../../../include/display/window/dungeonWindow.h"


dungeonWindow::dungeonWindow(dungeon_t * d) {
    this->dungeonPtr = d;
    this->windowPtr = newwin(21,DUNGEON_X,1,0);
    wbkgd(this->windowPtr,COLOR_PAIR(PAIR_DUNGEON_WINDOW));
    this->updateMap();
}

int dungeonWindow::updateMap() {
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            mvwaddch(this->windowPtr,i,j,this->getTerFromChar(i, j));
        }
    }
    return 0;
}

int dungeonWindow::updateNPC(pc *npc) {
    if (npc->prevLocation != nullptr){
        mvwaddch(this->windowPtr,
                 npc->prevLocation[dim_y],
                 npc->prevLocation[dim_x],
                 this->getTerFromChar(npc->prevLocation[dim_y],npc->prevLocation[dim_x])
                 );
        mvwaddch(this->windowPtr,npc->currentLocation[dim_y], npc->currentLocation[dim_x],'@');
        return 0;
    } else
        return -1;
}

int dungeonWindow::updateMonster(monster * monster) {
    if (monster->prevLocation != nullptr){
        mvwaddch(this->windowPtr,
                 monster->prevLocation[dim_x],
                 monster->prevLocation[dim_y],
                 this->getTerFromChar(monster->prevLocation[dim_x], monster->prevLocation[dim_y]));
        mvwaddch(this->windowPtr,monster->currentLocation[dim_y], monster->currentLocation[dim_x],'D');
        return 0;
    } else
        return -1;
}

const chtype dungeonWindow::getTerFromChar(int x, int y) {
    switch (dungeonPtr->map[y][x].terrain_type) {
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


