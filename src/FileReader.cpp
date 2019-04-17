//
// Created by chen_ on 2019/2/6.
//

#include<vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#include <sys/stat.h>
#include <sstream>
#include <unordered_map>
#include <string> // pulls in declaration for strlen.
#include "../include/FileReader.h"
#include "../include/Utils/crossplatform_header/endian.h"

int io::FileReader::read_operation(dungeon_t *dungeon, char * path){
    uint16_t tmp = 0;
    FILE * saved_file;
    struct stat statbuf;
    char file_head[] = "RLG327-S2019";

    if (path == NULL){
        char *home = getenv("HOME");
        path = (char *)malloc(strlen(home) + strlen("/.rlg327/dungeon") + 1);
        strcpy(path,home);
        strcat(path,"/.rlg327/dungeon");
        free(home);
    }


    stat(path,&statbuf);
    saved_file = fopen(path,"r");
    fflush(saved_file);

    //check the file head
    char *tmp_file_head = (char *)malloc(12);
    fread(tmp_file_head,12,1,saved_file);

    //Read the file version;
    int *tmp_file_version = (int *)malloc(4);
    fread(tmp_file_version,4,1,saved_file);

    //read the file size
    uint32_t *file_size = (uint32_t *) malloc(4);
    fread(file_size,4,1,saved_file);

    // //Read the npc location
    // fread(&dungeon->pcInitLocation[curr_x],1,1,saved_file);
    // fread(&dungeon->pcInitLocation[curr_y],1,1,saved_file);

    //read the hardness of the dungeon
    bzero(dungeon->map, sizeof(map_block_t)*DUNGEON_Y*DUNGEON_X);
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            fread(&dungeon->map[i][j].hardness,1,1,saved_file);
            if (dungeon->map[i][j].hardness < 1)
                dungeon->map[i][j].terrain_type = ter_floor_hall;
            else if (dungeon->map[i][j].hardness == 255)
                dungeon->map[i][j].terrain_type = ter_wall_immutable;
            else
                dungeon->map[i][j].terrain_type = ter_wall;
        }
    }

    //read the number of room in current dungeon
    tmp = 0;
    fread(&tmp, 2, 1, saved_file);
    // dungeon->num_rooms = be16toh(tmp);

    // //read the room in current dungeon
    // for (int k = 0; k < dungeon->num_rooms; ++k) {
    //     room_t * tmpRoom = new room_t();
    //     fread((void *)tmpRoom->position[curr_x],1,1,saved_file);
    //     fread((void *)tmpRoom->position[curr_y],1,1,saved_file);
    //     fread((void *)tmpRoom->size[curr_x],1,1,saved_file);
    //     fread((void *)tmpRoom->size[curr_y],1,1,saved_file);

    //     for (int i = 0; i < tmpRoom->size[curr_y]; ++i) {
    //         for (int j = 0; j < tmpRoom->size[curr_x]; ++j) {
    //             dungeon->map[i + tmpRoom->position[curr_y]][j + tmpRoom->position[curr_x]].terrain_type = ter_floor_room;
    //         }
    //     }
    //     dungeon->rooms.push_back(*tmpRoom);
    // }

    // Read the number of the up stairs
    tmp = 0;
    fread(&tmp,2,1,saved_file);
    int num_up_stairs = be16toh(tmp);

    // read the location of the up stairs
    for (int l = 0; l < num_up_stairs; ++l) {
        uint8_t x,y;
        fread(&x,1,1,saved_file);
        fread(&y,1,1,saved_file);
        dungeon->map[y][x].terrain_type = ter_stairs_up;
    }

    // read the number of down stairs
    fread(&tmp,2,1,saved_file);

    // read the location of the down stairs

    for (int l = 0; l < be16toh(tmp); ++l) {
        uint8_t x,y;
        fread(&x,1,1,saved_file);
        fread(&y,1,1,saved_file);
        dungeon->map[y][x].terrain_type = ter_stairs_down;
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
    char *path = (char *) malloc(strlen(home) + strlen("/.rlg327/dungeon") + 1);

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
    // tmp = htobe32(1704 + dungeon->num_rooms * 4 + 4 + dungeon->downStairs.size() * 2 + dungeon->upStairs.size() * 2);
    fwrite(&tmp, sizeof(tmp),1,saved_file);

    // //write the npc location
    // //tmp set to 1st room's position
    // fwrite(&dungeon->rooms.get()[0]->position[curr_x], 1,1,saved_file);
    // fwrite(&dungeon->rooms.get()[0]->position[curr_y], 1,1,saved_file);

    //write the hardness of the dungeon
    for (int i = 0; i < DUNGEON_Y; ++i) {
        for (int j = 0; j < DUNGEON_X; ++j) {
            fwrite(&dungeon->map[i][j].hardness, 1,1,saved_file);
        }
    }

    //write the room number
    // tmp = htobe16(dungeon->num_rooms);
    fwrite(&tmp, 2,1,saved_file);

    // //write the room
    // for (int k = 0; k < dungeon->num_rooms; ++k) {
    //     fwrite(&dungeon->rooms[k]->position[curr_x],1,1,saved_file);
    //     fwrite(&dungeon->rooms[k]->position[curr_y],1,1,saved_file);
    //     fwrite(&dungeon->rooms[k]->size[curr_x],1,1,saved_file);
    //     fwrite(&dungeon->rooms[k]->size[curr_y],1,1,saved_file);
    // }

    // write the number of the up stairs
    tmp = htobe16(dungeon->upStairs.size());
    fwrite(&tmp,2,1,saved_file);

    // write the location of the up stairs
    for (uint8_t m = 0; m < DUNGEON_Y; ++m) {
        for (uint8_t i = 0; i < DUNGEON_X; ++i) {
            if (dungeon->map[m][i].terrain_type == ter_stairs_up){
                fwrite(&i,1,1,saved_file);
                fwrite(&m,1,1,saved_file);
            }
        }

    }

    // read the number of down stairs
    tmp = htobe16(dungeon->downStairs.size());
    fwrite(&tmp,2,1,saved_file);

    // read the location of the down stairs

    for (uint8_t m = 0; m < DUNGEON_Y; ++m) {
        for (uint8_t i = 0; i < DUNGEON_X; ++i) {
            if (dungeon->map[m][i].terrain_type == ter_stairs_down){
                fwrite(&i,1,1,saved_file);
                fwrite(&m,1,1,saved_file);
            }
        }

    }

    fclose(saved_file);

}

