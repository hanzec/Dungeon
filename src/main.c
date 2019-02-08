//
// Created by chen_ on 2019/1/31.
//
#import <stdio.h>
#include <curses.h>
#include <string.h>
#include <ncurses.h>

typedef enum file_action {
    read_saved_game,
    write_saved_name,
} file_action_t;

const int base_width = 80;
const int base_height = 21;

int8_t text_mod(int argc, char *argv[]){
    file_action_t action;

    if (argc !=2){
        fprintf(stderr, "Usage: %s <-wt|-wb|-rt|-rb>\n", argv[0]); //<> required argument, [] optional argument.
        return - 1;
    } else{

    }

    switch (action){
        case :
    }
}

void graph_mod(){
    //todo add welcome menu here;
};

int main(int argc, char *argv[]) {
    int8_t error_code;

    if (argc != 1){
        error_code = text_mod(argc,argv);

        if (error_code != 0){
            return -1;
        }
    }else{
        if (!strcmp(argv[0],"-g")){
            printf("error input");
            return -1;
        } else{
            graph_mod();
        }
    }

    return 0;
}
