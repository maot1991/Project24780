#include "fssimplewindow.h"
#include <math.h>


const double PI2=3.1415927;
void DrawCircle(double cx,double cy,double rad,int indicator)
{
    if(indicator==0)
        glBegin(GL_LINE_LOOP);
    else if(indicator==1)
        glBegin(GL_POLYGON);
    for(int angle=0; angle<=360; angle+=30)
    {
        double a=(double)angle*2.0*PI2/360.0;
        double s=sin(a);
        double c=cos(a);
        
        glVertex2d(cx+c*rad,cy+s*rad);
    }
    glEnd();
}
void DrawSemicircle(double cx,double cy,double rad, int orientation)
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
        double a=(double)angle*2.0*PI2/360.0;
        double s=sin(a);
        double c=cos(a);
        
        glVertex2d(cx+c*rad,cy+s*rad);
    }
    
    glEnd();
}

void DrawHero(double x, double y,double state)
{
    if(state==0)//stand left
    {
        //draw hero stand toward left
        //body
        glColor3ub(150,255,255);
        
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-20);
        glVertex2d(x+10,y-70);
        glVertex2d(x-17,y-70);
        glVertex2d(x-20,y-20);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-20);
        glVertex2d(x+10,y-70);
        glVertex2d(x-17,y-70);
        glVertex2d(x-20,y-20);
        glEnd();
        
        //feet
        glColor3ub(150,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        //wheel
        glColor3ub(0,0,0);
        for(int i=-13;i<=13;i+=6)
        {
            DrawCircle(x+i,y-3,3,1);
        }
        //neck
        glColor3ub(170,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+7,y-70);
        glVertex2d(x+5,y-80);
        glVertex2d(x-5,y-80);
        glVertex2d(x-7,y-70);
        glEnd();
        //head
        glColor3ub(125,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        //antenna
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+3,y-95);
        glVertex2d(x-3,y-95);
        glVertex2d(x-10,y-110);
        glEnd();
        DrawCircle(x-10,y-110,2,1);
        //arm
       glColor3ub(160,32,240);
        DrawCircle(x,y-55,6,1);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-60);
        glVertex2d(x,y-50);
        glVertex2d(x+15,y-40);
        glVertex2d(x+30,y-40);
        glVertex2d(x+30,y-50);
        glVertex2d(x+15,y-45);
        glEnd();
        
        //gun
        glColor3ub(255,0,0);
        glBegin(GL_LINES);
        glVertex2d(x+25,y-50);
        glVertex2d(x+25,y-55);
        glVertex2d(x+25,y-40);
        glVertex2d(x+25,y-35);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-55);
        glVertex2d(x+30,y-55);
        glVertex2d(x+50,y-65);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-35);
        glVertex2d(x+30,y-35);
        glVertex2d(x+50,y-25);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex2d(x+30,y-37);
        glVertex2d(x+30,y-53);
        glVertex2d(x+50,y-50);
        glVertex2d(x+50,y-40);
        glEnd();
        //eyes
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+5,y-85);
        glVertex2d(x+5,y-90);
        glVertex2d(x+10,y-90);
        glVertex2d(x+15,y-85);
        glEnd();
        

    }
    if(state==1)//stand right
    {
        //draw hero stand right
        //body
        glColor3ub(150,255,255);
        
        glBegin(GL_POLYGON);
        glVertex2d(x-20,y-20);
        glVertex2d(x-10,y-70);
        glVertex2d(x+17,y-70);
        glVertex2d(x+20,y-20);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-20,y-20);
        glVertex2d(x-10,y-70);
        glVertex2d(x+17,y-70);
        glVertex2d(x+20,y-20);
        glEnd();
        
        //feet
        glColor3ub(150,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        //wheel
        glColor3ub(0,0,0);
        for(int i=-13;i<=13;i+=6)
        {
            DrawCircle(x+i,y-3,3,1);
        }
        //neck
        glColor3ub(170,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x-7,y-70);
        glVertex2d(x-5,y-80);
        glVertex2d(x+5,y-80);
        glVertex2d(x+7,y-70);
        glEnd();
        //head
        glColor3ub(125,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        //antenna
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+3,y-95);
        glVertex2d(x-3,y-95);
        glVertex2d(x+10,y-110);
        glEnd();
        DrawCircle(x+10,y-110,2,1);
        //arm
        glColor3ub(160,32,240);
        DrawCircle(x,y-55,6,1);
        glBegin(GL_POLYGON);
        glVertex2d(x,y-60);
        glVertex2d(x,y-50);
        glVertex2d(x-15,y-40);
        glVertex2d(x-30,y-40);
        glVertex2d(x-30,y-50);
        glVertex2d(x-15,y-45);
        glEnd();
        
        //gun
        glColor3ub(255,0,0);
        glBegin(GL_LINES);
        glVertex2d(x-25,y-50);
        glVertex2d(x-25,y-55);
        glVertex2d(x-25,y-40);
        glVertex2d(x-25,y-35);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-20,y-55);
        glVertex2d(x-30,y-55);
        glVertex2d(x-50,y-65);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-20,y-35);
        glVertex2d(x-30,y-35);
        glVertex2d(x-50,y-25);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex2d(x-30,y-37);
        glVertex2d(x-30,y-53);
        glVertex2d(x-50,y-50);
        glVertex2d(x-50,y-40);
        glEnd();
        //eyes
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-5,y-85);
        glVertex2d(x-5,y-90);
        glVertex2d(x-10,y-90);
        glVertex2d(x-15,y-85);
        glEnd();
    }
    if(state==2)//jump left
    {
        //draw hero jumping left
        //body
        glColor3ub(150,255,255);
        
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-20);
        glVertex2d(x+10,y-70);
        glVertex2d(x-17,y-70);
        glVertex2d(x-20,y-20);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-20);
        glVertex2d(x+10,y-70);
        glVertex2d(x-17,y-70);
        glVertex2d(x-20,y-20);
        glEnd();
        
        //feet
        glColor3ub(150,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        //wheel
        glColor3ub(0,0,0);
        for(int i=-13;i<=13;i+=6)
        {
            DrawCircle(x+i,y-3,3,1);
        }
        //neck
        glColor3ub(170,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+7,y-70);
        glVertex2d(x+5,y-80);
        glVertex2d(x-5,y-80);
        glVertex2d(x-7,y-70);
        glEnd();
        //head
        glColor3ub(125,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        //antenna
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+3,y-95);
        glVertex2d(x-3,y-95);
        glVertex2d(x-10,y-110);
        glEnd();
        DrawCircle(x-10,y-110,2,1);
        //arm
        glColor3ub(160,32,240);
        DrawCircle(x,y-55,6,1);
        glBegin(GL_POLYGON);
        glVertex2d(x+5,y-55);
        glVertex2d(x-5,y-55);
        glVertex2d(x-15,y-30);
        glVertex2d(x-15,y-15);
        glVertex2d(x-5,y-15);
        glVertex2d(x-5,y-30);
        glEnd();
        
        //gun
        glColor3ub(255,0,0);
        glBegin(GL_LINES);
        glVertex2d(x-15,y-20);
        glVertex2d(x-20,y-20);
        glVertex2d(x-5,y-20);
        glVertex2d(x,y-20);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-20,y-15);
        glVertex2d(x-20,y-25);
        glVertex2d(x-30,y+5);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x,y-15);
        glVertex2d(x,y-25);
        glVertex2d(x+10,y+5);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex2d(x-18,y-15);
        glVertex2d(x-2,y-15);
        glVertex2d(x-5,y+5);
        glVertex2d(x-15,y+5);
        glEnd();
        //eyes
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x+5,y-85);
        glVertex2d(x+5,y-90);
        glVertex2d(x+10,y-90);
        glVertex2d(x+15,y-85);
        glEnd();
        
    }
    if(state==3)//jump right
    {
        //draw hero jumping right
        //body
        glColor3ub(150,255,255);
        
        glBegin(GL_POLYGON);
        glVertex2d(x-20,y-20);
        glVertex2d(x-10,y-70);
        glVertex2d(x+17,y-70);
        glVertex2d(x+20,y-20);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x-20,y-20);
        glVertex2d(x-10,y-70);
        glVertex2d(x+17,y-70);
        glVertex2d(x+20,y-20);
        glEnd();
        
        //feet
        glColor3ub(150,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        glColor3ub(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x,y);
        glVertex2d(x+15,y);
        glVertex2d(x+22,y-5);
        glVertex2d(x+25,y-10);
        glVertex2d(x+5,y-28);
        glVertex2d(x,y-30);
        glVertex2d(x-5,y-28);
        glVertex2d(x-25,y-10);
        glVertex2d(x-22,y-5);
        glVertex2d(x-15,y);
        glEnd();
        
        //wheel
        glColor3ub(0,0,0);
        for(int i=-13;i<=13;i+=6)
        {
            DrawCircle(x+i,y-3,3,1);
        }
        //neck
        glColor3ub(170,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+7,y-70);
        glVertex2d(x+5,y-80);
        glVertex2d(x-5,y-80);
        glVertex2d(x-7,y-70);
        glEnd();
        //head
        glColor3ub(125,255,255);
        glBegin(GL_POLYGON);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        glColor3ub(255,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-80);
        glVertex2d(x+5,y-95);
        glVertex2d(x-5,y-95);
        glVertex2d(x-20,y-80);
        glEnd();
        //antenna
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-3,y-95);
        glVertex2d(x+3,y-95);
        glVertex2d(x+10,y-110);
        glEnd();
        DrawCircle(x+10,y-110,2,1);
        //arm
        glColor3ub(160,32,240);
        DrawCircle(x,y-55,6,1);
        glBegin(GL_POLYGON);
        glVertex2d(x-5,y-55);
        glVertex2d(x+5,y-55);
        glVertex2d(x+15,y-30);
        glVertex2d(x+15,y-15);
        glVertex2d(x+5,y-15);
        glVertex2d(x+5,y-30);
        glEnd();
        
        //gun
        glColor3ub(255,0,0);
        glBegin(GL_LINES);
        glVertex2d(x+15,y-20);
        glVertex2d(x+20,y-20);
        glVertex2d(x+5,y-20);
        glVertex2d(x,y-20);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x+20,y-15);
        glVertex2d(x+20,y-25);
        glVertex2d(x+30,y+5);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2d(x,y-15);
        glVertex2d(x,y-25);
        glVertex2d(x-10,y+5);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex2d(x+18,y-15);
        glVertex2d(x+2,y-15);
        glVertex2d(x+5,y+5);
        glVertex2d(x+15,y+5);
        glEnd();
        //eyes
        glColor3ub(255,0,0);
        glBegin(GL_POLYGON);
        glVertex2d(x-5,y-85);
        glVertex2d(x-5,y-90);
        glVertex2d(x-10,y-90);
        glVertex2d(x-15,y-85);
        glEnd();
    }

}

//following function is only for test
/*
int main(void)
{
    FsOpenWindow(16,16,800,600,1);
    
    glShadeModel(GL_SMOOTH);
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    DrawHero(500,500,0);
    DrawHero(200,500,1);
    DrawHero(500,200,2);
    DrawHero(200,200,3);
    FsSwapBuffers();
    
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
}
*/