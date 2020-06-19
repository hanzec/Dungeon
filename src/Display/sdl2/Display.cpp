//
// Created by 陈瀚泽 on 2019-03-14.
//d

#include "SDL/SDL.h"
#include "Display.h"

dungeon_t * Display::dungeonPtr;
monsterList * Display::monsterListPtr;
AbstractWindow * Display::windowStack[num_windows];

//***************************************************************************************
//
//! \file Display.c
//! This is the Control interface for SDL2 Display implementation
//!
//! \author    HANZE CHEN
//! \version   V0.1
//! \date      2020-6-5
//! \copyright GNU Public License V3.0
//
//***************************************************************************************

int Display::initDisplayEnv() {

}

int Display::initDisplaySystem(dungeon_t *dungeon) {

    return 0;
}

int Display::closeDislaySystem() {
    return 0;
}

int Display::showDiedScreen() {

    mvaddstr(0,0,tombstone);
    refresh();
    getch();
    return 0;
}

int Display::showMonsterList() {
    monsterListPtr->updatePanel();
    monsterListPtr->displayPanel();

    //wait for user press any key
    getch();
    monsterListPtr->hidePanel();
    return 0;
}

void Display::updateDungeonMap() {
    monsterListPtr->updateMonsterNode(&Display::dungeonPtr->monsters);
}

void Display::setFOWStatus(bool flag){
    ((dungeonWindow *)windowStack[dungeonScreen_win])->setFOWStatus(flag);
}

void Display::setTeleportStatus(bool flag){
    ((dungeonWindow *)windowStack[dungeonScreen_win])->setTeleportStatus(flag);
}

void Display::updatePlayer(location_t location) {
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updatePlayer(location);
}

void Display::updateGameContent(location_t location){
    ((dungeonWindow *)windowStack[dungeonScreen_win])->updateGameContent(location);
}

Display::Display(dungeon_t *dungeon) {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        throw std::runtime_error(SDL_GetError());
}

Display::~Display() {

    SDL_Quit();
}
