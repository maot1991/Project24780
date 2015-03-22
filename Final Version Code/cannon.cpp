#include "cannon.h"
#include "fssimplewindow.h"
#include <math.h>
#include "DrawMonster.h"

const double PI3=3.1415927;
Cannon::Cannon(){ 
  
}

void Cannon::init(const int x,int dif){
    
    (*this).x = x;
    y = 0;
    degStatus = 0;
    degree = rand()%90-45;
    changer = dif;
    initchanger = dif;
}  

void Cannon::DegreeChange(){
    if (degree < -45)
        degStatus = 1;
    if (degree > 45)
        degStatus = 0;
    if (degStatus == 0)
        degree = degree - 0.2;
    if (degStatus == 1)
        degree = degree + 0.2;
}

void Cannon::update(Hero hero,int right,Cannonelement &e,int bossstate){
    
    if (right == 1 && hero.y<=500 && hero.blockstate == 0 && bossstate == 0)
        x = x - 10;
    DegreeChange();
    
    double deg = degree/180*PI3;
   // printf("degree=%lf",deg);
    if (changer == 0)
        e.addelement(x+35*cos(deg+3.1415/2), 600-y+45+35*sin(deg+3.1415/2),-deg);
}

void Cannon::draw(){
    
    double p = x;
    double deg = degree/180*PI3;
    
    y=600;
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
    glVertex2d(x-30,600-y);
    glVertex2d(x+30,600-y);
    glVertex2d(x+20,600-y-25);
    glVertex2d(x-20,600-y-25);
    glEnd();
    glColor3ub(100,100,100);
    glBegin(GL_POLYGON);
    glVertex2d(x+5,600-y+25);
    glVertex2d(x+5,600-y+30);
    glVertex2d(x-5,600-y+30);
    glVertex2d(x-5,600-y+25);
    glEnd();
    glColor3ub(255,128,0);
    glBegin(GL_POLYGON);
    glVertex2d(x+12,600-y+55);
    glVertex2d(x+18,600-y+30);
    glVertex2d(x-18,600-y+30);
    glVertex2d(x-12,600-y+55);
    glEnd();
    
    glColor3ub(100,3,0);
    glBegin(GL_POLYGON);
    glVertex2d(x-30,600-y);
    glVertex2d(x+30,600-y);
    glVertex2d(x+20,600-y+25);
    glVertex2d(x-20,600-y+25);
    glEnd();
    glColor3ub(100,100,100);
    glBegin(GL_LINE_LOOP);
    glVertex2d(x+5,600-y+25);
    glVertex2d(x+5,600-y+30);
    glVertex2d(x-5,600-y+30);
    glVertex2d(x-5,600-y+25);
    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(x+12,600-y+55);
    glVertex2d(x+18,600-y+30);
    glVertex2d(x-18,600-y+30);
    glVertex2d(x-12,600-y+55);
    glEnd();
    
    
    //draw gun
    
    glColor3ub(100,50,100);
    glBegin(GL_POLYGON);
    glVertex2d(x,600-y+45);
    glVertex2d(x+5*cos(deg),600-y+45+5*sin(deg));
    
    glVertex2d(x+5*cos(deg)+35*cos(deg+3.1415/2),600-y+45+5*sin(deg)+35*sin(deg+3.1415/2));
    glVertex2d(x-5*cos(deg)+35*cos(deg+3.1415/2),600-y+45-5*sin(deg)+35*sin(deg+3.1415/2));
    
    glVertex2d(x-5*cos(deg),600-y+45-5*sin(deg));
    
    glColor3ub(50,50,50);
	glEnd();

    DrawCircle(x,600-y+45,7,1);
    
    
    
    if (p<=800 && p>=0 && changer == 0){
        
        changer = initchanger;
        
    }
    if (p<=800 && p>=0 && changer > 0){
        
        changer--;
    }
    
}
