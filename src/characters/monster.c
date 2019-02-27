//
// Created by 陈瀚泽 on 2019-02-26.
//

#include <stdlib.h>
#include <strings.h>
#include "monster.h"

monster_t * newMonster(dungeon_t *dungeon, pc_t *pc){
    srand(time(NULL));
    monster_t monster;
    bzero(&monster, sizeof(monster_t));

    monster.pc = pc;
    monster.dungeon = dungeon;
    monster.speed = (uint8_t) (rand()%16 + 5);
    monster.characteristics = (uint8_t) (rand() % 16);

    return &monster;
}

void specialIntelligence(monster_t *monster) {

}

void specialTelepathy(monster_t * monster){

}
void specialTunneling(monster_t * monster){}

void specialErratic(monster_t * monster){}

void meetWithPc(monster_t * monster){
    for (int i = -1 * monster->range; i < MONSTER_RANGE + 1 ; ++i) {
        for (int j = -1 * monster->range; j < MONSTER_RANGE + 1 ; ++j) {
            uint8_t x = (uint8_t) (monster->location[dim_x] + i);
            uint8_t y = (uint8_t) (monster->location[dim_y] + j);

            if ((x > 0 && x < DUNGEON_X) && (y > 0 && y < DUNGEON_Y)){
                if ((x == monster->pc->location[dim_x]) && (y == monster->pc->location[dim_y])){
                    monster->lastPcLocation[dim_y] = y;
                    monster->lastPcLocation[dim_x] = x;
                }
            }
        }
    }
}
void move(monster_t * monster){
    meetWithPc(monster);

    if(monster->characteristics & 0x1)
        specialErratic(monster);
    else{
        if (IS_MONSTER_SEEN_PC){
            for (int i = -1; i < 1; ++i) {

            }
        }
    }

    if(monster->characteristics & 0x2)
        specialTunneling(monster);
    if(monster->characteristics & 0x4)
        specialTelepathy(monster);
    if(monster->characteristics & 0x8)
        specialIntelligence(monster);
}