std::vector<std::unordered_map<std::string, std::string> > io::FileReader::readConfigureFile(std::string fileLocation){
    std::string lineBuffer;
    char *home = getenv("HOME");
    std::ifstream  configureFile;
    fileLocation = home + fileLocation;
    configureFile.open(fileLocation,std::ios::in);
    std::unordered_map<std::string, std::string> currentObject;
    std::vector<std::unordered_map<std::string, std::string> > result;

    std::getline(configureFile,lineBuffer);
    while(std::getline(configureFile,lineBuffer)){
        std::string tmpString;
        std::istringstream iss(lineBuffer);
        std::getline(iss,tmpString,' ');

        if (tmpString == "")
            continue;
        if (tmpString == "BEGIN"){
            std::getline(iss,tmpString, '\n');
            currentObject["TYPE"] = tmpString;
        }else if (tmpString == "DESC"){
            tmpString = "";
            while (lineBuffer[0] != '.'){
                std::getline(configureFile,lineBuffer);
                tmpString += lineBuffer;
            }
            currentObject["DESC"] = tmpString;
        }else if (tmpString == "END"){
            result.push_back(currentObject);
            currentObject = std::unordered_map<std::string, std::string>();
        }else{
            std::string key =  tmpString;
            std::getline(iss,tmpString, '\n');
            currentObject[key] = tmpString;
        }
    } 
    return result;
}