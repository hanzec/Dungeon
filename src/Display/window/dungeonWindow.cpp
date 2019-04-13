//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <ncurses.h>
#include "../../../include/Display/displayCommon.h"
#include "../../../include/Display/window/dungeonWindow.h"

#define getPrevChar getTerFromChar(location[prev_x], location[prev_y])

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


void dungeonWindow::updatePlayer(location_t location) {
   //set map to visable
    for(int i = -1; i <2 ; i++){
        for(int j = -1; j < 2; j++){
            this->dungeonPtr->map[location[curr_x] + i][location[curr_y] + j].visable = true;
            if (fow)
                dungeonWindow::updateMapByPixel(location[curr_x] + i,location[curr_y] + j);
        }  
    }
    //update pc location
    mvwaddch(this->windowPtr, location[prev_y], location[prev_x], getPrevChar);
    if (teleport)
        mvwaddch(this->windowPtr,location[curr_y], location[curr_x],'*');
    else
        mvwaddch(this->windowPtr,location[curr_y], location[curr_x],'@');
            
    wrefresh(this->windowPtr);
}

void dungeonWindow::updateGameContent(location_t location, int color, char symbol) {
   if (location[prev_x] != 0 && location[prev_y] != 0)
       mvwaddch(this->windowPtr, location[prev_y], location[prev_x], getPrevChar);

    //TODO for mutiple color for simgle monster support
    attron(COLOR_PAIR(color));
    mvaddch(location[curr_y] + 1, location[curr_x], symbol);
    attroff(COLOR_PAIR(color));
    wrefresh(this->windowPtr);
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


