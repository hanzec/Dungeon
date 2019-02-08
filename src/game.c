//
// Created by chen_ on 2019/1/31.
//
#include "game.h"

#include "io_display/display.h"
#include "dungeon_map_generate.h"

dungeon_t *current_level_map;
//todo current status

void start_new(bool cli_mode){
    current_level_map = malloc(sizeof(dungeon_t));

    generate_dungon(current_level_map);

}

void close_game(bool cli_mode){

    free(current_level_map);

}

