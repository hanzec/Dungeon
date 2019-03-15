//
// Created by chen_ on 2019/1/31.
//
#include <stdlib.h>
#include <strings.h>
#include <ncurses.h>
#include "../include/characters/charactersCommon.h"
#include "../include/gameCommon.h"
#include "../include/display/display.h"

//todo current status
//todo multiple stair support

npc_t pc;
dungeon_t dungeon;
baseScreen_t * screen;
monsterNode_t monsterNode;

void start_new(){
    //generate dungeon
    generate_dungon(&dungeon);
    bzero(&monsterNode,sizeof(monsterNode_t));

    //initial npc location
    npc.dungeon = &dungeon;
    bzero(&npc.prevLocation, sizeof(pair_t));
    npc.location[dim_x] = dungeon.rooms[0].position[dim_x];
    npc.location[dim_y] = dungeon.rooms[0].position[dim_y];

    //generate monster
    pushMonsterToQueue(10,&dungeon,&npc,&monsterNode);
    
    //start game
    startGame(&dungeon,&monsterNode,&npc);
}


void close_dungeon(int mode){
    switch (mode)
    {
        case 1:
            showDiedScreen(screen);
            break;
        default:
            endwin();
            closeScreen(screen);
            break;
    }
    return;
}

void startGame(){
    int time = 0;
    bool flag = true;
    
    initDisplayEnv();
    screen = initScreen(&dungeon,&npc,monsterNode);

    while(flag){
        while(time >= seeFrontMonsterNode(&monsterNode)->time){
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


