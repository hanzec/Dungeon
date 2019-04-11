//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_DUNGEONWINDOW_H
#define DUNGEON_COMS327_F19_DUNGEONWINDOW_H

#include "gameWindow.h"
#include "../../GameCommon.h"

class Monster;
class dungeonWindow : public gameWindow {
public:
    void setFOWStatus(bool flag);
    void setTeleportStatus(bool flag);
    dungeonWindow(dungeon_t * dungeon);
    int updatePlayer(pair_t location, pair_t prevLocation);
    int updateGameItem(pair_t location, pair_t prevLocation, int color, char symbol);

private:
    bool fow;
    bool teleport;
    void updateMap();
    dungeon_t * dungeonPtr;
    int updateMapByPixel(int x, int y);
    const chtype getTerFromChar(int x, int y);
};


#endif //DUNGEON_COMS327_F19_DUNGEONWINDOW_H
