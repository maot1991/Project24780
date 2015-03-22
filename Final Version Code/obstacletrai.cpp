#include<stdio.h>
#include<stdlib.h>

#include "fssimplewindow.h"
#include "obstacletrai.h"

void obstacletrai::initialize(int x,int y)
{
    x1 = x;
    y1 = y;
}

void obstacletrai::draw()
{
    glBegin(GL_QUADS);
    glColor3ub(200,200,192);
    glVertex2i(x1,y1);
    glVertex2i(x1+20,y1);
    glVertex2i(x1+20-5,y1-100);
    glVertex2i(x1+10, y1-100);
    glVertex2i(x1+5, y1-100);
    glEnd();
}

void obstacletrai::change()
{
    int v=10;
    int t=1;
    x1=x1-v*t;
}

void obstacletrai::update()
{
    int key = FsInkey();
    
    switch(key)
    {
        case FSKEY_RIGHT:
            change();
    }
}