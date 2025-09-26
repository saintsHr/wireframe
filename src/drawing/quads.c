#include "drawing/quads.h"
#include "drawing/lines.h"
#include "helpers.h"

void wfrDrawQuads(wfrQuad qd, wfrColor color){
    wfrVec2 p[4] = { qd.p[0], qd.p[1], qd.p[2], qd.p[3] };
    wfrOrderPoints(p);

    wfrLine lin1;
    wfrLine lin2;
    wfrLine lin3;
    wfrLine lin4;

    lin1.p[0] = qd.p[0];
    lin1.p[1] = qd.p[1];
    lin2.p[0] = qd.p[1];
    lin2.p[1] = qd.p[2];
    lin3.p[0] = qd.p[2];
    lin3.p[1] = qd.p[3];
    lin4.p[0] = qd.p[3];
    lin4.p[1] = qd.p[0];

    wfrDrawLine(lin1, color);
    wfrDrawLine(lin1, color);
    wfrDrawLine(lin1, color);
    wfrDrawLine(lin1, color);
}