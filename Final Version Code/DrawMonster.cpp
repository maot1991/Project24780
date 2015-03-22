
#include "fssimplewindow.h"
#include <math.h>
#include "DrawMonster.h"

void DrawCircle(int cx,int cy,int rad,int indicator)
{
    if(indicator==0)
        glBegin(GL_LINE_LOOP);
    else if(indicator==1)
        glBegin(GL_POLYGON);
    for(int angle=0; angle<=360; angle+=30)
    {
        double a=(double)angle*2.0*PI/360.0;
        double s=sin(a);
        double c=cos(a);
        
        glVertex2d(cx+c*rad,cy+s*rad);
    }
    glEnd();
}
void DrawSemicircle(int cx,int cy,int rad, int orientation)
{
    int theta=0;
    if(orientation==1)
    {
        theta=0;
    }
    else if(orientation==0)
    {
        theta=180;
    }
    glBegin(GL_POLYGON);
    for(int angle=theta; angle<=theta+180; angle+=10)
    {
        double a=(double)angle*2.0*PI/360.0;
        double s=sin(a);
        double c=cos(a);
        
        glVertex2d(cx+c*rad,cy+s*rad);
    }
    
    glEnd();
}

void DrawMonster1(int x, int y,int state,double theta)//battery
{
    if(state==0)//left
    {
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x-30,y);
        glVertex2d(x+30,y);
        glVertex2d(x+20,y-25);
        glVertex2d(x-20,y-25);
        glEnd();
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x+5,y-25);
        glVertex2d(x+5,y-30);
        glVertex2d(x-5,y-30);
        glVertex2d(x-5,y-25);
        glEnd();
        glColor3ub(255,128,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+12,y-55);
        glVertex2d(x+18,y-30);
        glVertex2d(x-18,y-30);
        glVertex2d(x-12,y-55);
        glEnd();
        
        glColor3ub(100,100,100);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-30,y);
        glVertex2d(x+30,y);
        glVertex2d(x+20,y-25);
        glVertex2d(x-20,y-25);
        glEnd();
        glColor3ub(100,100,100);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+5,y-25);
        glVertex2d(x+5,y-30);
        glVertex2d(x-5,y-30);
        glVertex2d(x-5,y-25);
        glEnd();
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+12,y-55);
        glVertex2d(x+18,y-30);
        glVertex2d(x-18,y-30);
        glVertex2d(x-12,y-55);
        glEnd();

        
        //draw gun
        
        glColor3ub(100,50,100);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-45);
        glVertex2d(x+3*cos(theta*PI/180),y-45-3*sin(theta*PI/180));
        
        glVertex2d(x+3*cos(theta*PI/180)+35*cos(theta*PI/180+PI/2),y-45-3*sin(theta*PI/180)-35*sin(theta*PI/180+PI/2));
        glVertex2d(x-3*cos(theta*PI/180)+35*cos(theta*PI/180+PI/2),y-45+3*sin(theta*PI/180)-35*sin(theta*PI/180+PI/2));
        
        glVertex2d(x-3*cos(theta*PI/180),y-45+3*sin(theta*PI/180));
        
		
        glEnd();
        glColor3ub(50,50,50);
        DrawCircle(x,y-45,7,1);
        

        
    }
    if(state==1)//right
    {
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x-30,y);
        glVertex2d(x+30,y);
        glVertex2d(x+20,y-25);
        glVertex2d(x-20,y-25);
        glEnd();
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x+5,y-25);
        glVertex2d(x+5,y-30);
        glVertex2d(x-5,y-30);
        glVertex2d(x-5,y-25);
        glEnd();
        glColor3ub(255,128,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-12,y-55);
        glVertex2d(x-18,y-30);
        glVertex2d(x+18,y-30);
        glVertex2d(x+12,y-55);
        glEnd();
        
        glColor3ub(100,100,100);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-30,y);
        glVertex2d(x+30,y);
        glVertex2d(x+20,y-25);
        glVertex2d(x-20,y-25);
        glEnd();
        glColor3ub(100,100,100);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+5,y-25);
        glVertex2d(x+5,y-30);
        glVertex2d(x-5,y-30);
        glVertex2d(x-5,y-25);
        glEnd();
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+12,y-55);
        glVertex2d(x+18,y-30);
        glVertex2d(x-18,y-30);
        glVertex2d(x-12,y-55);
        glEnd();

        //draw gun
        
        glColor3ub(100,50,100);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-45);
        glVertex2d(x-3*cos(theta*PI/180),y-45-3*sin(theta*PI/180));
        
        glVertex2d(x-3*cos(theta*PI/180)-35*cos(theta*PI/180+PI/2),y-45-3*sin(theta*PI/180)-35*sin(theta*PI/180+PI/2));
        glVertex2d(x+3*cos(theta*PI/180)-35*cos(theta*PI/180+PI/2),y-45+3*sin(theta*PI/180)-35*sin(theta*PI/180+PI/2));
        
        glVertex2d(x+3*cos(theta*PI/180),y-45+3*sin(theta*PI/180));
        
        glEnd();
        glColor3ub(50,50,50);
        DrawCircle(x,y-45,7,1);
        
       

    }
}

