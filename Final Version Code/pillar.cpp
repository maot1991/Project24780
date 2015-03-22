#include "fssimplewindow.h"
#include "pillar.h"
#include <math.h>


Pillar::Pillar(){
   
}
void Pillar::init(int x,int y){
    f = 0;
    state = 0;
    (*this).x = x;
    (*this).y = y;
}
void Pillar::update(Hero &hero,int right,int bossstate){
    if (f+50>hero.y-100 && hero.x+25<=x-25 && hero.x+25>x-35)
        hero.blockstate =1;
    if (right == 1 && hero.y<=500 && hero.blockstate == 0 && bossstate == 0)
        x = x - 10;
    //printf("hx=%d  hy=%d  x=%d  y=%d\n",hero.x,hero.y,x,50+f);
    if (hero.x+25>x-25 && hero.x-25<x+25 && 50+f>hero.y-100){
        hero.blood = 0;
        printf("pressed\n");
        return;
    }
    
  
    
    if (state == 0 && f<y-50)
        f = f+ 5;
    else if (state == 0 && f>=y-50){
        state =1;
        f=f-5;
    }
    else if (state == 1 && f > 0)
        f = f - 5;
    else if (state == 1 && f <= 0){
        state = 0;
        f=f+5;
    }
 
}

void Pillar::draw(){
    int p = x;
    if (p<=800 && p>=0){
        
        glShadeModel(GL_SMOOTH);
        glBegin(GL_POLYGON);
        glColor3ub(115, 128, 90);
        glVertex2i(p-25, 0);
        glVertex2i(p-15, 0);
        glVertex2i(p-15, 50+f);
        glVertex2i(p-25, 50+f);
        glEnd();
        glBegin(GL_POLYGON);
          glColor3ub(209, 224, 140);
        glVertex2i(p+15, 0);
        glVertex2i(p-15, 0);
        glVertex2i(p-15, 50+f);
        glVertex2i(p+15, 50+f);
        glEnd();
        glBegin(GL_POLYGON);
          glColor3ub(115, 128, 90);
        glVertex2i(p+25, 0);
        glVertex2i(p+15, 0);
        glVertex2i(p+15, 50+f);
        glVertex2i(p+25, 50+f);
        glEnd();
        
      
    }
}

