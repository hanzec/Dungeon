
//
// Created by 陈瀚泽 on 2019-02-27.
//

#include <strings.h>
#include <stdlib.h>
#include "MonsterController.h"
#include "monster.h"
#include "gameCommon.h"

void pushSingleMonster(monsterNode_t * monsterNode, monster_t * monster, uint32_t weight){
    monsterNode_t * nextMonster = malloc(sizeof(monsterNode_t));

    bzero(nextMonster,sizeof(monsterNode_t));
    nextMonster->prevNode = NULL;
    nextMonster->nextNode = NULL;
    nextMonster->monster = monster;
    nextMonster->time = (uint32_t) (1000 / monster->speed) + weight;

    if (monsterNode->nextNode == NULL) {
        monsterNode_t * endNode = malloc(sizeof(monsterNode_t));

        endNode->nextNode = NULL;
        endNode->monster = NULL;
        endNode->time = UINT32_MAX;
        endNode->prevNode = nextMonster;

        monsterNode->nextNode = nextMonster;
        nextMonster->nextNode = endNode;
        nextMonster->prevNode = monsterNode;
    } else{
        monsterNode_t * current = monsterNode;

        while(current != NULL){
            if (nextMonster->time < current->time){
                current->prevNode->nextNode = nextMonster;
                nextMonster->prevNode = current->prevNode;
                current->prevNode = nextMonster;
                nextMonster->nextNode = current;
                break;
            }
            current = current->nextNode;
        }

    }
}
monster_t * popMinMonster(monsterNode_t * monsterNode){
    if (monsterNode == NULL){
        return NULL;
    }
    monsterNode_t * removeNode = monsterNode->nextNode;
    monster_t * monster = removeNode->monster;
    monsterNode->nextNode = removeNode->nextNode;
    removeNode->nextNode->prevNode = monsterNode;

    free(removeNode);
    return monster;
}

monsterNode_t * seeFrontMonsterNode(monsterNode_t * monsterNode){
    return monsterNode->nextNode;
}

void cleanMonsterQueue(monsterNode_t * monsterNode) {
    while (monsterNode != NULL){
        free(monsterNode->monster);
        monsterNode = monsterNode->nextNode;
    }
}

void pushMonsterToQueue(uint32_t number, dungeon_t * dungeon, pc_t * pc , monsterNode_t * monsterNode){

    for (int i = 0; i < number; ++i){
        monster_t * monster = malloc(sizeof(monster_t));
        newMonster(dungeon,pc,monster);
        room_t tmp = dungeon->rooms[rand()%dungeon->num_rooms];
        monster->location[dim_y] = (uint16_t) (tmp.position[dim_y] + rand() % tmp.size[dim_y]);
        monster->location[dim_x] = (uint16_t) (tmp.position[dim_x] + rand() % tmp.size[dim_x]);

        pushSingleMonster(monsterNode, monster,0);
    }
}

int getNumberOfMonster(monsterNode_t monsterNode){
    int number = 0;

    while (monsterNode.nextNode != NULL){
        number += 1;
        monsterNode = * monsterNode.nextNode;
    }
    return number - 1;
}