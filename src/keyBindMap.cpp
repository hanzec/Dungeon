//
// Created by 陈瀚泽 on 2019-03-10.
//
// todo replace with hashmap

#include <vector>
#include <zconf.h>
#include <iostream>
#include <ncurses.h>
#include <unordered_map>
#include "../include/gameCommon.h"
#include "../include/keyBindMap.h"

io::keyBindMap::keyBindMap(){

    if (access(DUNGEON_KEY_CONF_LOC, 4) < 0)
    {
        this->keyMap[MOVE_L] = KEY_LEFT;
        this->keyMap[MOVE_UL] = KEY_HOME;
        this->keyMap[MOVE_R] = KEY_RIGHT;
        this->keyMap[MOVE_U] = KEY_UP;
        this->keyMap[MOVE_D] = KEY_DOWN;
        this->keyMap[MOVE_UR] = KEY_PPAGE;
        this->keyMap[MOVE_DR] = KEY_NPAGE;
        this->keyMap[MOVE_DL] = KEY_END;
        this->keyMap[GAME_REST] = KEY_B2;
        this->keyMap[DIS_C_INFO] = 'c';
        this->keyMap[MOVE_US] = '<';
        this->keyMap[DIS_C_EQIP] = 'e';
        this->keyMap[DIS_C_INVE] = 'i';
        this->keyMap[DIS_M_LIST] = 'm';
        this->keyMap[MOVE_DS] = '>';
        this->keyMap[DIS_MAP_T] = 's';
        this->keyMap[DIS_MAP_NTD] = 'D';
        this->keyMap[DIS_MAP_H] = 'h';
        this->keyMap[DIS_MAP_TD] = 'T';
        this->keyMap[DROP_ITEM] = 'd';
        this->keyMap[TOG_FOW] = 'f';
        this->keyMap[TELEPORT] = 'g';
        this->keyMap[TAKE_OFF] = 't';
        this->keyMap[WEAR_ITEM] = 'w';
        this->keyMap[EXPU_ITEM] = 'x';
        this->keyMap[INS_EQIP_I] = 'E';
        this->keyMap[INS_INVE_I] = 'I';
        this->keyMap[LOOK_AT_M] = 'L';
        this->keyMap[QUIT] = 'Q';
    }

    for (std::pair<int, int> element : this->keyMap){
        this->keyMapSearch[element.second] = element.first;
    }
}

int io::keyBindMap::setMoveKeySet(int *keyMap, int8_t combMum)
{
    switch (combMum){
    case 0:
        keyMap[MOVE_L] = KEY_LEFT;
        keyMap[MOVE_UL] = KEY_HOME;
        keyMap[MOVE_R] = KEY_RIGHT;
        keyMap[MOVE_U] = KEY_UP;
        keyMap[MOVE_D] = KEY_DOWN;
        keyMap[MOVE_UR] = KEY_PPAGE;
        keyMap[MOVE_DR] = KEY_NPAGE;
        keyMap[MOVE_DL] = KEY_END;
        return 0;
    case 1:
        keyMap[MOVE_L] = KEY_LEFT;
        keyMap[MOVE_UL] = KEY_HOME;
        keyMap[MOVE_R] = KEY_RIGHT;
        keyMap[MOVE_U] = KEY_UP;
        keyMap[MOVE_D] = KEY_DOWN;
        keyMap[MOVE_UR] = KEY_PPAGE;
        keyMap[MOVE_DR] = KEY_NPAGE;
        keyMap[MOVE_DL] = KEY_END;
        return 0;
    case 2:
        keyMap[MOVE_L] = KEY_LEFT;
        keyMap[MOVE_UL] = KEY_HOME;
        keyMap[MOVE_R] = KEY_RIGHT;
        keyMap[MOVE_U] = KEY_UP;
        keyMap[MOVE_D] = KEY_DOWN;
        keyMap[MOVE_UR] = KEY_PPAGE;
        keyMap[MOVE_DR] = KEY_NPAGE;
        keyMap[MOVE_DL] = KEY_END;
        return 0;
    default:
        return -1;
    }
}

int io::keyBindMap::setKey(keyList_t func, int key)
{
    keyMap[func] = key;
    return 0;
}