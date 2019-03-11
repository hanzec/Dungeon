//
// Created by chen_ on 2019/1/31.
//
#ifndef DUNGEON_V1_01_GAME_H
#define DUNGEON_V1_01_GAME_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "gameCommon.h"

/* Returns true if random float in [0,1] is less than *
 * numerator/denominator.  Uses only integer math.    */
# define rand_under(numerator, denominator) \
  (rand() < ((RAND_MAX / denominator) * numerator))

/* Returns random integer in [min, max]. */
# define rand_range(min, max) ((rand() % (((max) + 1) - (min))) + (min))

/*#define malloc(size) ({        \
  void *_tmp;                  \
  assert(_tmp = malloc(size)); \
  _tmp;                        \
})*/

dungeon_t* dump_dungeon();
void start_new(bool cli_mode);
void close_dungeon(bool cli_mode);
void load_dungeon(bool cli_mode);

#endif //DUNGEON_V1_01_GAME_H
