#include "drawing/lines.h"

#include <stdlib.h>
#include <ncurses.h>

void wfrDrawLine(wfrLine lin, wfrColor color) {
    static unsigned long long id = 1;
    id++;
    if (id >= COLOR_PAIRS) id = 1;

    wfrVec2 p1 = lin.p[0];
    wfrVec2 p2 = lin.p[1];

    int x1 = p1.x;
    int y1 = p1.y;
    int x2 = p2.x;
    int y2 = p2.y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    unsigned short steep = dy > dx;
    if (steep) {
        int tmp;
        tmp = x1; x1 = y1; y1 = tmp;
        tmp = x2; x2 = y2; y2 = tmp;
        tmp = dx; dx = dy; dy = tmp;
    }

    int p = 2 * dy - dx;
    int x = x1;
    int y = y1;

    wfrVec2* points = malloc(sizeof(wfrVec2));
    unsigned short size = 0;

    points[size].x = (unsigned short)(steep ? y : x);
    points[size].y = (unsigned short)(steep ? x : y);
    size++;

    short x_inc = (x2 > x1) ? 1 : -1;
    short y_inc = (y2 > y1) ? 1 : -1;

    for (int i = 0; i < dx; i++) {
        if (p < 0) {
            p += 2 * dy;
        } else {
            p += 2 * (dy - dx);
            y += y_inc;
        }
        x += x_inc;

        size++;
        points = realloc(points, size * sizeof(wfrVec2));
        points[size - 1].x = (unsigned short)(steep ? y : x);
        points[size - 1].y = (unsigned short)(steep ? x : y);
    }

    init_pair(id, color, COLOR_BLACK);
    attron(COLOR_PAIR(id));
    for (int i = 0; i < size; i++) {
        mvaddstr(points[i].y, points[i].x, "#");
    }
    attroff(COLOR_PAIR(id));
    
    refresh();

    free(points);
}