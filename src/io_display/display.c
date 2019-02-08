//
// Created by chen_ on 2019/1/31.
//

#include "display.h"
#include "display_utils.h"

WINDOW *base
//WINDOW *menu  todo: menu need to add;
//WINDOW *status_bar; todo： status bar need to add

void display_dungeon(char** map){
    int height = sizeof(map)/ sizeof(map[0]);
    int width = sizeof(map[0])/ sizeof(map[0][0]);

    if(!base)
        base = create_newwin(height,width);

    for (int i = 1; i < height; ++i)
        mvwprintw(base,0,i,map[i])

}

