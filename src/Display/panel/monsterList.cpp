//
// Created by 陈瀚泽 on 2019-03-14.
//


#include <queue>
#include <ncurses.h>
#include "../../../include/GameCommon.h"
#include "../../../include/Display/displayCommon.h"
#include "../../../include/Display/panel/monsterList.h"

monsterList::monsterList(MonsterNode * monsterNode) {
    // todo need to change instead of hard code
    monsterNodePtr = monsterNode;
    this->panel = new_panel(newwin(3 + this->getNumberOfMonster(), 38,4,20));
    wbkgd(panel_window(this->panel),COLOR_PAIR(PAIR_PANEL));
}

int monsterList::updateMonsterNode(MonsterNode *monsterNode) {
    this->monsterNodePtr = monsterNode;
    return 0;
}

int monsterList::updatePanel() {
    int x, y;
    MonsterNode * currentNode = this->monsterNodePtr->nextNode;
    WINDOW * tmpWindowsPtr = panel_window(this->panel);

    int numMonster = getNumberOfMonster();

    wclear(tmpWindowsPtr);
    box(tmpWindowsPtr, 0 , 0);

    mvwprintw(tmpWindowsPtr,0,12,"| Monster List |");
    //todo add number index of monster(c++)
    for (int i = 1; i < numMonster; ++i) {
        char tmp[3];
        mvwaddch(tmpWindowsPtr,i, 3, '#');
        mvwaddch(tmpWindowsPtr,i, 4, ' ');
        mvwaddch(tmpWindowsPtr,i, 5, ' ');
        mvwaddch(tmpWindowsPtr,i, 6, 'x');
        mvwaddch(tmpWindowsPtr,i, 7, ':');
        sprintf(tmp, "%d", currentNode->monster->currentLocation[dim_x]);
        mvwaddch(tmpWindowsPtr,i, 8, tmp[0]);
        mvwaddch(tmpWindowsPtr,i, 9, tmp[1]);
        mvwaddch(tmpWindowsPtr,i, 10, ' ');

        mvwaddch(tmpWindowsPtr,i, 11, 'y');
        mvwaddch(tmpWindowsPtr,i, 12, ':');
        sprintf(tmp, "%d", currentNode->monster->currentLocation[dim_y]);
        mvwaddch(tmpWindowsPtr,i, 13, tmp[0]);
        mvwaddch(tmpWindowsPtr,i, 14, tmp[1]);
        mvwaddch(tmpWindowsPtr,i, 15, ' ');

        currentNode = currentNode->nextNode;
    }

    getyx(tmpWindowsPtr,y,x);
    mvwprintw(tmpWindowsPtr,y + 1,5,"Press ANY key to return Game!");
    return 0;
}

int monsterList::getNumberOfMonster(){
    int number = 0;
    MonsterNode * tmp = this->monsterNodePtr->nextNode;

    while (tmp->nextNode->monster != nullptr){
        number += 1;
        tmp = tmp->nextNode;
    }
    return number - 1;

}
