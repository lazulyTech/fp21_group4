#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include <stdlib.h>
#include "img.h"

void img_fillCircle(struct color c, struct point xy, double r);

void backGround(struct color c);

void enemy(struct color c, struct point xy);
void myUnit(struct color c, struct point xy);

/*
    c: color of bullet
    x,y: Launch position
    l: radius of reference circle
    count: number of bullets
    r: radius of bullets
    theta: 
*/
void img_spreadCirc(struct color c, struct point xy, double l, int count, double r, double theta);

void img_fillRectangle(struct color c, struct point xy, double w, double h);

void shooting(struct color c, Point xy[], int frame, double length);
#endif

