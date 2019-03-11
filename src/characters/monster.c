//
// Created by 陈瀚泽 on 2019-02-26.
//

#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#include "dungeon_gen_path.h"
#include "../../include/characters/monster.h"
#include "macros.h"
#include "game.h"

void newMonster(dungeon_t *dungeon,pc_t *pc,monster_t * monster){
    bzero(monster, sizeof(monster_t));

    monster->pc = pc;
    monster->dungeon = dungeon;
    monster->range = (uint8_t) (rand() % 3);
    monster->speed = (uint8_t) (rand()%16 + 5);
    monster->characteristics = (uint8_t) (rand() % 16);
}

bool meetWithPc(monster_t * monster){
    for (int i = -1 * monster->range; i < monster->range + 1 ; ++i) {
        for (int j = -1 * monster->range; j < monster->range + 1 ; ++j) {
            uint8_t x = (uint8_t) (monster->location[dim_x] + i);
            uint8_t y = (uint8_t) (monster->location[dim_y] + j);

            if (checkLocation(x,y)){
                if ((x == monster->pc->location[dim_x]) && (y == monster->pc->location[dim_y])){
                    monster->lastPcLocation[dim_y] = y;
                    monster->lastPcLocation[dim_x] = x;
                    return true;
                }
            }
        }
    }
    return false;
}

int moveMonster(monster_t * monster){
    srand(time(NULL));

    pair_t nextParh;
    corridor_node_t path[DUNGEON_Y][DUNGEON_X];

    if (monster->characteristics & 0x1){
        bool flag = true;
        if ((rand() % 2 ) == 1){
            while(flag){
                int x = monster->location[dim_x] + rand()%3 - 1;
                int y = monster->location[dim_y] + rand()%3 - 1;
                if (checkLocation(x,y)){
                    if ((monster->dungeon->map[y][x] == ter_floor_room) ||
                        (monster->dungeon->map[y][x] == ter_floor_hall))
                    {
                        flag = false;
                        nextParh[dim_y] = (int16_t) y;
                        nextParh[dim_x] = (int16_t) x;
                    }
                }
            }
            goto update;
        }
    }

    if (monster->characteristics & 0x4){
        if(monster->characteristics & 0x8){
            if(monster->characteristics & 0x2){
                if (monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] == 0){
                    dijkstra_tunnelling(monster->dungeon,monster->pc->location,monster);
                    nextParh[dim_x] = monsterNext(monster)->pos[dim_x];
                    nextParh[dim_y] = monsterNext(monster)->pos[dim_y];
                    goto update;
                } else{
                    if (monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] <= 85)
                        monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] = 0;
                    else{
                        monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] -= 85;
                    }
                    return 0;
                }
            }else{
                dijkstra_no_tunnelling(monster->dungeon,monster->pc->location,monster);
                nextParh[dim_x] = monsterNext(monster)->pos[dim_x];
                nextParh[dim_y] = monsterNext(monster)->pos[dim_y];
                goto update;
            }
        }else{
            double shortestDistance = UINT32_MAX;
            for (int i = -1; i <2 ; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int16_t y = (int16_t) (monster->location[dim_y] + j);
                    int16_t x = (int16_t) (monster->location[dim_x] + i);
                    if (checkLocation(x,y)){
                        double distance = sqrt(abs(monster->location[dim_y] + j - monster->pc->location[dim_y])) +
                                            sqrt(abs(monster->location[dim_x] + i - monster->pc->location[dim_x]));
                        if (distance < shortestDistance){
                            shortestDistance = distance;
                            nextParh[dim_x] = x;
                            nextParh[dim_y] = y;
                        }
                    }
                }
            }
            goto update;
        }
    } else if (meetWithPc(monster)){
        if(monster->characteristics & 0x8){
            if(monster->characteristics & 0x2){
                if (monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] == 0){
                    dijkstra_tunnelling(monster->dungeon,monster->pc->location,monster);
                    nextParh[dim_x] = monsterNext(monster)->pos[dim_x];
                    nextParh[dim_y] = monsterNext(monster)->pos[dim_y];
                    goto update;
                } else{
                    if (monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] <= 85)
                        monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] = 0;
                    else{
                        monster->dungeon->hardness[monster->location[dim_y]][monster->location[dim_x]] -= 85;
                    }
                    return 0;
                }
            }else{
                dijkstra_no_tunnelling(monster->dungeon,monster->lastPcLocation,monster);
                nextParh[dim_x] = monsterNext(monster)->pos[dim_x];
                nextParh[dim_y] = monsterNext(monster)->pos[dim_y];
                goto update;
            }
        } else
            return 0;
    } else
        return 0;

    update:
    monster->dungeon->character[monster->location[dim_y]][monster->location[dim_x]] = ' ';

    if (monster->dungeon->character[nextParh[dim_y]][nextParh[dim_x]] != '@'){
        monster->location[dim_x] = nextParh[dim_x];
        monster->location[dim_y] = nextParh[dim_y];
    } else
        return 1;


    monster->dungeon->character[monster->location[dim_y]][monster->location[dim_x]] = 'D';
    return 0;
}
