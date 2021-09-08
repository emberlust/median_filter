#include "PGM.h"

#ifndef _FILTER_H
#define _FILTER_H

void filter(pgmData* myPGM, int range);
int* create_array(int* matrix, int range, int x, int y, int width, int height);
#endif
