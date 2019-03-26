//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_WINDOW_H
#define DUNGEON_COMS327_F19_WINDOW_H

#include <cstddef>
#include <ncurses.h>

class gameWindow {
public:
    WINDOW * windowPtr = nullptr;

    int destroy();
};

#endif //DUNGEON_COMS327_F19_WINDOW_H
