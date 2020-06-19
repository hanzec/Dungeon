//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_ABSTRACTWINDOW_H
#define DUNGEON_COMS327_F19_ABSTRACTWINDOW_H

template<typename T>
class AbstractWindow {
public:
    virtual T * getWindowPtr() = 0;
    virtual int getWindowWidth() = 0;
    virtual int  getWindowLength() = 0;
};

#endif //DUNGEON_COMS327_F19_ABSTRACTWINDOW_H
