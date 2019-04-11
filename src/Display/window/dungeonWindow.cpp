//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <ncurses.h>
#include "../../../include/Map.h"
#include "../../../include/Display/displayCommon.h"
#include "../../../include/Display/window/dungeonWindow.h"

void dungeonWindow::setFOWStatus(bool flag){ 
    this->fow = flag;
    dungeonWindow::updateMap();
    dungeonWindow::updatePlayer(); 
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


int dungeonWindow::updatePlayer() {
   //set map to visable
    for(int i = -1; i <2 ; i++){
        for(int j = -1; j < 2; j++){
            this->dungeonPtr->map[Map::getPlayerLocation()[dim_x] + i][Map::getPlayerLocation()[dim_y] + j].visable = true;
            if (fow)
                dungeonWindow::updateMapByPixel(Map::getPlayerLocation()[dim_x] + i,Map::getPlayerLocation()[dim_y] + j);
        }  
    }
    //update pc location
    mvwaddch(this->windowPtr,
             Map::getPlayerLocation()[dim_y],
             Map::getPlayerLocation()[dim_x],
             this->getTerFromChar(Map::getPlayerLocation()[dim_x],Map::getPlayerLocation()[dim_y])
             );
    if (teleport)
        mvwaddch(this->windowPtr,Map::getPlayerLocation()[dim_y], Map::getPlayerLocation()[dim_x],'*');
    else
        mvwaddch(this->windowPtr,Map::getPlayerLocation()[dim_y], Map::getPlayerLocation()[dim_x],'@');
            
    wrefresh(this->windowPtr);
    return 0;
}

int dungeonWindow::updateGameItem(int gameItemID) {
   if (Map::getPrevLocation(gameItemID)[dim_x] != 0 && Map::getPrevLocation(gameItemID)[dim_x] != 0) {
       mvwaddch(this->windowPtr,
                 Map::getPrevLocation(gameItemID)[dim_x],
                 Map::getPrevLocation(gameItemID)[dim_y],
                 this->getTerFromChar(Map::getPrevLocation(gameItemID)[dim_x],
                                      Map::getPrevLocation(gameItemID)[dim_y]));
   }
    //TODO for mutiple color for simgle monster support
    attron(COLOR_PAIR(Map::getGameItemColor(gameItemID)));
    mvwaddch(this->windowPtr,Map::getPrevLocation(gameItemID)[dim_y], 
                             Map::getPrevLocation(gameItemID)[dim_x],
                             Map::getGameItemSymbol(gameItemID));
    attroff(COLOR_PAIR(Map::getGameItemColor(gameItemID)));
    
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


