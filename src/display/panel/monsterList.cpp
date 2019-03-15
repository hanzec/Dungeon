//
// Created by 陈瀚泽 on 2019-03-14.
//


#include <ncurses.h>
#include "../../../include/gameCommon.h"
#include "../../../include/display/displayCommon.h"
#include "../../../include/display/panel/monsterList.h"
#include "../../../include/characters/MonsterController.h"

monsterList::monsterList(monsterNode_t *monsterNode) {
    int numMonster = getNumberOfMonster(*((monsterNode_t *) monsterNode));
    // todo need to change instead of hard code
    this->panel = new_panel(newwin(3 + numMonster, 38,4,20));
    wbkgd(panel_window(this->panel),COLOR_PAIR(PAIR_PANEL));
}

int monsterList::updatePanel(monsterNode_t * monsterNode) {
    int x, y;
    int tmpNumber = 1;
    WINDOW * tmpWindowsPtr = panel_window(this->panel);
    monsterNode_t * currentNode = monsterNode->nextNode;
    int numMonster = getNumberOfMonster(*currentNode);

    wclear(tmpWindowsPtr);
    box(tmpWindowsPtr, 0 , 0);

    mvwprintw(tmpWindowsPtr,0,12,"| Monster List |");
    //todo add number index of monster(c++)
    for (int i = 1; i <= numMonster; ++i) {
        char tmp[3];
        mvwaddch(tmpWindowsPtr,i, 3, '#');
        mvwaddch(tmpWindowsPtr,i, 4, ' ');
        mvwaddch(tmpWindowsPtr,i, 5, ' ');
        mvwaddch(tmpWindowsPtr,i, 6, 'x');
        mvwaddch(tmpWindowsPtr,i, 7, ':');
        sprintf(tmp, "%d", currentNode->monster->location[dim_x]);
        mvwaddch(tmpWindowsPtr,i, 8, tmp[0]);
        mvwaddch(tmpWindowsPtr,i, 9, tmp[1]);
        mvwaddch(tmpWindowsPtr,i, 10, ' ');

        mvwaddch(tmpWindowsPtr,i, 11, 'y');
        mvwaddch(tmpWindowsPtr,i, 12, ':');
        sprintf(tmp, "%d", currentNode->monster->location[dim_y]);
        mvwaddch(tmpWindowsPtr,i, 13, tmp[0]);
        mvwaddch(tmpWindowsPtr,i, 14, tmp[1]);
        mvwaddch(tmpWindowsPtr,i, 15, ' ');

        currentNode = currentNode->nextNode;
    }

    getyx(tmpWindowsPtr,y,x);
    mvwprintw(tmpWindowsPtr,y + 1,5,"Press ANY key to return Game!");
}

