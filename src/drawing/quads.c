#include "drawing/quads.h"
#include "drawing/lines.h"
#include "helpers.h"

void wfrDrawQuads(wfrVec2 p1, wfrVec2 p2, wfrVec2 p3, wfrVec2 p4, wfrColor color){
    wfrVec2 p[4] = { p1, p2, p3, p4 };
    wfrOrderPoints(p);
    wfrDrawLine(p[0], p[1], color);
    wfrDrawLine(p[1], p[2], color);
    wfrDrawLine(p[2], p[3], color);
    wfrDrawLine(p[3], p[0], color);
}