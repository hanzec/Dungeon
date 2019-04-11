//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <ncurses.h>
#include "../../../include/Display/displayCommon.h"
#include "../../../include/Display/window/dungeonWindow.h"

void dungeonWindow::setFOWStatus(bool flag){ 
    this->fow = flag;
    dungeonWindow::updateMap();
}

void dungeonWindow::setTeleportStatus(bool flag){this->teleport = flag; }

dungeonWindow::dungeonWindow(dungeon_t * d) {
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


int dungeonWindow::updatePlayer(pair_t location, pair_t prevLocation) {
   //set map to visable
    for(int i = -1; i <2 ; i++){
        for(int j = -1; j < 2; j++){
            this->dungeonPtr->map[location[dim_x] + i][location[dim_y] + j].visable = true;
            if (fow)
                dungeonWindow::updateMapByPixel(location[dim_x] + i,location[dim_y] + j);
        }  
    }
    //update pc location
    mvwaddch(this->windowPtr, prevLocation[dim_y], prevLocation[dim_x], 
            getTerFromChar(prevLocation[dim_x], prevLocation[dim_y]));
    if (teleport)
        mvwaddch(this->windowPtr,location[dim_y], location[dim_x],'*');
    else
        mvwaddch(this->windowPtr,location[dim_y], location[dim_x],'@');
            
    wrefresh(this->windowPtr);
    return 0;
}

int dungeonWindow::updateGameItem(pair_t location, pair_t prevLocation, int color, char symbol) {
   if (prevLocation[dim_x] != 0 && prevLocation[dim_x] != 0)
       mvwaddch(this->windowPtr, prevLocation[dim_y], prevLocation[dim_x],
                getTerFromChar(prevLocation[dim_x], prevLocation[dim_y]));

    //TODO for mutiple color for simgle monster support
    attron(COLOR_PAIR(color));
    mvaddch(location[dim_y] + 1, location[dim_x], symbol);
    attroff(COLOR_PAIR(color));
    wrefresh(this->windowPtr);
    return 0;
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


