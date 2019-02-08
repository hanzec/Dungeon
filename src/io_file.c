//
// Created by chen_ on 2019/2/6.
//

#include <stdlib.h>
#include <memory.h>
#include <bits/types/FILE.h>
#include <stdio.h>
#include "io_file.h"


int read_dungeon(){
    FILE *saved_file;
    char *home = getenv("HOME");
    char *path = malloc(strlen(home) + strlen("/rlg327/dungeon") + 1);

    strcpy(path,home);
    strcat(path,"/.rlg327/dungeon");
    saved_file = fopen(path,"r");

}
int wrie_dunegeon(){}
