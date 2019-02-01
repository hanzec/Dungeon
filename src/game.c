//
// Created by chen_ on 2019/1/31.
//
#include "game.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "io_display/display.h"
#include "dungeon_map_generate.h"

int current_width = 0;
int current_height = 0;
char** current_level_map;
//todo current status

void start_new(int height, int width){
    /*
     * 1st step alloc memory spaces for map
     *
     * current_level_map[height][width]
     */

    current_level_map = malloc(sizeof(char*)*height);
    for (int i = 0; i < width; ++i) {
        current_level_map[i] = malloc(sizeof(char*)*width);
    }

    current_height = height;
    current_width = width;

    /*
     * 2nd step generate the dungeon map
     */

    srand(time(NULL));
    generate_dungon(current_level_map,height,width,rand());


    /*
     * finish setup play game
     */

    display_dungeon(current_level_map);


    /*
     * when finished game
     */

    close_game();

}

void close_game(){

    /*
     * clean the map memory
     */
    for (int i = 0; i < current_height; ++i) {
        free(current_level_map[i]);
    }
    free(current_level_map);

    current_height = 0;
    current_width = 0;
}

