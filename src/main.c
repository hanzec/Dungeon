//
// Created by chen_ on 2019/1/31.
//

#include "../include/game.h"
#include <curses.h>
#include <string.h>
#include <ncurses.h>

typedef enum file_action {
    no_select,
    graph_mode,
    read_saved_game,
} action_t;

int main(int argc, char *argv[]) {
    int8_t error_code;
    action_t action = no_select;

    if (argc !=1){
        fprintf(stderr, "Usage: %s <--save(-s)|--locad(-l)|-g(not working now)>\n", argv[0]); //<> required argument, [] optional argument.
        return - 1;
    } else{
        if (strcmp(argv[0],"--save") )
            action = write_game_to_file;
        else if (strcmp(argv[0],"--load"))
            action = read_saved_game;
        else if (strcmp(argv[0],"-g"))
            action = graph_mode;
        else
            fprintf(stderr, "Usage: %s <--save(-s)|--locad(-l)|-g(not working now)>\n", argv[0]); //<> required argument, [] optional argument.
    }

    switch (action){
        case no_select:
            return -1;
        case read_saved_game:
            load_dungeon(false);
            break;
        case write_game_to_file:
            break;
        case graph_mode:
            graph_mod();
            break;
    }
    return 0;
}
