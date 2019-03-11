//
// Created by chen_ on 2019/2/6.
//

#include "../include/game.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../include/io_file_c.h"
#include <assert.h>
#include <sys/stat.h>
#include "../include/utils/dungeon_gen_map.h"
#include <crossplatform_header/endian.h>

void read_operation(dungeon_t *dungeon, char *path){
    uint16_t tmp = 0;
    FILE * saved_file;
    struct stat statbuf;
    char file_head[] = "RLG327-S2019";

    if (path == NULL){
        char *home = getenv("HOME");
        *path = malloc(strlen(home) + strlen("/.rlg327/dungeon") + 1);
        strcpy(path,home);
        strcat(path,"/.rlg327/dungeon");
        free(home);
    }


    stat(path,&statbuf);
    saved_file = fopen(path,"r");
    fflush(saved_file);

    //check the file head
    char *tmp_file_head = malloc(12);
    fread(tmp_file_head,12,1,saved_file);

    //Read the file version;
    int *tmp_file_version = malloc(4);
    fread(tmp_file_version,4,1,saved_file);

    //read the file size
    uint32_t *file_size = malloc(4);
    fread(file_size,4,1,saved_file);

    //Read the pc location
    fread(&dungeon->pc_position[dim_x],1,1,saved_file);
    fread(&dungeon->pc_position[dim_y],1,1,saved_file);

    //read the hardness of the dungeon
    bzero(dungeon->hardness, sizeof(uint8_t)*DUNGEON_Y*DUNGEON_X);
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            fread(&dungeon->hardness[i][j],1,1,saved_file);
            if (dungeon->hardness[i][j] < 1)
                dungeon->map[i][j] = ter_floor_hall;
            else if (dungeon->hardness[i][j] == 255)
                dungeon->map[i][j] = ter_wall_immutable;
            else
                dungeon->map[i][j] = ter_wall;
        }
    }

    //read the number of room in current dungeon
    tmp = 0;
    fread(&tmp, 2, 1, saved_file);
    dungeon->num_rooms = be16toh(tmp);

    //read the room in current dungeon
    for (int k = 0; k < dungeon->num_rooms; ++k) {
        fread(&dungeon->rooms[k].position[dim_x],1,1,saved_file);
        fread(&dungeon->rooms[k].position[dim_y],1,1,saved_file);
        fread(&dungeon->rooms[k].size[dim_x],1,1,saved_file);
        fread(&dungeon->rooms[k].size[dim_y],1,1,saved_file);

        for (int i = 0; i < dungeon->rooms[k].size[dim_y]; ++i) {
            for (int j = 0; j < dungeon->rooms[k].size[dim_x]; ++j) {
                dungeon->map[i + dungeon->rooms[k].position[dim_y]][j + dungeon->rooms[k].position[dim_x]] = ter_floor_room;
            }
        }
    }

    // Read the number of the up stairs
    tmp = 0;
    fread(&tmp,2,1,saved_file);
    dungeon->num_up_stairs = be16toh(tmp);

    // read the location of the up stairs
    for (int l = 0; l < dungeon->num_up_stairs; ++l) {
        uint8_t x,y;
        fread(&x,1,1,saved_file);
        fread(&y,1,1,saved_file);
        dungeon->map[y][x] = ter_stairs_up;
    }

    // read the number of down stairs
    fread(&tmp,2,1,saved_file);
    dungeon->num_down_stairs = be16toh(tmp);

    // read the location of the down stairs

    for (int l = 0; l < dungeon->num_down_stairs; ++l) {
        uint8_t x,y;
        fread(&x,1,1,saved_file);
        fread(&y,1,1,saved_file);
        dungeon->map[y][x] = ter_stairs_down;
    }

    free(file_size);
    fclose(saved_file);
    free(tmp_file_head);
    free(tmp_file_version);

}
int write_operation(dungeon_t *dungeon){
    uint32_t tmp;
    FILE * saved_file;
    char *home = getenv("HOME");
    char file_head[] = "RLG327-S2019";
    char *path = malloc(strlen(home) + strlen("/.rlg327/dungeon") + 1);

    strcpy(path,home);
    strcat(path,"/.rlg327/dungeon");

    system("mkdir ~/.rlg327");
    system("rm -rf ~/.rlg327/dungeon");
    saved_file = fopen(path, "w");

    // write file header
    fwrite(&file_head,12,1,saved_file);

    // write the file version
    tmp = htobe32(DUNGEON_VERSION);
    fwrite(&tmp, sizeof(tmp),1,saved_file);

    //write the file size
    tmp = htobe32(1704 + dungeon->num_rooms * 4 + 4 + dungeon->num_down_stairs * 2 + dungeon->num_up_stairs * 2);
    fwrite(&tmp, sizeof(tmp),1,saved_file);

    //write the pc location
    //tmp set to 1st room's position
    fwrite(&dungeon->rooms->position[dim_x], 1,1,saved_file);
    fwrite(&dungeon->rooms->position[dim_y], 1,1,saved_file);

    //write the hardness of the dungeon
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            fwrite(&dungeon->hardness[i][j], 1,1,saved_file);
        }
    }

    //write the room number
    tmp = htobe16(dungeon->num_rooms);
    fwrite(&tmp, 2,1,saved_file);

    //write the room
    for (int k = 0; k < dungeon->num_rooms; ++k) {
        fwrite(&dungeon->rooms[k].position[dim_x],1,1,saved_file);
        fwrite(&dungeon->rooms[k].position[dim_y],1,1,saved_file);
        fwrite(&dungeon->rooms[k].size[dim_x],1,1,saved_file);
        fwrite(&dungeon->rooms[k].size[dim_y],1,1,saved_file);
    }

    // write the number of the up stairs
    tmp = htobe16(dungeon->num_up_stairs);
    fwrite(&tmp,2,1,saved_file);

    // write the location of the up stairs
    for (uint8_t m = 0; m < DUNGEON_Y; ++m) {
        for (uint8_t i = 0; i < DUNGEON_X; ++i) {
            if (dungeon->map[m][i] == ter_stairs_up){
                fwrite(&i,1,1,saved_file);
                fwrite(&m,1,1,saved_file);
            }
        }

    }

    // read the number of down stairs
    tmp = htobe16(dungeon->num_down_stairs);
    fwrite(&tmp,2,1,saved_file);

    // read the location of the down stairs

    for (uint8_t m = 0; m < DUNGEON_Y; ++m) {
        for (uint8_t i = 0; i < DUNGEON_X; ++i) {
            if (dungeon->map[m][i] == ter_stairs_down){
                fwrite(&i,1,1,saved_file);
                fwrite(&m,1,1,saved_file);
            }
        }

    }

    fclose(saved_file);

}
