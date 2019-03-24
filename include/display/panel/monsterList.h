//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_MONSTERLIST_H
#define DUNGEON_COMS327_F19_MONSTERLIST_H

#include "gamePanel.h"
#include "../../characters/MonsterController.h"

class monsterList : public gamePanel {
private:
    monsterNode_t * monsterNodePtr;
    int getNumberOfMonster(monsterNode_t monsterNode);
public:
    int updatePanel();
    explicit monsterList(monsterNode_t *monsterNode);
};


#endif //DUNGEON_COMS327_F19_MONSTERLIST_H
