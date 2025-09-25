#define _POSIX_C_SOURCE 199309L
#include "helpers.h"
#include <ncurses.h>
#include <time.h>
#include "internal/vectors.h"
#include <math.h>
#include <stdlib.h>

void wfrInit(){
    initscr();
    start_color();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
}

void wfrRefresh(){
    refresh();
}

void wfrTerminate(){
    endwin();
}

void wfrClear(){
    clear();
    refresh();
}

void wfrFrameSync(unsigned int fps){
    static struct timespec last = {0, 0};
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);

    long target_us = 1000000 / fps;
    long elapsed_us = (now.tv_sec - last.tv_sec) * 1000000 + 
                      (now.tv_nsec - last.tv_nsec) / 1000;

    if (elapsed_us < target_us) {
        struct timespec sleep_time;
        sleep_time.tv_sec = 0;
        sleep_time.tv_nsec = (target_us - elapsed_us) * 1000;
        nanosleep(&sleep_time, NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &last);
}

static wfrVec2 wfrCenter;

int wfrCompare(const void *a, const void *b) {
    const wfrVec2 *p1 = a;
    const wfrVec2 *p2 = b;

    float ang1 = atan2f(p1->y - wfrCenter.y, p1->x - wfrCenter.x);
    float ang2 = atan2f(p2->y - wfrCenter.y, p2->x - wfrCenter.x);

    return (ang1 > ang2) - (ang1 < ang2);
}

void wfrOrderPoints(wfrVec2 pts[4]) {
    float cx = ((float)pts[0].x + pts[1].x + pts[2].x + pts[3].x) / 4.0f;
    float cy = ((float)pts[0].y + pts[1].y + pts[2].y + pts[3].y) / 4.0f;

    wfrCenter.x = (unsigned short)(cx + 0.5f);
    wfrCenter.y = (unsigned short)(cy + 0.5f);

    qsort(pts, 4, sizeof(wfrVec2), wfrCompare);
}