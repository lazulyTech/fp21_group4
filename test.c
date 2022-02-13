//
// test.c
// Created by lazulyTech
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "img.h"
#include "shape.h"
#include "action.h"

int main(void) {
    struct point enemyPoint = {300, 200};
    struct point myUnitPoint[FRAME];
    
    int frame_stop = 35;
    int frame_cuttedCirc = 240;
    int frame_second = 600;
    int frame_moveEnemy = 100;
    int frame_back = 1000;
    
    int a;
    for (a = 0; a < FRAME; a++) {
        myUnitPoint[a].x = WIDTH/2.0;
        myUnitPoint[a].y = HEIGHT/2.0 - 100;
    }
    for (a = 0; a < frame_stop; a++) { //wait
        myUnitPoint[a].x = WIDTH/2.0;
        myUnitPoint[a].y = HEIGHT/2.0 - 100;
    }
    for (a = 0; a < frame_cuttedCirc; a++) { // counterClockwise
        myUnitPoint[a+frame_stop].x = WIDTH/2.0 + 100*sin(a/PI/6);
        myUnitPoint[a+frame_stop].y = HEIGHT/2.0- 100*cos(a/PI/6);
    }
    for (a = 0; a < frame_cuttedCirc; a++) { // clockwise
        myUnitPoint[a+frame_stop+frame_cuttedCirc].x = WIDTH/2.0 + 100*sin(-a/PI/6);
        myUnitPoint[a+frame_stop+frame_cuttedCirc].y = HEIGHT/2.0- 100*cos(-a/PI/6);
    }
    for (a = 0; a < frame_second+frame_moveEnemy-frame_stop-2*frame_cuttedCirc; a++) { //wait
        myUnitPoint[a+frame_stop+2*frame_cuttedCirc].x = WIDTH/2.0;
        myUnitPoint[a+frame_stop+2*frame_cuttedCirc].y = HEIGHT/2.0 - 100;
    }
    for (a = 0; a < frame_second+frame_moveEnemy+50 -(frame_stop+2*frame_cuttedCirc); a++) { //wait
        myUnitPoint[a+frame_second+frame_moveEnemy].x = 300 + 134*a/50.0;
        myUnitPoint[a+frame_second+frame_moveEnemy].y = 100 + 183*a/50.0;
    }
    for (a = 0; a < frame_back - (frame_second + frame_moveEnemy + 50); a++) {
        myUnitPoint[a+frame_second + frame_moveEnemy + 50].x =   0 + 450 * cos(-(15 + 38*(a*0.5)/100.0)*PI/180);
        myUnitPoint[a+frame_second + frame_moveEnemy + 50].y = 400 + 450 * sin(-(15 + 38*(a*0.5)/100.0)*PI/180);
    }
    for (a = 0; a < 50; a++) {
        myUnitPoint[a+frame_back].x = 450 + 389*cos(-(133 + a/2.0)*PI/180);
        myUnitPoint[a+frame_back].y = 300 + 389*sin(-(133 + a/2.0)*PI/180);
    }
    
    printf("%d, %f, %f\n", a+frame_back-1, myUnitPoint[a+frame_back-1].x, myUnitPoint[a+frame_back-1].y);
    for (a = 0; a < 50; a++) {
        myUnitPoint[a+frame_back+50].x = 90 + 210*a/50.0;
        myUnitPoint[a+frame_back+50].y = 151 - 51*a/50.0;
    }
    int i;
    for(i = 0; i < FRAME; ++i) {
        img_clear();
        backGround(black);

        // counterClockwise
        if (i < frame_cuttedCirc) {
            int j;
            for (j = i; j >= 0; j-=5) {
                img_cuttedCirc(cyan, enemyPoint, 3*j, 30, 3*(i - j), 4);
            }
        } else {
            int j;
            for (j = i; j >= i-frame_cuttedCirc; j-=5) {
                img_cuttedCirc(cyan, enemyPoint, 3*j, 30, 3*(i - j), 4);
            }
        }
        
        // clockwise
        if (i >= frame_cuttedCirc) {
            if (i < 2*frame_cuttedCirc) {
                int j;
                for (j = i-frame_cuttedCirc; j >= 0; j-=5) {
                    img_cuttedCirc(cyan, enemyPoint, 3*j, 30, -3*(i-frame_cuttedCirc - j), 4);
                }
            } else {
                int j;
                for (j = i-frame_cuttedCirc; j >= i-2*frame_cuttedCirc; j-=5) {
                    img_cuttedCirc(cyan, enemyPoint, 3*j, 30, -3*(i-frame_cuttedCirc - j), 4);
                }
            }
        }
        
        // end
        if (i >= frame_second && i < frame_second + frame_moveEnemy) {
            struct point enemyPoint1, enemyPoint2;
            enemyPoint1.x = WIDTH/2.0 - WIDTH/4.0/frame_moveEnemy * (i - frame_second);
            enemyPoint1.y = HEIGHT/2.0 +HEIGHT/4.0/frame_moveEnemy* (i - frame_second);
            enemyPoint2.x = WIDTH/2.0 + WIDTH/4.0/frame_moveEnemy * (i - frame_second);
            enemyPoint2.y = enemyPoint1.y;
            enemyUnit(enemyPoint1);
            enemyUnit(enemyPoint2);
        }
        
        // double 
        if (i >= frame_second + frame_moveEnemy + 50) {
            int minus = frame_second + frame_moveEnemy + 50;
            int j;
            for (j = i-minus; j >= 0; j-=10) {
                struct point enemyPoint1 = {WIDTH/4.0, 3.0*HEIGHT/4.0}, enemyPoint2 = {3.0*WIDTH/4.0, 3.0*HEIGHT/4.0};
                struct color orange = {255, 50,0};
                if (i-minus - j <= 10*10) {
                    img_spreadCirc(orange, enemyPoint1, 2*j, 10, 3*(i-minus - j));
                    img_spreadCirc(orange, enemyPoint2, 2*j, 10, 3*(i-minus - j));
                }
            }
        }
        if (i >= frame_back + 100) {
            int minus = frame_back + 100;
            int j;
            for (j = i-minus; j >= 0; j-=1) {
                struct point enemyPoint1 = {WIDTH/4.0, 3.0*HEIGHT/4.0}, enemyPoint2 = {3.0*WIDTH/4.0, 3.0*HEIGHT/4.0};
                struct color orange = {255, 50,0};
                if (i-minus - j <= 30) {
                    img_spreadCirc(orange, enemyPoint1, 3*j, 60, 2*(i-minus - j));
                    img_spreadCirc(orange, enemyPoint2, 3*j, 60, 2*(i-minus - j));
                }
            }
        }
        if (i >= frame_back + 100+85) {
            int minus = frame_back + 100+85;
            int j;
            for (j = i-minus; j >= 0; j-=1) {
                if (i-minus - j <= 1 && 3*j < 150) {
                    img_defeatedCirc(white, myUnitPoint[i], 3*j, 8, 0, 13);
                }
            }
        }

        // plot enemies Unit
        if (i < frame_second) {
            //img_fillCircle(black, enemyPoint, 12);
            //img_fillRectangle(green, enemyPoint, 10, 10);
            enemyUnit(enemyPoint);
        }
        if (i >= frame_second + frame_moveEnemy) {
            struct point enemyPoint1 = {WIDTH/4.0, 3.0*HEIGHT/4.0}, enemyPoint2 = {3.0*WIDTH/4.0, 3.0*HEIGHT/4.0};
            enemyUnit(enemyPoint1);
            enemyUnit(enemyPoint2);
        }
        // plot myUnit
        if (i < frame_back + 100+85) {
            myUnit(myUnitPoint[i]);
        }
        //shooting(white, myUnitPoint, i, 3);
        
        img_write();
    }
    return 0;
}

