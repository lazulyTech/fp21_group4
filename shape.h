#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include <stdlib.h>
#include "img.h"

void img_fillCircle(struct color c, struct point xy, double r);
void gradationBullet(struct color c, struct point xy);

void backGround(struct color c);

void enemyUnit(struct point xy);
void myUnit(struct point xy);

void img_fillRectangle(struct color c, struct point xy, double w, double h);

#endif

