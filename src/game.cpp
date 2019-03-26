//
// Created by chen_ on 2019/1/31.
//
#include <stdlib.h>
#include <strings.h>
#include <ncurses.h>

#include "../include/game.h"
#include "../include/gameCommon.h"
#include "../include/characters/pc.h"
#include "../include/display/display.h"
#include "../include/utils/mapGenerator.h"

//todo current status
//todo multiple stair support

pc * game::pcPtr;
dungeon_t dungeon;
monsterController * game::monsterControllerPtr;

void game::start_new(){
    //generate dungeon
    mapGenerator::generate_dungon(&dungeon);

    //initial PC
    pcPtr = new pc(&dungeon,dungeon.rooms[0]->position);

    //initial Monster Controller
    monsterControllerPtr = new monsterController(&dungeon,pcPtr);

    //add 10 monster to dungeon
    monsterControllerPtr->addMonsterToQueue(10);
    
    //start game
    game::startGame();
}


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
}

void game::startGame(){
    int time = 0;
    bool flag = true;
    
    display::initDisplayEnv();
    display::initScreen(&dungeon,pcPtr,monsterControllerPtr->currentNode);

    while(flag){
        while(time >= monsterControllerPtr->popMinMonster().time){
            monster_t * current = popMinMonster(&monsterNode);
            if (moveMonster(current) == 1){
                flag = false;
                close_dungeon(1);
                goto end;
            }
            pushSingleMonster(&monsterNode, current, (uint32_t) (time + 1000 / current->speed));
        }

        reselect:
        switch (getch())
        {
            case KEY_UP:
                if(movePC(Upper,&npc))
                    goto reselect;
                updatePCLocation(screen,&npc);
                break;
            case KEY_DOWN:
                if(movePC(Down,&npc))
                    goto reselect;
                updatePCLocation(screen,&npc);
                break;
            case KEY_RIGHT:
                if(movePC(Right,&npc))
                    goto reselect;
                updatePCLocation(screen,&npc);
                break;
            case KEY_LEFT:
                if(movePC(Left,&npc))
                    goto reselect;
                updatePCLocation(screen,&npc);
                break;
            case 'm':
                showMonsterList(screen,&monsterNode);
                break;
            default:
                goto reselect;
                break;
        }
        if ((dungeon.map[npc.location[dim_y]][npc.location[dim_x]] == ter_stairs_up) ||
            (dungeon.map[npc.location[dim_y]][npc.location[dim_x]] == ter_stairs_up) ){
            bzero(&dungeon,sizeof(dungeon_t));
            //TODO may leak memory need imrove
            bzero(&monsterNode, sizeof(monsterNode_t));

            generate_dungon(&dungeon);

            //initial npc location
            npc.dungeon = &dungeon;
            bzero(&npc.prevLocation, sizeof(pair_t));
            npc.location[dim_x] = dungeon.rooms[0].position[dim_x];
            npc.location[dim_y] = dungeon.rooms[0].position[dim_y];

            //generate monster
            pushMonsterToQueue(10,&dungeon,&npc,&monsterNode);
            
            updateDungeonScreen(screen,&dungeon);
        time += 10;
    }
    end:

    return;
}


