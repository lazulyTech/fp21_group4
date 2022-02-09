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
            if((xy.x-i)*(xy.x-i) + (xy.y-j)*(xy.y-j) < r*r) { img_putpixel(c, xy_); }
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

void enemy(struct color c, struct point xy){
    
}
void myUnit(struct color c, struct point xy){
    
}

void img_spreadCirc(struct color c, struct point xy, double l, int count, double r, double theta){
    int i;
    struct point xy_;
    for(i = 0; i < count; ++i){
        xy_.x = xy.x + (l * sin(theta*PI/180 + 2*i*PI/count));
        xy_.y = xy.y - (l * cos(theta*PI/180 + 2*i*PI/count));
        img_fillCircle(c, xy_, r);
    }
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

void shooting(struct color c, Point xy[], int frame, double length){
    int i;
    struct point xy_;
    img_fillRectangle(white, xy[frame], 5, 5);
    for (i = 0; i < frame+1; i++) {
        if (i%3 == 0) {
            xy_.x = xy[i].x;
            xy_.y = xy[i].y + 2*length*(frame - i) + 2;
            img_fillCircle(c, xy_, 3);
        }
    }
}
