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
    std::list<std::shared_ptr<Monster> > * monstersPtr;
public:
    int updatePanel();
    explicit monsterList(std::list<std::shared_ptr<Monster> > * monsters);
    void updateMonsterNode(std::list<std::shared_ptr<Monster> > * monsters);
};


#endif //DUNGEON_COMS327_F19_MONSTERLIST_H
