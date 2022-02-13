#include "shape.h"
#include "img.h"
#include <math.h>

void img_fillCircle(struct color c, struct point xy, double r) {
    int imin = (int)(xy.x - r - 1), imax = (int)(xy.x + r + 1);
    int jmin = (int)(xy.y - r - 1), jmax = (int)(xy.y + r + 1);
    int i, j;
    for(j = jmin; j <= jmax; ++j) {
        for(i = imin; i <= imax; ++i) {
            struct point xy_ = {i, j};
            if((xy.x-i)*(xy.x-i) + (xy.y-j)*(xy.y-j) < r*r) { 
                img_putpixel(c, xy_); 
            }
        }
    }
}

void gradationBullet(struct color c, struct point xy){
    double r = BULLET_SIZE;
    int imin = (int)(xy.x - r - 1), imax = (int)(xy.x + r + 1);
    int jmin = (int)(xy.y - r - 1), jmax = (int)(xy.y + r + 1);
    int i, j;
    for(j = jmin; j <= jmax; ++j) {
        for(i = imin; i <= imax; ++i) {
            struct point xy_ = {i, j};
            double length = (xy.x-i)*(xy.x-i) + (xy.y-j)*(xy.y-j);
            if(length < r*r/16) {
                img_putpixel(c, xy_);
            } else if (length < r*r*25/36) {
                struct color gradation;
                gradation.r = 3*(255-c.r) + c.r - 3*(255-c.r)/7;
                gradation.g = 3*(255-c.g) + c.g - 3*(255-c.g)/7;
                gradation.b = 3*(255-c.b) + c.b - 3*(255-c.b)/7;
                img_putpixel(gradation, xy_);
            } else if (length < r*r) {
                img_putpixel(white, xy_);
            }
        }
    }
}

void backGround(struct color c){
    struct point xy;
    for (xy.x = 0; xy.x < WIDTH; xy.x++) {
        for (xy.y = 0; xy.y < HEIGHT; xy.y++) {
            img_putpixel(c, xy);
        }
    }
}

void enemyUnit(struct point xy){
    img_fillCircle(black, xy, 12);
    img_fillRectangle(green, xy, 10, 10);
}
void myUnit(struct point xy){
    img_fillRectangle(red, xy, 10, 10);
    img_fillRectangle(white, xy, 6, 6);
}

void img_fillRectangle(struct color c, struct point xy, double w, double h){
    int i, j;
    struct point xy_;
    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            xy_.x = xy.x + i - w/2;
            xy_.y = xy.y + j - h/2;
            img_putpixel(c, xy_);
        }
    }
}


