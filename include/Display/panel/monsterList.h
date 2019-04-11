//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_MONSTERLIST_H
#define DUNGEON_COMS327_F19_MONSTERLIST_H

#include "gamePanel.h"
#include "../../utils/MonsterController.h"

class monsterList : public gamePanel {
private:
    MonsterNode * monsterNodePtr;
    int getNumberOfMonster();
public:
    int updatePanel();
    int updateMonsterNode(MonsterNode *monsterNode);
    explicit monsterList(MonsterNode *monsterNode);
};


#endif //DUNGEON_COMS327_F19_MONSTERLIST_H
