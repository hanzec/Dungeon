//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_PANEL_H
#define DUNGEON_COMS327_F19_PANEL_H

#include <panel.h>

class gamePanel{
public:
    PANEL * panel;
    int hidePanel();
    int displayPanel();
    virtual int updatePanel() = 0;
};


#endif //DUNGEON_COMS327_F19_PANEL_H
