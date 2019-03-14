//
// Created by chen_ on 2019/1/31.
//
#include "gameCommon.h"
#include "charactersCommon.h"

#ifndef DUNGEON_V1_01_GAME_H
#define DUNGEON_V1_01_GAME_H


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

void start_new();
void startGame();
void close_dungeon(int mode);


#endif //DUNGEON_V1_01_GAME_H
