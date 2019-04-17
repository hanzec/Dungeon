#include <queue>
#include "../../include/Utils/DungeonUtils.h"

void DungeonUtils::OrderedList::push(std::list<std::shared_ptr<Monster> > * monsters, std::shared_ptr<Monster> monster){
    for ( auto i = monsters->begin(); i != monsters->end(); i++){
        if(i->get()->nextMoveTime > monster->nextMoveTime){
            monsters->insert(i,monster);
            return;
        }
    }
    monsters->push_back(monster);
}

std::shared_ptr<Monster> DungeonUtils::OrderedList::pop_min(std::list<std::shared_ptr<Monster> > * monsters){ 
    std::shared_ptr<Monster> result = monsters->front();
    monsters->pop_front();
    return result;
}

void DungeonUtils::Path::dijkstra_no_tunnelling(dungeon_t *dungeon, location_t playerLocation){

    corridor_node_t *prev_node;
    std::list<corridor_node_t *> heap;

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            dungeon->nontunnel[y][x].pos[curr_y] = y;
            dungeon->nontunnel[y][x].pos[curr_y] = y;
            dungeon->nontunnel[y][x].cost = INT32_MAX;
        }
    }

    dungeon->nontunnel[playerLocation[curr_y]][playerLocation[curr_x]].cost = 0;
    heap.push_front(&dungeon->nontunnel[playerLocation[curr_y]][playerLocation[curr_x]]);

    while (heap.size() != 0){
        prev_node = (corridor_node_t *) heap.front();
        heap.pop_front();
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[curr_x];
                uint16_t y = i + prev_node->pos[curr_y];
                if (checkLocation(x,y)){
                    if (dungeon->map[y][x].terrain_type != ter_wall){
                        if (prev_node->cost + 1 < dungeon->nontunnel[y][x].cost){
                            dungeon->nontunnel[y][x].prev_node = prev_node;
                            dungeon->nontunnel[y][x].cost = prev_node->cost + 1;
                            heap.push_front(&dungeon->nontunnel[y][x]);
                        }
                    }
                }
            }
        }
    }
}

void DungeonUtils::Path::dijkstra_tunnelling(dungeon_t *dungeon, location_t playerLocation){

    corridor_node_t *prev_node;
    std::list<corridor_node_t *> heap;

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            dungeon->tunnel[y][x].pos[curr_y] = y;
            dungeon->tunnel[y][x].pos[curr_y] = y;
            dungeon->tunnel[y][x].cost = INT32_MAX;
        }
    }

    dungeon->tunnel[playerLocation[curr_y]][playerLocation[curr_x]].cost = 0;
    heap.push_front(&dungeon->tunnel[playerLocation[curr_y]][playerLocation[curr_x]]);

    while (heap.size() != 0){
        prev_node = (corridor_node_t *) heap.front();
        heap.pop_front();
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[curr_x];
                uint16_t y = i + prev_node->pos[curr_y];

                if (checkLocation(x,y)){
                    int weight_tmp = 0;

                    if (dungeon->map[y][x].terrain_type == ter_wall_immutable)
                        break;

                    if (dungeon->map[y][x].hardness == 0){
                        weight_tmp = 1 + prev_node->cost;
                    }else{
                        weight_tmp = 1 + (dungeon->map[y][x].hardness/85) + prev_node->cost;
                    }

                    if (weight_tmp < dungeon->tunnel[y][x].cost){
                        dungeon->tunnel[y][x].cost = weight_tmp;
                        dungeon->tunnel[y][x].prev_node = prev_node;
                        heap.push_front(&dungeon->tunnel[y][x]);
                    }
                }
            }
        }
    }
}

