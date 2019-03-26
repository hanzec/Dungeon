//
// Created by chen_ on 2019/2/6.
//

#ifndef DUNGEON_COMS327_F19_IO_FILE_H
#define DUNGEON_COMS327_F19_IO_FILE_H

#include "gameCommon.h"

namespace io {
    class fileReader{
    private:
        fileReader(/* args */);
        ~fileReader();
    public:
        static int write_operation(dungeon_t *d);
        static int read_operation(dungeon_t *dungeon, char *path);
    };
    
}


#endif //DUNGEON_COMS327_F19_IO_FILE_H
