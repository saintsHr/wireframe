#include "drawing/triangles.h"
#include "drawing/lines.h"
#include "helpers.h"

void wfrDrawTriangles(wfrTriangle tri, wfrColor color){
    wfrVec2 p[3] = {tri.p[0], tri.p[0], tri.p[0]};
    wfrOrderPoints(p);

    wfrLine lin1;
    wfrLine lin2;
    wfrLine lin3;
    wfrLine lin4;

    lin1.p[0] = tri.p[0];
    lin1.p[1] = tri.p[1];
    lin2.p[0] = tri.p[1];
    lin2.p[1] = tri.p[2];
    lin3.p[0] = tri.p[2];
    lin3.p[1] = tri.p[0];

    wfrDrawLine(lin1, color);
    wfrDrawLine(lin2, color);
    wfrDrawLine(lin3, color);
}