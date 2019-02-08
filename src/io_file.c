//
// Created by chen_ on 2019/2/6.
//

#include <stdlib.h>
#include <memory.h>
#include <bits/types/FILE.h>
#include <stdio.h>
#include "io_file.h"
#include "game.h"


dungeon_t* read_operation(){
    char * tmp;
    FILE * saved_file;
    uint32_t version;
    uint32_t file_size;
    dungeon_t *dungeon = malloc(sizeof(dungeon_t));

    char *home = getenv("HOME");
    char *path = malloc(strlen(home) + strlen("/rlg327/dungeon") + 1);

    strcpy(path,home);
    strcat(path,"/.rlg327/dungeon");
    saved_file = fopen(path,"r");

    fseek(saved_file,0,SEEK_SET);

    //Check file Header should be 12 Byte
    tmp = malloc(12);
    fread(tmp,1,12,saved_file);
    if (!strcpy(tmp,"RLG327-S2019"))
        return NULL;
    free(tmp);

    //Check the version of the save Game(Not used now)
    tmp = malloc(4);
    fread(tmp,1,4,saved_file);
    version = (uint32_t) *tmp;
    free(tmp);

    //Check the file Size
    tmp = malloc(4);
    fread(tmp,1,4,saved_file);
    file_size = (uint32_t) *tmp;
    free(tmp);

    //Read the PC location
    tmp = malloc(2);
    fread(tmp,1,2,saved_file);
    dungeon->pc_position[dim_x] = tmp[0];
    dungeon->pc_position[dim_y] = tmp[1];
    free(tmp);

    //Read hardness of the dungeon
    tmp =  malloc(1680);
    fread(tmp,1,1680,saved_file);
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            dungeon->hardness[i][j] = (int32_t) *tmp[i * DUNGEON_X + j];
        }
    }

    //Read the PC location
    tmp = malloc(2);
    fread(tmp,1,2,saved_file);
dungeon->num_rooms = *tmp
    free(tmp);




}
int wrie_dunegeon(){}
