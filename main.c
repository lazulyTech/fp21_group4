// animate1 --- create animation using img lib.
#include "img.h"
#include "shape.h"

int main(void) {
    struct color c1 = { 0, 0, 255 };
    struct color c2 = { 255, 0, 0 };
    int i;
//    img_clear();
//    img_spreadCirc(red, 300, 200, 100, 48, 4, 0);
//    img_write();
    for(i = 0; i < WIDTH/2; ++i) {
        img_clear();
        backGround(black);
        int j;
        for (j = i; j >= 0; j-=15) {
            img_spreadCirc(red, 300, 200, 1*j, 30, 4, 3*(i - j));
            img_spreadCirc(red, 300, 200, 1*j, 30, 4, 3*(i - j));
        }
        img_fillCircle(black, 300, 200, 12);
        img_fillRectangle(green, 300, 200, 10, 10);
        img_write();
    }
    return 0;
}

