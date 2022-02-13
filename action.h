#ifndef ACTION_H
#define ACTION_H

#include <stdio.h>
#include <stdlib.h>
#include "img.h"
#include "shape.h"

/*
    c: color of bullet
    x,y: Launch position
    l: radius of reference circle
    count: number of bullets
    r: radius of bullets
    theta: 
*/
void img_spreadCirc(struct color c, struct point xy, double l, int count, double theta);
void img_defeatedCirc(struct color c, struct point xy, double l, int count, double theta, double radius);

void img_cuttedCirc(struct color c, struct point xy, double l, int count, double theta, double cutted);

void shooting(struct color c, Point xy[], int frame, double length);

#endif

