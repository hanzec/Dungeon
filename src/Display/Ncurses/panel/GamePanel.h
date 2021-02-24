//
// Created by 陈瀚泽 on 2019-03-14.
//

#ifndef DUNGEON_COMS327_F19_PANEL_H
#define DUNGEON_COMS327_F19_PANEL_H

#include <string>
#include <panel.h>
#include <ncurses.h>
#include "../CursesWindow.h"

using namespace std;

class GamePanel : public CursesWindow{
private:
    bool visable = false;

protected:
    PANEL * panelPtr = nullptr;

    bool isVisable(){ return this -> visable;}
public:
    ~GamePanel();

    GamePanel(string name, int height, int width, int y, int x)
        :CursesWindow(name, height, width, y, x){
        this->panelPtr = new_panel(this->windowPtr);
    }

    void setVisable(bool status){
        this->visable = status;

        if(status)
            hide_panel(this->panelPtr);
        else
            show_panel(this->panelPtr);

        doupdate(); 
    }
    
    virtual void update() = 0;
    
    virtual void onResizeWindow(int newX, int newY) = 0;
};


#endif //DUNGEON_COMS327_F19_PANEL_H
