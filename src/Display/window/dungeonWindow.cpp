//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <ncurses.h>
#include "../../../include/GameContant/Item.h"
#include "../../../include/GameContant/Monster.h"
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
    if(!this->dungeonPtr->map[y][x].visable){
        if(fow){
            mvwaddch(this->windowPtr,y,x,' ');
            return 0;
        }
    }

    if(this->dungeonPtr->map[y][x].monster != nullptr){
        wattron(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[y][x].monster->color));
        mvwaddch(this->windowPtr, y + 1,x,this->dungeonPtr->map[y][x].monster->symbol);
        wattroff(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[y][x].monster->color));
        return 0;
    }else{
        if(this->dungeonPtr->map[y][x].isItemInit){
            wattron(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[y][x].item->color));
            mvwaddch(this->windowPtr, y + 1,x,this->dungeonPtr->map[y][x].item->symbol);
            wattroff(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[y][x].item->color));
            return 0;
        }
    }
    mvwaddch(this->windowPtr,y,x,this->getTerFromChar(x, y));
    return 0;
}

void dungeonWindow::updateMap() {
    std::list<std::pair<int, int> > gameItems;
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            if(this->dungeonPtr->map[i][j].monster != nullptr || this->dungeonPtr->map[i][j].isItemInit)
                gameItems.push_back(std::pair<int,int>(i,j));
            else
                mvwaddch(this->windowPtr,i,j,this->getTerFromChar(j, i));
        }
    }

    for(auto V : gameItems){
        if(this->dungeonPtr->map[V.first][V.second].monster != nullptr){
            wattron(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[V.first][V.second].monster->color));
            mvwaddch(this->windowPtr, V.first,V.second,this->dungeonPtr->map[V.first][V.second].monster->symbol);
            wattroff(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[V.first][V.second].monster->color));
        }else{
            if(this->dungeonPtr->map[V.first][V.second].isItemInit){
                wattron(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[V.first][V.second].item->color));
                mvwaddch(this->windowPtr, V.first,V.second,this->dungeonPtr->map[V.first][V.second].item->symbol);
                wattroff(this->windowPtr, COLOR_PAIR(this->dungeonPtr->map[V.first][V.second].item->color));
            }
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
    this->updateMapByPixel(location[prev_x],location[prev_y]);
    if (teleport)
        mvwaddch(this->windowPtr,location[curr_y], location[curr_x],'*');
    else
        mvwaddch(this->windowPtr,location[curr_y], location[curr_x],'@');
            
    wrefresh(this->windowPtr);
}

void dungeonWindow::updateGameContent(location_t location) {
    this->updateMapByPixel(location[curr_x], location[curr_y]);
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