void DrawMonster2(int x,int y,int state)//robot
{
    if(state==0)//left
    {
        glColor3ub(100,100,100);
        DrawCircle(x-10,y,5,1);
        DrawCircle(x+10,y,5,1);
        glColor3ub(255,100,0);
        DrawCircle(x,y-12,12,1);
        glColor3ub(0,0,0);
        DrawCircle(x,y-12,12,0);
        DrawCircle(x,y-43,20,0);
        glColor3ub(255,128,0);
        DrawCircle(x,y-43,20,1);

        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-45);
        glVertex2d(x-15,y-45);
        glVertex2d(x-15,y-50);
        glVertex2d(x,y-50);
        glEnd();
        
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-14);
        glVertex2d(x,y-18);
        glVertex2d(x-15,y-18);
        glVertex2d(x-15,y-14);
        glEnd();
        
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x-15,y-24);
        glVertex2d(x-15,y-20);
        glVertex2d(x-30,y-18);
        glVertex2d(x-30,y-26);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2d(x-15,y-21);
        glVertex2d(x-15,y-15);
        glVertex2d(x-17,y-15);
        glVertex2d(x-17,y-21);
        glEnd();

        

        
    }
    if(state==1)//right
    {
        glColor3ub(100,100,100);
        DrawCircle(x-10,y,5,1);
        DrawCircle(x+10,y,5,1);
        glColor3ub(255,100,0);
        DrawCircle(x,y-12,12,1);
        glColor3ub(0,0,0);
        DrawCircle(x,y-12,12,0);
        DrawCircle(x,y-43,20,0);
        glColor3ub(255,128,0);
        DrawCircle(x,y-43,20,1);
        
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-45);
        glVertex2d(x+15,y-45);
        glVertex2d(x+15,y-50);
        glVertex2d(x,y-50);
        glEnd();
        
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-14);
        glVertex2d(x,y-18);
        glVertex2d(x+15,y-18);
        glVertex2d(x+15,y-14);
        glEnd();
        
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x+15,y-24);
        glVertex2d(x+15,y-20);
        glVertex2d(x+30,y-18);
        glVertex2d(x+30,y-26);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2d(x+15,y-21);
        glVertex2d(x+15,y-15);
        glVertex2d(x+17,y-15);
        glVertex2d(x+17,y-21);
        glEnd();
        

    }
}

