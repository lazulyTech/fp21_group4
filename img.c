#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

Color white = {255, 255, 255};
Color black = {0, 0, 0};
Color red = {255, 0, 0};
Color green = {0, 255, 0};
Color blue = {0, 0, 255};
Color cyan = {0, 255, 255};
Color magenta = {255, 0, 255};
Color yellow = {255, 255, 0};

void img_clear(void) {
    int i, j;
    for(j = 0; j < HEIGHT; ++j) {
        for(i = 0; i < WIDTH; ++i) {
            buf[j][i][0] = buf[j][i][1] = buf[j][i][2] = 255;
        }
    }
}

void img_write(void) {
    sprintf(fname, "images/img%04d.ppm", ++filecnt);
    FILE *f = fopen(fname, "wb");
    if(f == NULL) {
        fprintf(stderr, "can't open %s\n", fname);
        exit(1);
    }
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(buf, sizeof(buf), 1, f);
    fclose(f);
}

void img_putpixel(struct color c, struct point xy) {
    if(xy.x < 0 || xy.x >= WIDTH || xy.y < 0 || xy.y >= HEIGHT) return;
    buf[HEIGHT-(int)xy.y-1][(int)xy.x][0] = c.r;
    buf[HEIGHT-(int)xy.y-1][(int)xy.x][1] = c.g;
    buf[HEIGHT-(int)xy.y-1][(int)xy.x][2] = c.b;
}

