#include "helpers.h"
#include <ncurses.h>

void wfrInit(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

void wfrRefresh(){
    refresh();
}

void wfrTerminate(){
    endwin();
}