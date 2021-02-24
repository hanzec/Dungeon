#ifndef DUNGEON_V1_01_DISPLAY_COMMON_H
#define DUNGEON_V1_01_DISPLAY_COMMON_H

// defaule window Size
static int DEFAULT_TERMINAL_HEIGHT = 24;
static int DEFAULT_TERMINAL_LENGTH = 80;

// default Window & Panel size
static int PLAYER_WINDOW_X = 0;
static int PLAYER_WINDOW_Y = 23;
static int PLAYER_WINDOW_HEIGHT = 2;
static int PLAYER_WINDOW_LENGTH = DEFAULT_TERMINAL_LENGTH;

static int STATUS_WINDOW_X = 0;
static int STATUS_WINDOW_Y = 0;
static int STATUS_WINDOW_HEIGHT = 2;
static int STATUS_WINDOW_TIME_SLOT_LENGTH = 12;
static int STATUS_WINDOW_LENGTH = DEFAULT_TERMINAL_LENGTH;


// window & panel color configuration
static int PAIR_PANEL  = 4;
static int PAIR_STATUS_BAR = 1;
static int PAIR_DUNGEON_WINDOW = 2;
static int PAIR_CHARACTER_STATUS = 3;

// monstor & Items color configuration
static int PAIR_RED = 5;
static int PAIR_BLUE = 6;
static int PAIR_CYAN = 7;
static int PAIR_GREEN = 8;
static int PAIR_WHITE = 9;
static int PAIR_BLACK = 10;
static int PAIR_YELLOW = 11;
static int PAIR_MAGENTA = 12;

#endif