//
//  WorldState.cpp
//  worldstate
//
//  Created by TangMao on 14-11-17.
//  Copyright (c) 2014年 TangMao. All rights reserved.
//


const double PI=3.1415927;
#include <iostream>

#include "DrawHero.h"
//#include "menu.h"
#include "HeroAction.h"
#include "fssimplewindow.h"
//#include "item.h"
#include "herobullet.h"
#include "sky.h"
#include "path.h"
#include "obstacletrai.h"
#include "cannon.h"
#include "fire.h"
#include "pillar.h"
//#include "cannonbullet.h"
//#include "Enemy.h"
#include "GameObject.h"
#include "Boss.h"
#include "menu.h"
#include "ysglfontdata.h"
#include "yspng.h"


int main(void)
{
    
    FsChangeToProgramDir();
//--------------------------------------------------------------------------------------------------  
    int time_count = 5;
    
    FsOpenWindow(16, 16, 800, 600, 1);

	
	YsRawPngDecoder png[5];
	if(YSOK==png[0].Decode("3.png"))
	{
		printf("Read Width=%d Height=%d\n",png[0].wid,png[0].hei);
		png[0].Flip();
	}
	else
	{
		printf("Read Error!\n");
		return 0;
	}
    if(YSOK==png[1].Decode("5.png"))
	{
		printf("Read Width=%d Height=%d\n",png[1].wid,png[1].hei);
		png[1].Flip();
	}
	else
	{
		printf("Read Error!\n");
		return 0;
	}
//    if(YSOK==png[2].Decode("6.png"))
//	{
//		printf("Read Width=%d Height=%d\n",png[2].wid,png[2].hei);
//		png[2].Flip();
//	}
//	else
//	{
//		printf("Read Error!\n");
//		return 0;
//	}
//    if(YSOK==png[3].Decode("6.png"))
//	{
//		printf("Read Width=%d Height=%d\n",png[3].wid,png[3].hei);
//		png[3].Flip();
//	}
//	else
//	{
//		printf("Readdd Error!\n");
//		return 0;
//	}
//    
    int state=0; // 0:menu  1:game  2:terminate
	GameMenu menu;
    while(true){
	while(2!=state&&3!=state)
	{

		FsPollDevice();
		//Key=FsInkey();
    
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		int winWid,winHei;
		FsGetWindowSize(winWid,winHei);
		glRasterPos2d(0.0,(double)(png[0].hei-1));
		glDrawPixels(png[0].wid,png[0].hei,GL_RGBA,GL_UNSIGNED_BYTE,png[0].rgba);
		
		switch(state)
		{
            case 0:
			{
				menu.RunGameMenuOneStep();
				if(FSKEY_S==menu.lastKey)
				{
					state=1;
				}
				else if(FSKEY_ESC==menu.lastKey)
				{
					state=3;
				}
			}
                break;
            case 1:
			{
				
				state=2;
			}
                break;
		}
	}

    if (state==3)
	{
		break;
	}
	state=0;
    
    BulletDrawing b;
    element e;
    Cannonelement ce;
    Enemy a(4);
    

    
    sky bluesky;
    
    // Cannon *c;
    //  Pillar *p;
    Fire f[100];
    int j;
    int k;
    int ii = 0;//counter for fires
    Runway runway[11];
    Runway runway1[6];
    runway[0].initialize(0,500,300+rand()%200,100,100);
    for(j=1;j<10;j++)
    {
        runway[j].initialize(runway[j-1].x1+runway[j-1].l+100,500,300+rand()%200,100,100);
        if (j%5==0 || j%7==0 || j%9==0){
            
            f[ii].init(runway[j].x1+runway[j].l+100/2);
            ii++;
        }
        
    }
    runway[10].initialize(runway[9].x1+runway[9].l+100,500,1000,100,100);
    runway1[5].initialize(runway[9].x1+runway[9].l+100+500,300, 500, 50, 0);
    
    
    
    runway1[0].initialize(600,300,200+rand()%200,50,300);
    for(k=1;k<5;k++)
    {
        runway1[k].initialize(runway1[k-1].x1+runway1[k-1].l+runway1[k-1].w,300,200+rand()%200,50,300+rand()%300);
    }
    
    Hero hero;
    int bossstate=0;
    hero.Initialize(500);
    
    Cannon c[9];
    Pillar p[9];
    c[0].init(100+rand()%500,rand()%50+50);
    p[0].init(c[0].x+rand()%500+200,300+rand()%200);
    for (int i =1 ;i<9;i++){
        c[i].init(p[i-1].x+rand()%300+300,rand()%50+50);
        p[i].init(c[i].x+rand()%300+200,300+rand()%20);
    }
    
   
    //Enemy a;
	
    Boss boss(runway[10].x1+350);
    
    
	
    while (state!=3)
    {
        
      
        
        if(0==a.exist && runway[10].x1>500)
        {
            time_count--;
            if(time_count==0)
            {
                time_count=3;
                int rdn = rand()%40;
                if(rdn==0)
                {
                    a = Enemy(2);
                }
                
                if(rdn==1)
                {
                    a = Enemy(4);
                }
                
                if(rdn==2)
                {
                    a = Enemy(4);
                    a.Initialize(40, 60, 700, 500, 1);
                }
                
                if(rdn==3)
                {
                    a = Enemy(2);
                    a.Initialize(40, 60, 700, 500, 1);
                }
            }
        }
        
        if (hero.CheckDie()!=0){
            
            
            
            break;
        }
        if (runway[10].x1<70)
            bossstate = 1;
        FsPollDevice();
        //double hx=hero.x;
        //printf("%lf\n",hx);
        
        int right=0,left=0,up=0,down=0,space=0,d=0;
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glRasterPos2d(0.0,(double)(png[1].hei-1));
		glDrawPixels(png[1].wid,png[1].hei,GL_RGBA,GL_UNSIGNED_BYTE,png[1].rgba);


        int key = FsInkey();
        
        
        
        if (key == FSKEY_ESC)
        {
            break;
        }
        if (0==FsGetKeyState(NULL))
            
         if (0!=FsGetKeyState(FSKEY_LEFT))//walking
            left = 1;
        if (0!=FsGetKeyState(FSKEY_RIGHT) ){
            right = 1;
           
        }
        if (0!=FsGetKeyState(FSKEY_UP))
            up = 1;
        if (0!=FsGetKeyState(FSKEY_DOWN))
            down = 1;
        if (0!=FsGetKeyState(FSKEY_D)) //squate
            d = 1;
            
        if (0!=FsGetKeyState(FSKEY_SPACE)){ //shoot
                space = 1;
            }
        
    
        for (int i=0;i<11;i++)
            runway[i].update(hero,right,a,bossstate);
        
        for (int k=0;k<6;k++)
            runway1[k].update(hero,right,a,bossstate);
        
    
        
		
        

        
        if(1==boss.exist)
        {
            for (int i = 0; i < boss.numBullet; ++i)
            {
                
                boss.b[i].Update(hero,right,bossstate);
                //printf("debug%d\n", boss.b[0].x);
                
                boss.b[i].Draw();
            }
            boss.Update(hero,right,bossstate);
            boss.Draw();
            
        }
        
      
        for(j=0;j<11;j++)
        {
            runway[j].draw();
            
            
        }
        for(k=0;k<6;k++)
        {
            runway1[k].draw();
        }

        //printf("blockstate1=%d\n",hero.blockstate);
        hero.Update(300,500,bossstate,right,left,up,down,space);



        //printf("blockstate2=%d\n",hero.blockstate);
		
        for (int i=0;i<9;i++){
        p[i].update(hero,right,bossstate);
        c[i].update(hero,right,ce,bossstate);
        }
        if (right == 1 && hero.blockstate == 0 && hero.y<=500 && bossstate==0){
			b.update(hero, e, a, boss,space,bossstate,10);
            e.update(hero,10);
            ce.update(hero, 10);
        }else{
			b.update(hero, e, a, boss,space,bossstate,0);
            e.update(hero,0);
            ce.update(hero, 0);
        }
        
        if(1==a.exist)
		{
			for (int i = 0; i < a.numBullet; ++i)
			{
                
				a.b[i].Update(hero,right,bossstate);
				//printf("%d\n", b[i].speed);
                
				a.b[i].Draw();
			}
			a.Update(hero,right,bossstate);
			a.Draw();
            
		}
        
        for (int i=0;i<ii;i++){
            f[i].update(hero, right);
            f[i].draw();
        }

        
        for (int i=0;i<9;i++){
        c[i].draw();
        p[i].draw();
        
        }
        
        b.drawmenu(hero, boss, bossstate);
        
        
        if (boss.blood<=0)
        {
            glColor3ub(0,0,0);
            glRasterPos2d(300,230);
            YsGlDrawFontBitmap20x32("You Win!");
            FsSwapBuffers();
            FsSleep(3000);
            break;
        }
        if (hero.CheckDie()!=0) {
            glColor3ub(0,0,0);
            glRasterPos2d(300,230);
            YsGlDrawFontBitmap20x32("Game Over!");
            FsSwapBuffers();
            FsSleep(3000);
            break;
        }
        if (runway[10].x1<800 && runway[10].x1>100) {
            glColor3ub(0,0,0);
            glRasterPos2d(50,230);
            YsGlDrawFontBitmap16x20("You need to move forward to fight against boss");
            
        }


//-------------------------------------------------------------------------------------------------
        
        
        FsSwapBuffers();
        
        
        
        
        FsSleep(40);
    }
     
	}
    
    return 0;
}
