//
// Created by chen_ on 2019/1/31.
//

#ifndef COMS327_S19_DUNGEON_DUNGEON_MAP_GENERATE_H
#define COMS327_S19_DUNGEON_DUNGEON_MAP_GENERATE_H

#include "../gameCommon.h"
#include "data_stucture/heap.h"

/* Returns true if random float in [0,1] is less than *
 * numerator/denominator.  Uses only integer math.    */
# define rand_under(numerator, denominator) \
  (rand() < ((RAND_MAX / denominator) * numerator))

/* Returns random integer in [min, max]. */
# define rand_range(min, max) ((rand() % (((max) + 1) - (min))) + (min))

typedef struct corridor_path {
    heap_node_t *hn;
    uint8_t pos[2];
    uint8_t from[2];
    int32_t cost;
} corridor_path_t;

class mapGenerator
{
private:
 mapGenerator();
~mapGenerator();
public:
static int connect_rooms(dungeon_t *d);
static void generate_dungon(dungeon_t *dunegeon);
};



#endif //COMS327_S19_DUNGEON_DUNGEON_MAP_GENERATE_H
