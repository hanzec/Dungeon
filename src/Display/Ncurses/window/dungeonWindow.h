//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_DUNGEONWINDOW_H
#define DUNGEON_COMS327_F19_DUNGEONWINDOW_H
#include <memory>
#include "GameCommon.h"
#include "../CursesWindow.h"

using namespace std;

class GameWindow : public CursesWindow {
public:
    GameWindow(shared_ptr<Dungeon> dungeon);
    void updatePlayer(location_t location);
    void updateGameContent(location_t location);

private:
    void updateMap();
    shared_ptr<Dungeon> dungeonPtr;
    int updateMapByPixel(int x, int y);
    const chtype getTerFromChar(int x, int y);
};


#endif //DUNGEON_COMS327_F19_DUNGEONWINDOW_H
