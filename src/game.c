//
// Created by chen_ on 2019/1/31.
//
#include <stdlib.h>
#include <strings.h>
#include <ncurses.h>
#include "game.h"
#include "display.h"
#include "dungeon_utils.h"
#include "dungeon_gen_map.h"
#include "MonsterController.h"
#include "monster.h"
#include "pc.h"
//todo current status
//todo multiple stair support

pc_t pc;
dungeon_t dungeon;
baseScreen_t * screen;
monsterNode_t monsterNode;

void start_new(){
    //generate dungeon
    generate_dungon(&dungeon);
    bzero(&monsterNode,sizeof(monsterNode_t));

    //initial pc location
    pc.dungeon = &dungeon;
    bzero(&pc.prevLocation, sizeof(pair_t));
    pc.location[dim_x] = dungeon.rooms[0].position[dim_x];
    pc.location[dim_y] = dungeon.rooms[0].position[dim_y];

    //generate monster
    pushMonsterToQueue(10,&dungeon,&pc,&monsterNode);
    
    //start game
    startGame(&dungeon,&monsterNode,&pc);
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
    screen = initScreen(&dungeon,&pc,monsterNode);

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
                if(movePC(Upper,&pc))
                    goto reselect;
                updatePCLocation(screen,&pc);
                break;
            case KEY_DOWN:
                if(movePC(Down,&pc))
                    goto reselect;
                updatePCLocation(screen,&pc);
                break;
            case KEY_RIGHT:
                if(movePC(Right,&pc))
                    goto reselect;
                updatePCLocation(screen,&pc);
                break;
            case KEY_LEFT:
                if(movePC(Left,&pc))
                    goto reselect;
                updatePCLocation(screen,&pc);
                break;
            case 'm':
                showMonsterList(screen,&monsterNode);
                break;
            default:
                goto reselect;
                break;
        }
        if ((dungeon.map[pc.location[dim_y]][pc.location[dim_x]] == ter_stairs_up) ||
            (dungeon.map[pc.location[dim_y]][pc.location[dim_x]] == ter_stairs_up) ){
            bzero(&dungeon,sizeof(dungeon_t));
            //TODO may leak memory need imrove
            bzero(&monsterNode, sizeof(monsterNode_t));

            generate_dungon(&dungeon);

            //initial pc location
            pc.dungeon = &dungeon;
            bzero(&pc.prevLocation, sizeof(pair_t));
            pc.location[dim_x] = dungeon.rooms[0].position[dim_x];
            pc.location[dim_y] = dungeon.rooms[0].position[dim_y];

            //generate monster
            pushMonsterToQueue(10,&dungeon,&pc,&monsterNode);
            
            updateDungeonScreen(screen,&dungeon);
        time += 10;
    }
    end:

    return;
}


