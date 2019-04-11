//
// Created by chen_ on 2019/1/31.
//
#include "Player.h"
#include "GameCommon.h"
#include "utils/MonsterController.h"

#ifndef DUNGEON_V1_01_GAME_H
#define DUNGEON_V1_01_GAME_H


class game{
public:
    static void startGame();
    static void newGame();
private:
    static Player pcPtr;
    static void newDungeonLevel();
    static void close_dungeon(int mode);
    static monsterController * monsterControllerPtr;
};


#endif //DUNGEON_V1_01_GAME_H
