#include "Boss.h"
#include <time.h>
#include <stdlib.h>

#include "fssimplewindow.h"
#include <stdio.h>
#include <math.h>
#include "DrawMonster.h"





Boss::Boss()
{
	numBullet = 0;
	b = NULL;
	speed = 1;
	Initialize(40, 80, 700, 200, 1);
	blood = 300;
	heading = 1;
}

Boss::Boss(int x)
{
    numBullet = 0;
    b = NULL;
    speed = 1;
    Initialize(80, 160, x, 200, 1);
    blood = 100;
    heading = 1;
}

void Boss::Initialize(int a, int b, int c, int d, int e) {
	width = a;
	height = b;
	x = c;
	y = d;
	vx=0;
	vy=0;
	roadstate = e;
	exist = 1;
}

bool Boss::checkHeroColision(Hero &hero)
{
	int a = hero.x-25;
	int b = hero.x+25;
	int c = x;
	int d = x+width;

	if(d<a||c>b)
	{
		return false;
	}
	else
	{
		int a = hero.y;
		int b = hero.y-80;
		int c = y-height;
		int d = y;

		if(d<b||c>a)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void Boss::Update(Hero &hero,int right,int bossstate)
{
	if (right == 1&&0==bossstate && hero.blockstate ==0)
	{
            x-=10;
	}

	
	if(true == checkHeroColision(hero))
	{
		hero.blood=hero.blood-5;
	}

	//printf("numBullet :%d\n",numBullet);
	
	if(numBullet<1 && bossstate)
	{
		shoot();
	}

	walk();

	//printf("b[0].x: %d\n", b[0].x);
	//printf("draw enemy bullet ");



	if(b!=NULL)
	{
		if (b[6].x < -100)
		{
			delete[]b;
			b = NULL;
			numBullet = 0;
			
		}

		for(int i = 1; i < numBullet; i++)
		{

			if(true == b[i].checkHeroColision(hero))
			{
				hero.blood-=2;
				delete[]b;
				b = NULL;
				numBullet = 0;
			}
		}


	}

	/*if(hero.y<400)
	{
		remove();
	}*/
}

void Boss::shoot()
{
	numBullet = 15;
	const double PI = 3.1415927;
	b = new eBullet[numBullet];
	for(int i=0; i<15; i++)
    {
		int angle = 24*i;
        double a=(double)angle*2.0*PI/360.0;
        double s=sin(a);
        double c=cos(a);
        int vx_ = (int)(s*10);
		int vy_ = (int)(c*10);
		b[i].initialize(x,y,3);
		b[i].setV(vx_, vy_);
    }
}

void Boss::walk(){
	//printf("Walking y:%d\n",y);
	if(y>700)
	{
		heading = -1;
	}

	if(y<100)
	{
		heading = 1;
	}

	y = y+heading * 10;
}

void Boss::Draw() {
	if (1 == exist)
	{

		DrawBoss(x,y,0,0);

	}
}

void Boss::remove(){
	exist = 0;
	width = 0;
	height = 0;
	if (NULL != b)
	{
		
		delete[] b;
		//printf("delete\n");
		b = NULL;
	}
}