//
// Created by chen_ on 2019/1/31.
//
#include "game.h"
#include "io_file.h"
#include "io_display/display.h"
#include "utils/dungeon_utils.h"
#include "dungeon_map_generate.h"

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

void load_dungeon(dungeon_t *dungeon, bool cli_mode){

    if (dungeon == NULL){
        printf("read error");
        return;
    }

    current_level_map = malloc(sizeof(dungeon_t));
    memcpy(current_level_map,dungeon, sizeof(dungeon_t));
    free(dungeon);
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

