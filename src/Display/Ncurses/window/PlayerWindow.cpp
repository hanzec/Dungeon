//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <curses.h>


#include "Player.h"
#include "GameCommon.h"
#include "PlayerWindow.h"
#include "../displayCommon.h"



PlayerWindow::PlayerWindow(shared_ptr<Player> player) 
    :CursesWindow("PLAYER_WINDOW", PLAYER_WINDOW_HEIGHT, PLAYER_WINDOW_LENGTH, PLAYER_WINDOW_Y, PLAYER_WINDOW_X){
    
    this->playerPtr = player;

    wbkgd(this->windowPtr,COLOR_PAIR(PAIR_CHARACTER_STATUS));
}

void PlayerWindow::onUpdate(){
    mvwprintw(this->windowPtr, 0, 0, "HP:    %6d", playerPtr->getHealthPoint());
    mvwprintw(this->windowPtr, 1, 0, "Damage:%6d", playerPtr->getDamagePoint());
    mvwprintw(this->windowPtr, 0, 14, "Weight:%6d", playerPtr->getWeight());
}

void PlayerWindow::onResizeWindow(int scaleX, int scaleY){
    
}