//
// Created by 陈瀚泽 on 2019-02-22.
//
#include "game.h"
#include <string>
#ifndef DUNGEON_COMS327_F19_IO_FILE_H
#define DUNGEON_COMS327_F19_IO_FILE_H


typedef enum struct file_type{
    file_not_set,
    file_configure,
    file_dungeon_saving
}file_type_t;

class file {
private:
    std::string * filePath = NULL;
    file_type_t fileType = file_type_t::file_not_set;
public:
    explicit file(std::string * string);
    int8_t read_saved_map(dungeon_t * dungeon);
    int8_t save_map_to_file(dungeon_t * dungeon);
};


#endif //DUNGEON_COMS327_F19_IO_FILE_H
