//
// Created by chen_ on 2019/2/6.
//

#ifndef DUNGEON_COMS327_F19_IO_FILE_H
#define DUNGEON_COMS327_F19_IO_FILE_H

#include <vector>
#include "GameCommon.h"
#include <unordered_map>

namespace io {
    class FileReader{
    private:
        FileReader(/* args */);
        ~FileReader();
    public:
        static int write_operation(dungeon_t *d);
        static int read_operation(dungeon_t *dungeon, char *path);
        static std::vector<std::unordered_map<std::string, std::string> > readConfigureFile(std::string fileLocation);
    };
    
}


#endif //DUNGEON_COMS327_F19_IO_FILE_H
