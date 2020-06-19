//
// Created by 陈瀚泽 on 2019-03-14.
//

#include "window/AbstractWindow.h"

int AbstractWindow::destroy() {
    wborder(this->windowPtr, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(this->windowPtr);
    return delwin(this->windowPtr);
}

