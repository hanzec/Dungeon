//
// Created by chen_ on 2019/1/31.
//
#include <stdlib.h>
#include <strings.h>
#include <ncurses.h>

#include "../include/game.h"
#include "../include/gameCommon.h"
#include "../include/GameContant/Pc.h"
#include "../include/display/display.h"
#include "../include/utils/mapGenerator.h"

//todo current status
//todo multiple stair support

Pc game::pcPtr;
int currentLevel = 0;
std::vector<dungeon *> dungeonMap;
monsterController game::monsterControllerPtr;

void game::close_dungeon(int mode){
    switch (mode)
    {
        case 1:
            display::showDiedScreen();
            break;
        default:
            display::closeScreen();
            break;
    }

    //todo add free dungeonNap code
}

void game::startGame() {
    int time = 0;
    bool flag = true;
    bool fowFlag = false;
    bool teleportFlag = false;

    display::initDisplayEnv();
    dungeon_t *currentDungeon = dungeonMap[0];
    display::initScreen(currentDungeon, &pcPtr);

    while (flag) {
        while (time >= monsterControllerPtr.seeMinMonsterTime()) {
            Monster *monster = monsterControllerPtr.popMinMonster();
            monster->moveMonster();
            if (monster->meetWithNPC()) {
                flag = false;
                close_dungeon(1);
                return;
            }
            monsterControllerPtr.addSingleMonster(monster, (uint32_t) (time + 1000 / monster->getSpeed()));
        }

        reselect:
        switch (getch()) {
            case KEY_UP:
                if (pcPtr.movePC(Upper))
                    goto reselect;
                display::updatePCLocation();
                break;
            case KEY_DOWN:
                if (pcPtr.movePC(Down))
                    goto reselect;
                display::updatePCLocation();
                break;
            case KEY_RIGHT:
                if (pcPtr.movePC(Right))
                    goto reselect;
                display::updatePCLocation();
                break;
            case KEY_LEFT:
                if (pcPtr.movePC(Left))
                    goto reselect;
                display::updatePCLocation();
                break;
            case 'm':
                display::showMonsterList();
                break;
            case 'f':
                display::setFOWStatus(!fowFlag);
                fowFlag = ! fowFlag;
                break;
            case 't':
                display::setTeleportStatus(!teleportFlag);
                teleportFlag = ! teleportFlag;
                break;
            case 'r':
                pair_t location;
                if (teleportFlag) {
                    display::setTeleportStatus(!teleportFlag);
                    teleportFlag = ! teleportFlag;

                    do{
                    location[dim_x] = rand()%DUNGEON_X;
                    location[dim_y] = rand()%DUNGEON_Y;
                    }while(pcPtr.setPcLocation(location) == 1);
                    display::updatePCLocation();
                }
                goto reselect;
            default:
                goto reselect;
        }
        if (currentDungeon->map[pcPtr.currentLocation[dim_y]][pcPtr.currentLocation[dim_x]].terrain_type ==
            ter_stairs_up) {
            currentLevel++;

            if (currentLevel > dungeonMap.size())
                newDungeonLevel();

            //set current dungeon to next layer
            currentDungeon = dungeonMap[currentLevel];

            //set new pc location to stairs
            printf("%d",currentDungeon->downStairs.size());
            pcPtr.setPcLocation(*currentDungeon->downStairs[0]);

            //update display dungeon ptr
            display::updateDungeonMap(currentDungeon);
        } else if (currentDungeon->map[pcPtr.currentLocation[dim_y]][pcPtr.currentLocation[dim_x]].terrain_type ==
                   ter_stairs_up) {
            currentLevel--;

            if (currentLevel > dungeonMap.size())
                newDungeonLevel();

            //set current dungeon to next layer
            currentDungeon = dungeonMap[currentLevel];

            //set new pc location to stairs
            pcPtr.setPcLocation(*currentDungeon->upStairs[0]);

            //update display dungeon ptr
            display::updateDungeonMap(currentDungeon);
        }

    }
}

void game::newDungeonLevel() {

    //generate new layer of dungeon
    auto * dungeon = new dungeon_t;
    mapGenerator::generate_dungon(dungeon);

    //push dungeon to vector
    dungeonMap.push_back(dungeon);
}

void game::newGame(){

    //generate dungeon
    auto * dungeon = new dungeon_t;
    mapGenerator::generate_dungon(dungeon);

    //initial PC
    pcPtr = Pc(dungeon);

    //initial Monster Controller
    monsterControllerPtr = monsterController(dungeon,&pcPtr);

    //add 10 monster to dungeon
    monsterControllerPtr.addMonsterToQueue(10);
    dungeon->monsterArray = monsterControllerPtr.currentNode;

    //initial dungeon array
    dungeonMap.push_back(dungeon);

    //set pc location to room[0]
    pcPtr.setPcLocation(dungeon->rooms[0]->position);

    //start game
    game::startGame();
}

