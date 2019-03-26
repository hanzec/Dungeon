

#include <cstdlib> 
#include <cstring>
#include "../../include/utils/MonsterController.h"

int monsterController::getNumberOfMonster(){return this->numberOfMonster;}

monsterController::monsterController(dungeon_t *dungeon, class pc *pc) {
    this->dungeon = dungeon;
    this->pc = pc;
}
void monsterController::addSingleMonster(monster * monster, int weight){

    monsterNode_t * nextMonster = (monsterNode_t *)malloc(sizeof(monsterNode_t));
    
    nextMonster->prevNode = nullptr;
    nextMonster->nextNode = nullptr;
    nextMonster->monster = monster;
    nextMonster->time = (uint32_t) (1000 / monster->getSpeed() + weight);

    if (this->currentNode->nextNode == NULL) {
        monsterNode_t * endNode = (monsterNode_t *)malloc(sizeof(monsterNode_t));

        endNode->nextNode = NULL;
        endNode->monster = NULL;
        endNode->time = UINT32_MAX;
        endNode->prevNode = nextMonster;

        nextMonster->nextNode = endNode;
        nextMonster->prevNode = this->currentNode;
        this->currentNode->nextNode = nextMonster;
    } else{
        monsterNode_t * current = this->currentNode;

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

    this->numberOfMonster += 1;
}
monster * monsterController::popMinMonster(){
    if (this->currentNode == NULL){
        return NULL;
    }
    monsterNode_t * removeNode = this->currentNode->nextNode;
    monster* monster = removeNode->monster;
    this->currentNode->nextNode = removeNode;
    removeNode->nextNode->prevNode = this->currentNode;
    this->numberOfMonster -= 1;
    free(removeNode);
    return monster;
}

void monsterController::cleanMonsterQueue() {
    while (this->currentNode != NULL){
        free(this->currentNode->monster);
        this->currentNode = this->currentNode->nextNode;
    }
    this->numberOfMonster = 0;
}

void monsterController::addMonsterToQueue(uint32_t number){

    for (int i = 0; i < number; ++i){
        monster * monster = new class monster(dungeon,pc);
        room_t tmp = * dungeon->rooms[rand()%dungeon->num_rooms];
        monster->currentLocation[dim_y] = (uint16_t) (tmp.position[dim_y] + rand() % tmp.size[dim_y]);
        monster->currentLocation[dim_x] = (uint16_t) (tmp.position[dim_x] + rand() % tmp.size[dim_x]);

        this->addSingleMonster(monster,0);
    }
}