//
// Created by chen_ on 2019/1/31.
//

#include <string.h>
#include <ncurses.h>
#include "../include/game.h"

typedef enum file_action {
    no_select,
    graph_mode,
    read_saved_game,
} action_t;

int main(int argc, char *argv[]) {

    game::newGame();

}
