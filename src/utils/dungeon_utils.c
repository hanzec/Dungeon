//
// Created by chen_ on 2019/2/7.
//

#include "../../include/utils/dungeon_utils.h"

void print_dungeon_cli(dungeon_t *d)
{
    pair_t p;

    for (p[dim_y] = 0; p[dim_y] < DUNGEON_Y; p[dim_y]++) {
        for (p[dim_x] = 0; p[dim_x] < DUNGEON_X; p[dim_x]++) {
            if (d->character[p[dim_y]][p[dim_x]] == 'D'){
                putchar('D');
            }else if (d->character[p[dim_y]][p[dim_x]] == '@'){
                putchar('@');
            } else {
                switch (mappair(p)) {
                    case ter_wall:
                    case ter_wall_immutable:
                        putchar(' ');
                        break;
                    case ter_floor:
                    case ter_floor_room:
                        putchar('.');
                        break;
                    case ter_floor_hall:
                        putchar('#');
                        break;
                    case ter_debug:
                        putchar('*');
                        fprintf(stderr, "Debug character at %d, %d\n", p[dim_y], p[dim_x]);
                        break;
                    case ter_stairs_up:
                        putchar('<');
                        break;
                    case ter_stairs_down:
                        putchar('>');
                        break;
                    default:
                        break;
                }
            }
        }
        putchar('\n');
    }
}