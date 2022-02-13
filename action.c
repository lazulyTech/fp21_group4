#include "action.h"
#include "shape.h"
#include "img.h"
#include <math.h>

void img_spreadCirc(struct color c, struct point xy, double l, int count, double theta){
    int i;
    struct point xy_;
    for(i = 0; i < count; ++i){
        xy_.x = xy.x + (l * sin(theta*PI/180 + 2*i*PI/count));
        xy_.y = xy.y - (l * cos(theta*PI/180 + 2*i*PI/count));
        gradationBullet(c, xy_);
    }
}

void img_defeatedCirc(struct color c, struct point xy, double l, int count, double theta, double radius){
    int i;
    struct point xy_;
    for(i = 0; i < count; ++i){
        xy_.x = xy.x + (l * sin(theta*PI/180 + 2*i*PI/count));
        xy_.y = xy.y - (l * cos(theta*PI/180 + 2*i*PI/count));
        img_fillCircle(c, xy_, radius);
    }
}

void img_cuttedCirc(struct color c, struct point xy, double l, int count, double theta, double cutted){
    int i;
    struct point xy_;
    for (i = cutted/2; i < count - cutted/2; i++) {
        xy_.x = xy.x + (l * sin(theta*PI/180 + 2*i*PI/count));
        xy_.y = xy.y - (l * cos(theta*PI/180 + 2*i*PI/count));
        gradationBullet(c, xy_);
    }
}

void shooting(struct color c, Point xy[], int frame, double length){
    int i;
    struct point xy_;
    myUnit(xy[frame]);
    for (i = 0; i < frame+1; i++) {
        if (i%3 == 0) {
            xy_.y = xy[i].y + 2*length*(frame - i) + 2;
            int j;
            for (j = 0; j < 3; j++) {
                xy_.x = xy[i].x + 10*(j-1);
                img_fillCircle(c, xy_, 3);
            }
        }
    }
}
