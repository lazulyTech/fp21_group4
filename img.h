#ifndef IMG_H
#define IMG_H

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926535897932238462

#define WIDTH 600
#define HEIGHT 400
#define FRAME 1300
#define BULLET_SIZE 4

typedef struct color { 
    unsigned char r, g, b; 
}Color;

typedef struct point {
    double x;
    double y;
}Point;
// colors
extern Color white;
extern Color black;
extern Color red;
extern Color green;
extern Color blue;
extern Color cyan;
extern Color magenta;
extern Color yellow;

void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, struct point xy);

#endif

