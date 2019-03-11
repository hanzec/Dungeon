//
// Created by 陈瀚泽 on 2019-03-10.
//
// todo replace with hashmap

#include "../include/game.h"
#include "../include/KeyBindMap.h"
#include <unistd.h>
#include <curses.h>

int * initKeyMap(){
    int * result = malloc(sizeof(keyList_t));

    if(access(DUNGEON_KEY_CONF_LOC,4) < 0){
        result[MOVE_L] = KEY_LEFT;
        result[MOVE_UL] = KEY_HOME;
        result[MOVE_R] = KEY_RIGHT;
        result[MOVE_U] = KEY_UP;
        result[MOVE_D] = KEY_DOWN;
        result[MOVE_UR] = KEY_PPAGE;
        result[MOVE_DR] = KEY_NPAGE;
        result[MOVE_DL] = KEY_END;
        result[GAME_REST] = KEY_B2;
        result[DIS_C_INFO] = 'c';
        result[MOVE_US] = '<';
        result[DIS_C_EQIP] = 'e';
        result[DIS_C_INVE] = 'i';
        result[DIS_M_LIST] = 'm';
        result[MOVE_DS] = '>';
        result[DIS_MAP_T] = 's';
        result[DIS_MAP_NTD] = 'D';
        result[DIS_MAP_H] = 'h';
        result[DIS_MAP_TD] = 'T';
        result[DROP_ITEM] = 'd';
        result[TOG_FOW] = 'f';
        result[TELEPORT] = 'g';
        result[TAKE_OFF] = 't';
        result[WEAR_ITEM] = 'w';
        result[EXPU_ITEM] = 'x';
        result[INS_EQIP_I] = 'E';
        result[INS_INVE_I] = 'I';
        result[LOOK_AT_M] = 'L';
        result[QUIT] = 'Q';
    }

    return result;
}

int setMoveKeySet(int * keyMap, int8_t combMum){
    switch(combMum){
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

int setKey(int * keyMap, keyList_t func, int key){
    if (keyMap == NULL)
        return -1;
    keyMap[func] = key;
    return 0;
}