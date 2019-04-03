#include <cstdlib> 
#include <cstring>
#include <climits>
#include "../../include/utils/MonsterController.h"

int monsterController::getNumberOfMonster(){return this->numberOfMonster;}

int monsterController::seeMinMonsterTime(){ return this->currentNode->nextNode->time;}

monsterController::monsterController(dungeon_t *dungeon, Pc * user) {
    this->user = user;
    this->dungeon = dungeon;
    this->currentNode = nullptr;
}
void monsterController::addSingleMonster(Monster * monster, int weight){

    auto * nextMonster = (MonsterNode_t *)malloc(sizeof(MonsterNode_t));

    nextMonster->monster = monster;
    nextMonster->nextNode = nullptr;
    nextMonster->time = (uint32_t) (1000 / monster->getSpeed() + weight);

    if (this->currentNode == nullptr) {
        currentNode = new MonsterNode;
        auto * endNode = new MonsterNode;

        endNode->time = INT_MAX;
        endNode->monster = nullptr;
        endNode->nextNode = nullptr;
        endNode->prevNode = nextMonster;

        currentNode->prevNode = nullptr;
        currentNode->nextNode = nextMonster;

        nextMonster->nextNode = endNode;
        nextMonster->prevNode = currentNode;
    } else{
        MonsterNode_t * current = this->currentNode;

        while(current->nextNode != NULL){
            if (nextMonster->time < current->time){
                nextMonster->prevNode = current->prevNode;
                current->prevNode->nextNode = nextMonster;

                nextMonster->nextNode = current;
                current->prevNode = nextMonster;
                break;
            }
            current = current->nextNode;
        }

    }

    this->numberOfMonster += 1;
}
Monster * monsterController::popMinMonster(){
    if (this->currentNode == NULL){
        return NULL;
    }
    MonsterNode_t * removeNode = this->currentNode->nextNode;
    Monster* monster = removeNode->monster;
    this->currentNode->nextNode = removeNode->nextNode;
    removeNode->nextNode->prevNode = this->currentNode;
    this->numberOfMonster -= 1;
    //free(removeNode);
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
        Monster * monster = new class Monster(this->dungeon,this->user);
        room_t tmp = * dungeon->rooms[rand()%dungeon->num_rooms];
        monster->currentLocation[dim_y] = (uint16_t) (tmp.position[dim_y] + rand() % tmp.size[dim_y]);
        monster->currentLocation[dim_x] = (uint16_t) (tmp.position[dim_x] + rand() % tmp.size[dim_x]);

        this->addSingleMonster(monster,0);
    }
}