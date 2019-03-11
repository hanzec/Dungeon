//
// Created by chen_ on 2019/1/31.
//
#include "../include/game.h"
#include "../include/io_file_c.h"
#include "../include/display/display.h"
#include "../include/utils/dungeon_utils.h"
#include "../include/utils/dungeon_gen_map.h"

dungeon_t *current_level_map;
//todo current status
//todo multiple stair support
void start_new(bool cli_mode){
    current_level_map = malloc(sizeof(dungeon_t));
    generate_dungon(current_level_map);

    if (cli_mode){
        print_dungeon_cli(current_level_map);
    }
}

void load_dungeon(bool cli_mode){
    current_level_map = malloc(sizeof(dungeon_t));

    read_operation(dump_dungeon(), NULL);

    current_level_map = malloc(sizeof(dungeon_t));
    memcpy(current_level_map,current_level_map, sizeof(dungeon_t));
    free(current_level_map);
    print_dungeon_cli(current_level_map);
}

dungeon_t* dump_dungeon(){
    dungeon_t *dump = malloc(sizeof(dungeon_t));
    memcpy(dump,current_level_map, sizeof(dungeon_t));

    return dump;
}


void close_dungeon(bool cli_mode){

    free(current_level_map);

}

