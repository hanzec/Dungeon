//
// Created by 陈瀚泽 on 2019-02-26.
//

#ifndef DUNGEON_COMS327_F19_MONSTER_H
#define DUNGEON_COMS327_F19_MONSTER_H

typedef enum characteristics{
    char_eratic,
    char_telepathy,
    char_tunneling,
    char_intelligence
} characteristics_t;

typedef struct monster{
    uint8_t speed;
    pair_t location;
    uint8_t special;
};
#endif //DUNGEON_COMS327_F19_MONSTER_H
