//
// Created by 陈瀚泽 on 2019-03-10.
//
// todo replace with hashmap

#include <zconf.h>
#include "game.h"
#include "KeyBindMap.h"
#include <ncurses.h>

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
        result[GAME_REST] = ;
        result[DIS_C_INFO] = ;
        result[MOVE_US] = ;
        result[DIS_C_EQIP] = ;
        result[DIS_C_INVE] = ;
        result[DIS_M_LIST] = ;
        result[MOVE_DS] = ;
        result[DIS_MAP_T] = ;
        result[DIS_MAP_NTD] = ;
        result[DIS_MAP_H] = ;
        result[DIS_MAP_TD] = ;
        result[DROP_ITEM] = ;
        result[TOG_FOW] = ;
        result[TELEPORT] = ;
        result[TAKE_OFF] = ;
        result[WEAR_ITEM] = ;
        result[EXPU_ITEM] = ;
        result[INS_EQIP_I] = ;
        result[INS_INVE_I] = ;
        result[LOOK_AT_M] = ;
        result[QUIT] = ;
    }
}