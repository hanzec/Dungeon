//
// Created by 陈瀚泽 on 2019-03-14.
//

#include "../../../include/Display/window/gameWindow.h"

int gameWindow::destroy() {
    wborder(this->windowPtr, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(this->windowPtr);
    return delwin(this->windowPtr);
}
