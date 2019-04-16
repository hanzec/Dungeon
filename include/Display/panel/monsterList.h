//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_MONSTERLIST_H
#define DUNGEON_COMS327_F19_MONSTERLIST_H

#include <vector>
#include <memory>
#include "gamePanel.h"
#include "../../GameContant/Monster.h"

class monsterList : public gamePanel {
private:
    std::list<Monster> * monstersPtr;
public:
    int updatePanel();
    explicit monsterList(std::list<Monster> * monsters);
    void updateMonsterNode(std::list<Monster> * monsters);
};


#endif //DUNGEON_COMS327_F19_MONSTERLIST_H
