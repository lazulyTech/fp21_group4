#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include <stdlib.h>
#include "img.h"

void img_fillCircle(struct color c, double x, double y, double r);

void backGround(struct color c);

/*
    c: color of bullet
    x,y: Launch position
    l: radius of reference circle
    count: number of bullets
    r: radius of bullets
    theta: 
*/
void img_spreadCirc(struct color c, double x, double y, double l, int count, double r, double theta);

void img_fillRectangle(struct color c, double x, double y, double w, double h);

#endif

