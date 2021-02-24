//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_MONSTERLIST_H
#define DUNGEON_COMS327_F19_MONSTERLIST_H

#include <vector>
#include <memory>
#include "GamePanel.h"
#include "GameContant/Monster.h"

using namespace std;

class MonsterListPanel : public GamePanel {
private:
    shared_ptr<list<Monster>> monsters;
public:
    void update();
    MonsterListPanel(shared_ptr<list<Monster>> monsters);
};

#endif //DUNGEON_COMS327_F19_MONSTERLIST_H