void DrawMonster3(int x,int y,int state)//mouse
{
    if(state==0)//left
    {
        glColor3ub(160,160,160);
        glBegin(GL_POLYGON);
        glVertex2d(x-36,y-8);
        glVertex2d(x+30,y-8);
        glVertex2d(x+30,y-28);
        glVertex2d(x+26,y-32);
        glVertex2d(x+24,y-32);
        glVertex2d(x-18,y-22);
        glEnd();
        glColor3ub(0,0,0);
        DrawCircle(x-20,y-4,4,1);
        DrawCircle(x+20,y-4,4,1);
        glColor3ub(160,160,160);
        glBegin(GL_TRIANGLES);
        glVertex2d(x-28,y-8);
        glVertex2d(x-10,y-8);
        glVertex2d(x-14,y-36);
        glEnd();
        glColor3ub(255,0,0);
        DrawCircle(x-20,y-14,3,1);
        glBegin(GL_QUADS);
        glColor3ub(160,160,160);
        glVertex2d(x+30,y-14);
        glVertex2d(x+40,y-14);
        glVertex2d(x+40,y-18);
        glVertex2d(x+30,y-18);
        glEnd();

    }
    else if(state==1)//right
    {
        glColor3ub(160,160,160);
        glBegin(GL_POLYGON);
        glVertex2d(x+36,y-8);
        glVertex2d(x-30,y-8);
        glVertex2d(x-30,y-28);
        glVertex2d(x-26,y-32);
        glVertex2d(x-24,y-32);
        glVertex2d(x+18,y-22);
        glEnd();
        glColor3ub(0,0,0);
        DrawCircle(x+20,y-4,4,1);
        DrawCircle(x-20,y-4,4,1);
        glColor3ub(160,160,160);
        glBegin(GL_TRIANGLES);
        glVertex2d(x+28,y-8);
        glVertex2d(x+10,y-8);
        glVertex2d(x+14,y-36);
        glEnd();
        glColor3ub(255,0,0);
        DrawCircle(x+20,y-14,3,1);
        glBegin(GL_QUADS);
        glColor3ub(160,160,160);
        glVertex2d(x-30,y-14);
        glVertex2d(x-40,y-14);
        glVertex2d(x-40,y-18);
        glVertex2d(x-30,y-18);
        glEnd();

    }
}
void DrawMonster4(int x,int y,int state)//tank
{
    if(state==0)//left
    {
        
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x-15,y-30);
        glVertex2d(x-10,y-35);
        glVertex2d(x-35,y-60);
        glVertex2d(x-40,y-55);
        glEnd();
    
        glColor3ub(50,50,100);
        glBegin(GL_POLYGON);
        glVertex2d(x-29,y-56);
        glVertex2d(x-36,y-49);
        glVertex2d(x-52,y-63);
        glVertex2d(x-43,y-72);
        glEnd();
        
        glColor3ub(255,128,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-30,y-14);
        glVertex2d(x+30,y-14);
        glVertex2d(x+30,y-30);
        glVertex2d(x+15,y-44);
        glVertex2d(x-15,y-44);
        glVertex2d(x-30,y-30);
        glEnd();
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-30,y-14);
        glVertex2d(x+30,y-14);
        glVertex2d(x+30,y-30);
        glVertex2d(x+15,y-45);
        glVertex2d(x-15,y-45);
        glVertex2d(x-30,y-30);
        glEnd();
        glColor3ub(0,0,0);
        DrawCircle(x-26,y-15,15,1);
        DrawCircle(x+26,y-15,15,1);
        
        glColor3ub(200,100,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-12,y-45);
        glVertex2d(x-12,y-50);
        glVertex2d(x+12,y-50);
        glVertex2d(x+12,y-45);
        glEnd();
       
        
    }
    else if(state==1)//right
    {
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x+15,y-30);
        glVertex2d(x+10,y-35);
        glVertex2d(x+35,y-60);
        glVertex2d(x+40,y-55);
        glEnd();
        
        glColor3ub(50,50,100);
        glBegin(GL_POLYGON);
        glVertex2d(x+29,y-56);
        glVertex2d(x+36,y-49);
        glVertex2d(x+52,y-63);
        glVertex2d(x+43,y-72);
        glEnd();
        
        glColor3ub(255,128,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+30,y-14);
        glVertex2d(x-30,y-14);
        glVertex2d(x-30,y-30);
        glVertex2d(x-15,y-44);
        glVertex2d(x+15,y-44);
        glVertex2d(x+30,y-30);
        glEnd();
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+30,y-14);
        glVertex2d(x-30,y-14);
        glVertex2d(x-30,y-30);
        glVertex2d(x-15,y-45);
        glVertex2d(x+15,y-45);
        glVertex2d(x+30,y-30);
        glEnd();
        glColor3ub(0,0,0);
        DrawCircle(x-26,y-15,15,1);
        DrawCircle(x+26,y-15,15,1);
        
        glColor3ub(200,100,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-12,y-45);
        glVertex2d(x-12,y-50);
        glVertex2d(x+12,y-50);
        glVertex2d(x+12,y-45);
        glEnd();
        
        
        
    }
}
void DrawBoss(int x, int y, int state, double theta)//boss state 1 means hit, theta is top gun angle, bottom gun is pointing at 360 degrees
{
    if(state==0)//normal
    {
        //top wings right
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y+20);
        glVertex2d(x+20,y+60);
        glVertex2d(x+70,y+40);
        glVertex2d(x+70,y+20);
        glEnd();
        
        glColor3ub(150,150,150);
        glBegin(GL_POLYGON);
        glVertex2d(x+70,y+10);
        glVertex2d(x+70,y+50);
        glVertex2d(x+74,y+45);
        glVertex2d(x+74,y+10);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+70,y+30);
        glVertex2d(x+70,y+34);
        glVertex2d(x+20,y+54);
        glVertex2d(x+20,y+50);
        glEnd();
        
        //top wings left
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x-20,y+20);
        glVertex2d(x-20,y+60);
        glVertex2d(x-70,y+40);
        glVertex2d(x-70,y+20);
        glEnd();
        
        glColor3ub(150,150,150);
        glBegin(GL_POLYGON);
        glVertex2d(x-70,y+10);
        glVertex2d(x-70,y+50);
        glVertex2d(x-74,y+45);
        glVertex2d(x-74,y+10);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-70,y+30);
        glVertex2d(x-70,y+34);
        glVertex2d(x-20,y+54);
        glVertex2d(x-20,y+50);
        glEnd();
        
        //top body
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x,y+120);
        glVertex2d(x-20,y+90);
        glVertex2d(x-30,y+20);
        glVertex2d(x+30,y+20);
        glVertex2d(x+20,y+90);
        glEnd();
        //top center
        glColor3ub(255,128,0);
        glBegin(GL_POLYGON);
        glVertex2d(x,y+100);
        glVertex2d(x-10,y+80);
        glVertex2d(x-20,y+30);
        glVertex2d(x+20,y+30);
        glVertex2d(x+10,y+80);
        glEnd();
        //bottom right wing
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x+50,y-50);
        glVertex2d(x+50,y-100);
        glVertex2d(x+90,y-100);
        glVertex2d(x+90,y-60);
        glEnd();
        glColor3ub(255,128,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+90,y-110);
        glVertex2d(x+90,y-50);
        glVertex2d(x+100,y-60);
        glVertex2d(x+100,y-140);
        glEnd();
        //bottom left wing
        glColor3ub(100,100,100);
        glBegin(GL_POLYGON);
        glVertex2d(x-50,y-50);
        glVertex2d(x-50,y-100);
        glVertex2d(x-90,y-100);
        glVertex2d(x-90,y-60);
        glEnd();
        glColor3ub(255,128,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-90,y-110);
        glVertex2d(x-90,y-50);
        glVertex2d(x-100,y-60);
        glVertex2d(x-100,y-140);
        glEnd();
        //bottom body
        glColor3ub(180,180,180);
        glBegin(GL_POLYGON);
        glVertex2d(x-15,y);
        glVertex2d(x+15,y);
        glVertex2d(x+50,y-10);
        glVertex2d(x+60,y-100);
        glVertex2d(x-60,y-100);
        glVertex2d(x-50,y-10);
        glEnd();
        
        //medium body
        glColor3ub(150,150,150);
        glBegin(GL_POLYGON);
        glVertex2d(x-15,y+10);
        glVertex2d(x+15,y+10);
        glVertex2d(x+25,y-20);
        glVertex2d(x+25,y-40);
        glVertex2d(x-25,y-40);
        glVertex2d(x-25,y-20);
        glVertex2d(x-15,y-10);
        glEnd();
        //medium connect
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+10,y+25);
        glVertex2d(x+15,y-20);
        glVertex2d(x-15,y-20);
        glVertex2d(x-10,y+25);
        glEnd();
        //tail
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+40,y-100);
        glVertex2d(x+45,y-110);
        glVertex2d(x-45,y-110);
        glVertex2d(x-40,y-100);
        glEnd();
        
        glColor3ub(0,0,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-110);
        glVertex2d(x+30,y-110);
        glVertex2d(x+30,y-150);
        glVertex2d(x+20,y-120);
        glEnd();
        glColor3ub(0,0,255);
        glBegin(GL_POLYGON);
        glVertex2d(x-20,y-110);
        glVertex2d(x-30,y-110);
        glVertex2d(x-30,y-150);
        glVertex2d(x-20,y-120);
        glEnd();
        //bottom boday center
        glColor3ub(255,100,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+10,y-50);
        glVertex2d(x+40,y-60);
        glVertex2d(x+40,y-80);
        glVertex2d(x+25,y-90);
        glVertex2d(x-25,y-90);
        glVertex2d(x-40,y-80);
        glVertex2d(x-40,y-60);
        glVertex2d(x-10,y-50);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-55);
        glVertex2d(x+20,y-65);
        glVertex2d(x+20,y-75);
        glVertex2d(x,y-85);
        glVertex2d(x-20,y-75);
        glVertex2d(x-20,y-65);
        glEnd();
        //bottom gun
        glColor3ub(0,0,255);
        DrawCircle(x,y-70,5,1);
        //top gun
        DrawCircle(x,y+55,5,1);
        glColor3ub(100,50,100);
        glBegin(GL_POLYGON);
        glVertex2d(x,y+55);
        glVertex2d(x+3*cos(theta*PI/180),y+55+3*sin(theta*PI/180));
        
        glVertex2d(x+3*cos(theta*PI/180)+30*cos(theta*PI/180+PI/2),y+55+3*sin(theta*PI/180)+30*sin(theta*PI/180+PI/2));
        glVertex2d(x-3*cos(theta*PI/180)+30*cos(theta*PI/180+PI/2),y+55-3*sin(theta*PI/180)+30*sin(theta*PI/180+PI/2));
        
        glVertex2d(x-3*cos(theta*PI/180),y+55-3*sin(theta*PI/180));
		glEnd();
        
        glColor3ub(50,50,50);
        DrawCircle(x,y+55,7,1);
        
    }
    if(state==1)//hit and shine
    {
        //top wings right
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y+20);
        glVertex2d(x+20,y+60);
        glVertex2d(x+70,y+40);
        glVertex2d(x+70,y+20);
        glEnd();
        
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+70,y+10);
        glVertex2d(x+70,y+50);
        glVertex2d(x+74,y+45);
        glVertex2d(x+74,y+10);
        glEnd();
        glColor3ub(255,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+70,y+30);
        glVertex2d(x+70,y+34);
        glVertex2d(x+20,y+54);
        glVertex2d(x+20,y+50);
        glEnd();
        
        //top wings left
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x-20,y+20);
        glVertex2d(x-20,y+60);
        glVertex2d(x-70,y+40);
        glVertex2d(x-70,y+20);
        glEnd();
        
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x-70,y+10);
        glVertex2d(x-70,y+50);
        glVertex2d(x-74,y+45);
        glVertex2d(x-74,y+10);
        glEnd();
        glColor3ub(255,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x-70,y+30);
        glVertex2d(x-70,y+34);
        glVertex2d(x-20,y+54);
        glVertex2d(x-20,y+50);
        glEnd();
        
        //top body
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x,y+120);
        glVertex2d(x-20,y+90);
        glVertex2d(x-30,y+20);
        glVertex2d(x+30,y+20);
        glVertex2d(x+20,y+90);
        glEnd();
        //top center
        glColor3ub(255,228,200);
        glBegin(GL_POLYGON);
        glVertex2d(x,y+100);
        glVertex2d(x-10,y+80);
        glVertex2d(x-20,y+30);
        glVertex2d(x+20,y+30);
        glVertex2d(x+10,y+80);
        glEnd();
        //bottom right wing
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+50,y-50);
        glVertex2d(x+50,y-100);
        glVertex2d(x+90,y-100);
        glVertex2d(x+90,y-60);
        glEnd();
        glColor3ub(255,228,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+90,y-110);
        glVertex2d(x+90,y-50);
        glVertex2d(x+100,y-60);
        glVertex2d(x+100,y-140);
        glEnd();
        //bottom left wing
        glColor3ub(200,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x-50,y-50);
        glVertex2d(x-50,y-100);
        glVertex2d(x-90,y-100);
        glVertex2d(x-90,y-60);
        glEnd();
        glColor3ub(255,228,200);
        glBegin(GL_POLYGON);
        glVertex2d(x-90,y-110);
        glVertex2d(x-90,y-50);
        glVertex2d(x-100,y-60);
        glVertex2d(x-100,y-140);
        glEnd();
        //bottom body
        glColor3ub(220,220,220);
        glBegin(GL_POLYGON);
        glVertex2d(x-15,y);
        glVertex2d(x+15,y);
        glVertex2d(x+50,y-10);
        glVertex2d(x+60,y-100);
        glVertex2d(x-60,y-100);
        glVertex2d(x-50,y-10);
        glEnd();
        
        //medium body
        glColor3ub(220,220,220);
        glBegin(GL_POLYGON);
        glVertex2d(x-15,y+10);
        glVertex2d(x+15,y+10);
        glVertex2d(x+25,y-20);
        glVertex2d(x+25,y-40);
        glVertex2d(x-25,y-40);
        glVertex2d(x-25,y-20);
        glVertex2d(x-15,y-10);
        glEnd();
        //medium connect
        glColor3ub(255,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+10,y+25);
        glVertex2d(x+15,y-20);
        glVertex2d(x-15,y-20);
        glVertex2d(x-10,y+25);
        glEnd();
        //tail
        glColor3ub(255,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+40,y-100);
        glVertex2d(x+45,y-110);
        glVertex2d(x-45,y-110);
        glVertex2d(x-40,y-100);
        glEnd();
        
        glColor3ub(200,200,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-110);
        glVertex2d(x+30,y-110);
        glVertex2d(x+30,y-150);
        glVertex2d(x+20,y-120);
        glEnd();
        glColor3ub(200,200,255);
        glBegin(GL_POLYGON);
        glVertex2d(x-20,y-110);
        glVertex2d(x-30,y-110);
        glVertex2d(x-30,y-150);
        glVertex2d(x-20,y-120);
        glEnd();
        //bottom boday center
        glColor3ub(255,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x+10,y-50);
        glVertex2d(x+40,y-60);
        glVertex2d(x+40,y-80);
        glVertex2d(x+25,y-90);
        glVertex2d(x-25,y-90);
        glVertex2d(x-40,y-80);
        glVertex2d(x-40,y-60);
        glVertex2d(x-10,y-50);
        glEnd();
        glColor3ub(255,200,200);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-55);
        glVertex2d(x+20,y-65);
        glVertex2d(x+20,y-75);
        glVertex2d(x,y-85);
        glVertex2d(x-20,y-75);
        glVertex2d(x-20,y-65);
        glEnd();
        //bottom gun position is (x,y-70).
        glColor3ub(200,200,255);
        DrawCircle(x,y-70,5,1);
        //top gun position is (x,y+55).
        DrawCircle(x,y+55,5,1);
        glColor3ub(200,150,200);
        glBegin(GL_POLYGON);
        glVertex2d(x,y+55);
        glVertex2d(x+3*cos(theta*PI/180),y+55+3*sin(theta*PI/180));
        
        glVertex2d(x+3*cos(theta*PI/180)+30*cos(theta*PI/180+PI/2),y+55+3*sin(theta*PI/180)+30*sin(theta*PI/180+PI/2));
        glVertex2d(x-3*cos(theta*PI/180)+30*cos(theta*PI/180+PI/2),y+55-3*sin(theta*PI/180)+30*sin(theta*PI/180+PI/2));
        
        glVertex2d(x-3*cos(theta*PI/180),y+55-3*sin(theta*PI/180));
        glEnd();
        glColor3ub(220,220,220);
        DrawCircle(x,y+55,7,1);
     
        
    }
    
    
}

//main function is for test only
/*
int main(void)
{
    FsOpenWindow(16,16,800,800,1);
    
    glShadeModel(GL_SMOOTH);
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    DrawMonster1(100,500,0,90);
    DrawMonster1(200,500,1,120);
    DrawMonster3(300,500,0);
    DrawMonster3(400,500,1);
    DrawBoss(600,200,1,57);
    
    DrawMonster2(100,200,0);
    DrawMonster2(200,200,1);
    DrawMonster4(300,200,0);
    DrawMonster4(400,200,1);
    DrawBoss(600,500,0,90);
    FsSwapBuffers();
    FsSleep(100);


    
    for(;;)
    {
        FsPollDevice();
        int key=FsInkey();
        
        if(FSKEY_ESC==key)
        {
            break;
        }
        
        FsSleep(10);
    }
    
    return 0;
}*/

