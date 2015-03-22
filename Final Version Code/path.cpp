#include<stdio.h>
#include<stdlib.h>

#include "fssimplewindow.h"
#include "path.h"
//#include "HeroAction.h"
#include "DrawHero.h"
//#include "Enemy.h"





void Runway::initialize(int x,int y,int leng,int hei,int width){
    
    y1 = y;
    x1 = x;
    l = leng;
    h = hei;
    w=width;
    if(y1==500)
    {
        id=1;
    }
    else if(y1==300)
    {
        id=2;
    }else
        id = 0;
    
}

bool Runway::checkroll(double x, double y)
{
    if(x+25>=x1 && x-25 <= x1+l && y==y1)
    {
        return true;
    }
    return false;      //for (int i =0;i<100;i++){if (road[i].checkroll==true) 保留位置 else 下降}
}

void Runway::checkdie(Hero &hero)
{
  //  printf("id=%d\n",id);
    
    if(hero.y<300)
    {
        hero.roadstate=4;
    }
   // printf("hero.y=%d,hero.roadstate=%d,hero.x=%d,x1=%d,x1+l=%d id=%d\n",hero.y,hero.roadstate,hero.x,x1,x1+l,id);
    
    if (hero.y>=300 && hero.roadstate == 4 && (hero.x+25>=x1) && (hero.x-25 <= x1+l) && id == 2){
       // printf("!!!\n");
        hero.roadstate=3;
        hero.y=300;
        hero.vy=0;
    }
   /* if(hero.y==300 && (hero.x>=x1) && (hero.x<=x1+l) && id == 2)
    {
        hero.roadstate=3;
    }*/
    if(hero.y>=300 && hero.y<500 && hero.roadstate == 4)
    {
        hero.roadstate=4;
    }
    else if(hero.y>=300 && hero.y<500 && hero.roadstate !=3)
    {
        hero.roadstate=2;
    }
    if(hero.y>=300 && hero.y<500 && (hero.roadstate == 2 || hero.roadstate ==1))
    {
        hero.roadstate=2;
    }
    if(hero.y>=500 && (hero.x+25 >=x1) && (hero.x-25 <=x1+l) && id == 1)
    {
        hero.roadstate=1;
    }
    if((hero.roadstate<=2)&&(id==1))
    {
        //printf("check that\n");
        //printf("hero.x=%d,hero.y=%d,x1=%d x1+l=%d\n",hero.x,hero.y,x1,x1+l);
        if((hero.x+25>=x1) && (hero.x-25<=x1+l) && (hero.y>=y1))
        {
           // printf("check this\n");
            hero.vy=0;
            hero.roadstate=1;
            hero.y=500;
            return;
        }
    }
   /* if((hero.roadstate>2)&&(id==2))
    {
        
        if((hero.x>=x1) && (hero.x<=x1+l) && (hero.y>=y1))
        {
            
            hero.vy=0;
            hero.roadstate=3;
            hero.y=300;
            return;
        }
    }*/
}
void Runway::checkmons(Enemy &enemy)
{
    {
        //  printf("id=%d\n",id);
        
        if(enemy.y<300)
        {
            enemy.roadstate=4;
        }
        // printf("hero.y=%d,hero.roadstate=%d,hero.x=%d,x1=%d,x1+l=%d id=%d\n",hero.y,hero.roadstate,hero.x,x1,x1+l,id);
        
        if (enemy.y>=300 && enemy.roadstate == 4 && (enemy.x+25>=x1) && (enemy.x-25 <= x1+l) && id == 2){
            // printf("!!!\n");
            enemy.roadstate=3;
            enemy.y=300;
            enemy.vy=0;
        }
        /* if(hero.y==300 && (hero.x>=x1) && (hero.x<=x1+l) && id == 2)
         {
         hero.roadstate=3;
         }*/
        if(enemy.y>=300 && enemy.y<500 && enemy.roadstate == 4)
        {
            enemy.roadstate=4;
        }
        else if(enemy.y>=300 && enemy.y<500 && enemy.roadstate !=3)
        {
            enemy.roadstate=2;
        }
        if(enemy.y>=300 && enemy.y<500 && (enemy.roadstate == 2 || enemy.roadstate ==1))
        {
            enemy.roadstate=2;
        }
        if(enemy.y>=500 && (enemy.x+25>=x1) && (enemy.x-25 <=x1+l) && id == 1)
        {
            enemy.roadstate=1;
        }
        if((enemy.roadstate<=2)&&(id==1))
        {
            //printf("check that\n");
            //printf("hero.x=%d,hero.y=%d,x1=%d x1+l=%d\n",hero.x,hero.y,x1,x1+l);
            if((enemy.x+25>=x1) && (enemy.x-25<=x1+l) && (enemy.y=y1))
            {
                // printf("check this\n");
                enemy.vy=0;
                enemy.roadstate=1;
                enemy.y=500;
                return;
            }
        }
    }
}

void Runway::draw()
{
 
    glBegin(GL_QUADS);
    glColor3ub(32,178,170);
    glVertex2i(x1,y1);
    glVertex2i(x1,y1+20);
    glVertex2i(x1+l,y1+20);
    glVertex2i(x1+l, y1);
    glColor3ub(218,147,73);
    glVertex2i(x1,y1+20);
    glVertex2i(x1,y1+h);
    glVertex2i(x1+l,y1+h);
    glVertex2i(x1+l, y1+20);
    glEnd();
}

void Runway::update(Hero &hero,int right,Enemy &enemy,int bossstate)
{
    checkdie(hero);
    if (right == 1 && hero.y<=500 && hero.blockstate==0 && bossstate == 0)
            change();
    checkmons(enemy);
}

void Runway::change()
{
    int v=10;
    int t=1;
    x1=x1-v*t;
};



