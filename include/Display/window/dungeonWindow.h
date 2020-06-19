//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_DUNGEONWINDOW_H
#define DUNGEON_COMS327_F19_DUNGEONWINDOW_H

#include "AbstractWindow.h"
#include "../../GameCommon.h"

class Monster;
class dungeonWindow : public AbstractWindow {
public:
    void setFOWStatus(bool flag);
    void setTeleportStatus(bool flag);
    dungeonWindow(dungeon_t * dungeon);
    void updatePlayer(location_t location);
    void updateGameContent(location_t location);

private:
    bool fow;
    bool teleport;
    void updateMap();
    dungeon_t * dungeonPtr;
    int updateMapByPixel(int x, int y);
    const chtype getTerFromChar(int x, int y);
};


#endif //DUNGEON_COMS327_F19_DUNGEONWINDOW_H
