#pragma once

#include "internal/vectors.h"

void wfrInit();
void wfrRefresh();
void wfrTerminate();
void wfrClear();
void wfrFrameSync(unsigned int fps);
int wfrCompare(const void *a, const void *b);
void wfrOrderPoints(wfrVec2 pts[4]);