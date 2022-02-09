// animate1 --- create animation using img lib.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "img.h"
#include "shape.h"

int main(void) {
    struct color c1 = { 0, 0, 255 };
    struct color c2 = { 255, 0, 0 };
    struct point enemyPoint = {300, 200};
    int a,b;
    struct point myUnitPoint[FRAME];
    for (a = 0; a < FRAME; a++) {
        myUnitPoint[a].x = WIDTH/2.0 + 50*sin(a /PI/5);
        myUnitPoint[a].y = 100 + 50*cos(a/PI/6);
    }
    int i;
//    img_clear();
//    img_spreadCirc(red, 300, 200, 100, 48, 4, 0);
//    img_write();
    for(i = 0; i < FRAME; ++i) {
        img_clear();
        backGround(black);
        int j;
        for (j = i; j >= 0; j-=15) {
            img_spreadCirc(cyan, enemyPoint, 1*j, 30, 4, 3*(i - j));
//            img_spreadCirc(cyan, enemyPoint, 1*j, 30, 4, 3*(i - j));
        }
        img_fillCircle(black, enemyPoint, 12);
        img_fillRectangle(green, enemyPoint, 10, 10);
        shooting(white, myUnitPoint, i, 3);
        img_write();
    }
    return 0;
}

