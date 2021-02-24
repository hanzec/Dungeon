//
// Created by 陈瀚泽 on 2019-03-14.
//


#include <queue>
#include <ncurses.h>
#include "GameCommon.h"
#include "../displayCommon.h"
#include "MonsterListPanel.h"

MonsterListPanel::MonsterListPanel(shared_ptr<list<Monster>> monsters, WINDOW * gameWindow)
    :GamePanel("MONSTER_PANEL", gameWindow) {
    this->monsters = monsters;
    wbkgd(panel_window(this->panel),COLOR_PAIR(PAIR_PANEL));
}

int MonsterListPanel::updatePanel() {
    int x, y, i = 0;

    wclear(panel_window(this->panel));
    box(panel_window(this->panel), 0 , 0);
    mvwprintw(panel_window(this->panel),0,12,"| Monster List |");

    //todo add number index of monster(c++)
    for (auto K : *this->monstersPtr) {
        char tmp[3];
        mvwaddch(panel_window(this->panel),i, 3, '#');
        mvwaddch(panel_window(this->panel),i, 4, ' ');
        mvwaddch(panel_window(this->panel),i, 5, ' ');
        mvwaddch(panel_window(this->panel),i, 6, 'x');
        mvwaddch(panel_window(this->panel),i, 7, ':');
        sprintf(tmp, "%d", K->location[curr_x]);
        mvwaddch(panel_window(this->panel),i, 8, tmp[0]);
        mvwaddch(panel_window(this->panel),i, 9, tmp[1]);
        mvwaddch(panel_window(this->panel),i, 10, ' ');

        mvwaddch(panel_window(this->panel),i, 11, 'y');
        mvwaddch(panel_window(this->panel),i, 12, ':');
        sprintf(tmp, "%d", K->location[curr_y]);
        mvwaddch(panel_window(this->panel),i, 13, tmp[0]);
        mvwaddch(panel_window(this->panel),i, 14, tmp[1]);
        mvwaddch(panel_window(this->panel),i, 15, ' ');

        i++;
    }

    getyx(panel_window(this->panel),y,x);
    mvwprintw(panel_window(this->panel),y + 1,5,"Press ANY key to return Game!");
}

void MonsterListPanel::updateMonsterNode(std::list<Monster * > * monsters) { this->monstersPtr = monsters; }
