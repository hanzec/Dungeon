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

double diceToDouble(const std::string &diceString){
    double result;
    int dice,size;
    std::string tmpString;
    srand (time(NULL));
    std::istringstream iss(diceString);

    std::getline(iss,tmpString,'+');
    result = std::stoi(tmpString);
    std::getline(iss,tmpString,'d');
    dice = std::stoi(tmpString);
    std::getline(iss,tmpString,'\0');
    size = std::stoi(tmpString);

    for (int i = 0; i < dice; ++i)
        result += rand()%(size + 1);
    return result;
}

int main(int argc, char *argv[]) {

    game::newGame();

}
