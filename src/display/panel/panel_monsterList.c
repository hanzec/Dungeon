//
// Created by 陈瀚泽 on 2019-03-12.
//


#include <panel.h>
#include <ncurses.h>
#include "gameCommon.h"
#include "displayCommon.h"
#include "panel_monsterList.h"
#include "MonsterController.h"


//todo add scroll function
PANEL * initMonsterList(monsterNode_t * monsterNode){
    int numMonster = getNumberOfMonster(*monsterNode);
    // todo need to change instead of hard code
    PANEL * monsterPanel = new_panel(newwin(3 + numMonster, 38,4,20));
    wbkgd(panel_window(monsterPanel),COLOR_PAIR(PAIR_PANEL));

    return monsterPanel;
}

int  updateMonsterList(WINDOW * window, monsterNode_t * monsterNode){
    int x, y;
    int tmpNumber = 1;
    monsterNode_t * currentNode = monsterNode->nextNode;
    int numMonster = getNumberOfMonster(*currentNode);

    wclear(window);
    box(window, 0 , 0);
    
    mvwprintw(window,0,12,"| Monster List |");
    //todo add number index of monster(c++)
    for (int i = 1; i <= numMonster; ++i) {
        char tmp[3];
        mvwaddch(window,i, 3, '#');
        mvwaddch(window,i, 4, ' ');
        mvwaddch(window,i, 5, ' ');
        mvwaddch(window,i, 6, 'x');
        mvwaddch(window,i, 7, ':');
        sprintf(tmp, "%d", currentNode->monster->location[dim_x]);
        mvwaddch(window,i, 8, tmp[0]);
        mvwaddch(window,i, 9, tmp[1]);
        mvwaddch(window,i, 10, ' ');

        mvwaddch(window,i, 11, 'y');
        mvwaddch(window,i, 12, ':');
        sprintf(tmp, "%d", currentNode->monster->location[dim_y]);
        mvwaddch(window,i, 13, tmp[0]);
        mvwaddch(window,i, 14, tmp[1]);
        mvwaddch(window,i, 15, ' ');

        currentNode = currentNode->nextNode;
    }

    getyx(window,y,x);
    mvwprintw(window,y + 1,5,"Press ANY key to return Game!");
}