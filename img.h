#ifndef IMG_H
#define IMG_H

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 600
#define HEIGHT 400
typedef struct color { unsigned char r, g, b; }Color;
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
void img_putpixel(struct color c, int x, int y);

#endif

