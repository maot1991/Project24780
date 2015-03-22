#include<stdio.h>
#include<stdlib.h>
#include "fssimplewindow.h"
#include "sky.h"

void sky::initialize(){
glBegin(GL_QUADS);
glColor3ub(0,188,225);
glVertex2i(0,600);
glVertex2i(10000,600);
glVertex2i(10000,0);
glVertex2i(0,0);
glEnd();
}