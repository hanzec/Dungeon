//
// Created by chen_ on 2019/1/31.
//
#include <stdio.h>
#include <curses.h>
#include "dungeon_map_generate.h"

struct location{
    int x;
    int y;
};

struct room{
    struct location ur_corner;
    struct location ul_corner;
    struct location lr_corner;
    struct location ll_corner;
};

void generate_dungon(char** map, int height, int width, int seed){
    
    /*
     * 1st step generate the border as wall
     */

    for (int i = 0; i < height ; ++i) {
        if(i == 0 || i == (height - 1))
            for (int j = 0; j < width ; ++j)
                map[i][j] = 'w';
        else{
            map[i][0] = 'w';
            map[i][width] = 'w';
            for (int j = 0; j < width; ++j)
                if (map[i][j] != 'w')
                    map[i][j] == ' ';
        }
    }

    /*
     * 2nd add empty rooms to border
     */



}

void generate_room(char** map, int height, int width){

}