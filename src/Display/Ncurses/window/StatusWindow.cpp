//
// Created by 陈瀚泽 on 2019-03-14.
//

#include <ctime>
#include <curses.h>
#include <sys/_types/_time_t.h>
#include "StatusWindow.h"
#include "../displayCommon.h"

StatusWindow::StatusWindow(shared_ptr<queue<string>> queue)
    :CursesWindow("STATUS_WINDOW", STATUS_WINDOW_Y, STATUS_WINDOW_X, STATUS_WINDOW_LENGTH, STATUS_WINDOW_HEIGHT),messageQueue(queue){
    wbkgd(this->windowPtr,COLOR_PAIR(PAIR_STATUS_BAR));
}

void StatusWindow::onUpdate(){
    // update message queue
    if(!(*this->messageQueue).empty()){
        string newMessage = (*this->messageQueue).front();
        if (newMessage.length() < this->getCurrentWidth() - STATUS_WINDOW_TIME_SLOT_LENGTH){
            mvwaddstr(this->windowPtr, 0, 0, this->prevMessage.c_str());
            mvwaddstr(this->windowPtr, 0, 1, newMessage.c_str());
            this->prevMessage = newMessage;
        }else{
            this->prevMessage = newMessage;
            mvwaddnstr(this->windowPtr, 0, 0, newMessage.c_str(), this->getCurrentWidth() - STATUS_WINDOW_TIME_SLOT_LENGTH);
            mvwaddstr(this->windowPtr, 0, 1, newMessage.c_str() + this->getCurrentWidth() - STATUS_WINDOW_TIME_SLOT_LENGTH);
        }
    }

    // update current time
    time_t t = time(0);
    tm* now = localtime(&t);
    mvwprintw(this->windowPtr, 0, 0, "   %02d::%02d   ", now->tm_hour, now->tm_min);
    mvwprintw(this->windowPtr, 1, 0, " %04d-%02d-%02d ", now->tm_year + 1900, now->tm_mon, now->tm_mday);
}
