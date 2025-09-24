#include "drawing/lines.h"
#include <stdlib.h>
#include <ncurses.h>

void wfrDrawLine(wfrVec2 p1, wfrVec2 p2) {
    int x1 = p1.x;
    int y1 = p1.y;
    int x2 = p2.x;
    int y2 = p2.y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int steep = dy > dx;
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
    int size = 0;

    points[size].x = steep ? y : x;
    points[size].y = steep ? x : y;
    size++;

    int x_inc = (x2 > x1) ? 1 : -1;
    int y_inc = (y2 > y1) ? 1 : -1;

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
        points[size - 1].x = steep ? y : x;
        points[size - 1].y = steep ? x : y;
    }

    for (int i = 0; i < size; i++) {
        mvaddstr(points[i].y, points[i].x, "#");
    }
    refresh();

    free(points);
}