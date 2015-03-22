
#include "fire.h"
#include "fssimplewindow.h"
#include <math.h>

Fire::Fire(){
    
}

void Fire::init(int x){
    (*this).x = x;
    f = 0;
    state = 0;
}

void Fire::draw(){
    int p = x+0; 
    if (p<=800 && p>=0){
        glShadeModel(GL_SMOOTH);
        glBegin(GL_POLYGON);
        glColor3ub(226, 197, 0);
        glVertex2i(p-0, 600-f);
        glColor3ub(226, 127, 0);
        glVertex2i(p-0, 604-f);
        glColor3ub(226, 110, 0);
        glVertex2i(p+1, 608-f);
        glColor3ub(226, 80, 0);
        glVertex2i(p+3, 611-f);
        glColor3ub(226, 60, 0);
        glVertex2i(p+5, 614-f);
        glColor3ub(226, 45, 0);
        glVertex2i(p+7, 618-f);
        glColor3ub(226, 30, 0);
        glVertex2i(p+7, 625-f);
        glColor3ub(226, 15, 0);
        glVertex2i(p+5, 629-f);
        glColor3ub(226, 0, 0);
        glVertex2i(p+2, 631-f);
        glColor3ub(226, 0, 0);
        glVertex2i(p-2, 631-f);
        glColor3ub(226, 15, 0);
        glVertex2i(p-5, 629-f);
        glColor3ub(226, 30, 0);
        glVertex2i(p-7, 625-f);
        glColor3ub(226, 45, 0);
        glVertex2i(p-7, 618-f);
        glColor3ub(226, 60, 0);
        glVertex2i(p-5, 614-f);
        glColor3ub(226, 80, 0);
        glVertex2i(p-3, 611-f);
        glColor3ub(226, 110, 0);
        glVertex2i(p-1, 608-f);
        glColor3ub(226, 127, 0);
        glVertex2i(p-0, 604-f);
        glColor3ub(226, 197, 0);
        glVertex2i(p-0, 600-f);
        glEnd();
       
        f=f+5;
        if(f>600)
            f=0;
    }
}
void Fire::destroy(){
    x = -100;
    y = -100;
    f = 0;
    
}
void Fire::update(Hero &hero,int right){
    if (right == 1 && hero.y<=550 && hero.blockstate == 0)
        x = x - 10;
	double a = hero.x-x;
	double b = hero.y-50-615+f;
    if (fabs(a)<25 && fabs(b)<50){
        hero.blood = hero.blood - 1;
        destroy();
    }
}

bool Fire::checkHit(int x, int y){
	double c = (*this).x-x;
	double d = 615-f-(y-50);
    if (fabs(c)<12 && fabs(d)<50)
        return true;
    return false;
}

