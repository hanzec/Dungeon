//
// Created by 陈瀚泽 on 2019-03-10.
//

#ifndef DUNGEON_COMS327_F19_KEYBINDMAP_H
#define DUNGEON_COMS327_F19_KEYBINDMAP_H
#include <unordered_map>

namespace io{
    class keyBindMap{
    private:
        typedef enum keyList{
            MOVE_UL,    MOVE_L,     MOVE_R,     MOVE_U,     MOVE_D,
            MOVE_UR,    MOVE_DR,    MOVE_DL,    GAME_REST,  MOVE_DS,
            MOVE_US,    DIS_C_INFO, DIS_C_EQIP, DIS_C_INVE, DIS_M_LIST,
            DIS_MAP_T,  DIS_MAP_NTD,DIS_MAP_H,  DIS_MAP_TD, DROP_ITEM,
            TOG_FOW,    TELEPORT,   TAKE_OFF,   WEAR_ITEM,  EXPU_ITEM,
            INS_EQIP_I, INS_INVE_I, LOOK_AT_M,  QUIT     ,  KEY_LIST_NUM,
        }keyList_t;

        std::unordered_map<keyBindMap::keyList, int> keyMap;
        std::unordered_map<int, keyBindMap::keyList> keyMapSearch;
    public:
        keyBindMap(/* args */);
        ~keyBindMap();
        
        int setMoveKeySet(int * keyMap, int8_t combNum);
        int setKey(int * keyMap, keyList_t func, int key);
    };   
}
#endif //DUNGEON_COMS327_F19_KEYBINDMAP_H
