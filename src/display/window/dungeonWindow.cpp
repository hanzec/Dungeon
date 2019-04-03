//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <ncurses.h>
#include "../../../include/display/displayCommon.h"
#include "../../../include/display/window/dungeonWindow.h"

void dungeonWindow::setFOWStatus(bool flag){ 
    this->fow = flag;
    dungeonWindow::updateMap();
    dungeonWindow::updateNPC(); 
}

void dungeonWindow::setTeleportStatus(bool flag){this->teleport = flag; }

dungeonWindow::dungeonWindow(dungeon_t * d, Pc * npc) {
    this->npc = npc;
    this->fow = false;
    this->dungeonPtr = d;
    this->teleport = false;
    this->windowPtr = newwin(21,DUNGEON_X,1,0);
    wbkgd(this->windowPtr,COLOR_PAIR(PAIR_DUNGEON_WINDOW));
    this->updateMap();
}

int dungeonWindow::updateMapByPixel(int x, int y) {
    mvwaddch(this->windowPtr,y,x,this->getTerFromChar(x, y));
    wrefresh(this->windowPtr);
    return 0;
}

void dungeonWindow::updateMap() {
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            if (this->fow) {
                if (this->dungeonPtr->map[i][j].visable) 
                    mvwaddch(this->windowPtr,i,j,this->getTerFromChar(j, i));
                else
                    mvwaddch(this->windowPtr,i,j,' ');
                
            }else
                mvwaddch(this->windowPtr,i,j,this->getTerFromChar(j, i));
        }
    }
    wrefresh(this->windowPtr);
}


int dungeonWindow::updateNPC() {
    if (npc->prevLocation != nullptr){
        //set map to visable
        for(int i = -1; i <2 ; i++){
            for(int j = -1; j < 2; j++){
                this->dungeonPtr->map[npc->currentLocation[dim_x] + i][npc->currentLocation[dim_y] + j].visable = true;
                if (fow)
                    dungeonWindow::updateMapByPixel(npc->currentLocation[dim_x] + i,npc->currentLocation[dim_y] + j);
            }  
        }
        //update pc location
        mvwaddch(this->windowPtr,
                 npc->prevLocation[dim_y],
                 npc->prevLocation[dim_x],
                 this->getTerFromChar(npc->prevLocation[dim_x],npc->prevLocation[dim_y])
                 );
        if (teleport)
            mvwaddch(this->windowPtr,npc->currentLocation[dim_y], npc->currentLocation[dim_x],'*');
        else
            mvwaddch(this->windowPtr,npc->currentLocation[dim_y], npc->currentLocation[dim_x],'@');
            
        wrefresh(this->windowPtr);
        return 0;
    } else
        return -1;
}

int dungeonWindow::updateMonster(Monster * monster) {
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


