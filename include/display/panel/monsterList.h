//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_MONSTERLIST_H
#define DUNGEON_COMS327_F19_MONSTERLIST_H

#include "gamePanel.h"
#include "../../characters/charactersCommon.h"


class monsterList : public gamePanel {
public:
    explicit monsterList(monsterNode_t *monsterNode);
    int updatePanel(monsterNode_t * monsterNode);
};


#endif //DUNGEON_COMS327_F19_MONSTERLIST_H
