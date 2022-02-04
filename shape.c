#include "shape.h"
#include "img.h"
#include <math.h>

#define PI 3.1415926535897932238462

void img_fillCircle(struct color c, double x, double y, double r) {
    int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
    int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
    int i, j;
    for(j = jmin; j <= jmax; ++j) {
        for(i = imin; i <= imax; ++i) {
            if((x-i)*(x-i) + (y-j)*(y-j) < r*r) { img_putpixel(c, i, j); }
        }
    }
}

void backGround(struct color c){
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            img_putpixel(c, x, y);
        }
    }
}

void img_spreadCirc(struct color c, double x, double y, double l, int count, double r, double theta){
    int i;
    for(i = 0; i < count; ++i){
        double x_ = x + (l * sin(theta*PI/180 + 2*i*PI/count));
        double y_ = y - (l * cos(theta*PI/180 + 2*i*PI/count));
        img_fillCircle(c, x_, y_, r);
    }
}

void img_fillRectangle(struct color c, double x, double y, double w, double h){
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            img_putpixel(c, x + i - w/2, y + j - h/2);
        }
    }
}

