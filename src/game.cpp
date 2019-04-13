//
// Created by chen_ on 2019/1/31.
//
#include <strings.h>
#include <ncurses.h>
#include <vector>
#include <unordered_map>
#include "../include/game.h"
#include "../include/Player.h"
#include "../include/GameCommon.h"
#include "../include/FileReader.h"
#include "../include/Display/Display.h"
#include "../include/utils/mapGenerator.h"
#include "../include/GameContant/ItemFactory.h"
#include "../include/GameContant/MonsterFactory.h"

//todo current status
//todo multiple stair support

Player game::pcPtr;
int currentLevel = 0;
std::vector<dungeon *> dungeonMap;
ItemFactory * itemFactory;
MonsterFactory * monsterFactoryPtr;
monsterController * game::monsterControllerPtr;

void game::close_dungeon(int mode){
    switch (mode)
    {
        case 1:
            Display::showDiedScreen();
            break;
        default:
            Display::closeDislaySystem();
            break;
    }

    //todo add free dungeonNap code
}

void game::startGame() {
    int time = 0;
    bool flag = true;
    bool fowFlag = false;
    bool teleportFlag = false;

    Display::initDisplayEnv();
    dungeon_t *currentDungeon = dungeonMap[0];
    Display::initDisplaySystem(currentDungeon);
    //update ALL Monster
    MonsterNode_t * tmpList = currentDungeon->monsterArray->nextNode;
    while(tmpList->monster != nullptr){
        Item item = itemFactory->generateNewGameContant(currentDungeon);
        Monster * monster = tmpList->monster;
        Display::updateGameContent(item.location,item.color,item.symbol);
        Display::updateGameContent(monster->location,monster->color,monster->symbol);
        tmpList = tmpList->nextNode;
    }
    



    while (flag) {
        while (time >= monsterControllerPtr->seeMinMonsterTime()) {
            Monster *monster = monsterControllerPtr->popMinMonster();
            monster->moveMonster(pcPtr.location);
            if (monster->meetWithPlayer(pcPtr.location)){
                flag = false;
                close_dungeon(1);
                return;
            }
            monsterControllerPtr->addSingleMonster(*monster, (uint32_t) (time + 1000 / monster->getSpeed()));
            Display::updateGameContent(monster->location,monster->color,monster->symbol);
        }

        reselect:

        time += pcPtr.getSpeed();
        switch (getch()) {
            case KEY_UP:
                if (pcPtr.movePC(Upper))
                    goto reselect;
                Display::updatePlayer(pcPtr.location);
                break;
            case KEY_DOWN:
                if (pcPtr.movePC(Down))
                    goto reselect;
                Display::updatePlayer(pcPtr.location);
                break;
            case KEY_RIGHT:
                if (pcPtr.movePC(Right))
                    goto reselect;
                Display::updatePlayer(pcPtr.location);
                break;
            case KEY_LEFT:
                if (pcPtr.movePC(Left))
                    goto reselect;
                Display::updatePlayer(pcPtr.location);
                break;
            case 'm':
                Display::showMonsterList();
                break;
            case 'f':
                Display::setFOWStatus(!fowFlag);
                fowFlag = ! fowFlag;
                break;
            case 't':
                Display::setTeleportStatus(!teleportFlag);
                teleportFlag = ! teleportFlag;
                break;
            case 'r':
                location_t location;
                if (teleportFlag) {
                    Display::setTeleportStatus(!teleportFlag);
                    teleportFlag = ! teleportFlag;

                    do{
                    location[curr_x] = rand()%DUNGEON_X;
                    location[curr_y] = rand()%DUNGEON_Y;
                    }while(pcPtr.setPcLocation(location) == 1);
                    Display::updatePlayer(pcPtr.location);
                }
                goto reselect;
        }
        // if (currentDungeon->map[pcPtr.currentLocation[dim_y]][pcPtr.currentLocation[dim_x]].terrain_type ==
        //     ter_stairs_up) {
        //     currentLevel++;

        //     if (currentLevel > dungeonMap.size())
        //         newDungeonLevel();

        //     //set current dungeon to next layer
        //     currentDungeon = dungeonMap[currentLevel];

        //     // //set new pc location to stairs
        //     pcPtr.setPcLocation(*currentDungeon->downStairs[0]);

        //     //update display dungeon ptr
        //     Display::updateDungeonMap(currentDungeon);
        // } else if (currentDungeon->map[pcPtr.currentLocation[dim_y]][pcPtr.currentLocation[dim_x]].terrain_type ==
        //            ter_stairs_up) {
        //     currentLevel--;

        //     if (currentLevel > dungeonMap.size())
        //         newDungeonLevel();

        //     //set current dungeon to next layer
        //     currentDungeon = dungeonMap[currentLevel];

        //     //set new pc location to stairs
        //     pcPtr.setPcLocation(*currentDungeon->upStairs[0]);

        //     //update display dungeon ptr
        //     Display::updateDungeonMap(currentDungeon);
        // }

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
    pcPtr = Player(dungeon);

    //initial Monster Controller
    monsterControllerPtr = new monsterController(dungeon);


    //inital ItemFactory
    itemFactory = new ItemFactory(io::FileReader::readConfigureFile("/.rlg327/object_desc.txt"));

    //initial MonserFactoty;
    monsterFactoryPtr = new MonsterFactory(io::FileReader::readConfigureFile("/.rlg327/monster_desc.txt"));

    //add 10 monster to dungeon
    for(int i = 0; i < 10; i++)
        monsterControllerPtr->addSingleMonster(monsterFactoryPtr->generateNewGameContant(dungeon),0);
    
    dungeon->monsterArray = monsterControllerPtr->currentNode;

    //initial dungeon array
    dungeonMap.push_back(dungeon);

    //set pc location to room[0]
    pcPtr.setPcLocation(dungeon->rooms[0]->position);


    //start game
    game::startGame();
}

