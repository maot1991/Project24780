#include "fssimplewindow.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Enemy.h"
#include "DrawMonster.h"

Enemy::Enemy()
{
	numBullet = 0;
	b = NULL;
	speed = 1;
	Initialize(40, 60, 700, 500, 1);
}

Enemy::Enemy(int label)
{
	type = label;
	numBullet = 0;
	b = NULL;
	speed = 1;
	//Initialize(40, 60, 700, 500, 1);
    Initialize(40, 60, 700, 300, 3);
}

Enemy::~Enemy()
{
	/*
	if (1 == exist)
	{
		remove();
	}
	*/
}

int Enemy::getType()
{
	return type;
}

void Enemy::Initialize(int a, int b, int c, int d, int e) {
	width = a;
	height = b;
	x = c;
	y = d;
	vx=0;
	vy=0;
	roadstate = e;
	exist = 1;
}

void Enemy::Update(Hero &hero,int right,int bossstate)
{
	if (right == 1 && hero.y<=500 && hero.blockstate==0 && bossstate == 0)
	{
            x-=10;
	}


    if(true == checkHeroColision(hero))
    {
        hero.blood=hero.blood-5;
    }
	
	if(numBullet<1)
	{
		shoot();
	}
    //printf("x:%d y:%d\n", x, y);
	//printf("draw enemy bullet ");
	walk();

	if(b!=NULL)
	{
		if (b[0].x < 0)
		{
			delete[]b;
			b = NULL;
			numBullet = 0;
			
		}
		else if(true == b[0].checkHeroColision(hero))
		{
			--hero.blood;
			delete[]b;
			b = NULL;
			numBullet = 0;
		}



	}

	if(y>900)
	{
		remove();
	}
}


void Enemy::Draw() {
	if (1 == exist)
	{
		/*glColor3d(0.0, 0.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2i(x, y);
		glVertex2i(x + width, y);
		glVertex2i(x + width, y + height);
		glVertex2i(x, y + height);
		glEnd();*/
		if(2==type)
		{
			DrawMonster2(x,y,0);
		}
		
		if(4==type)
		{
			DrawMonster4(x,y,0);
		}
	}
}



void Enemy::remove(){
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

void Enemy::walk(){
    //printf("%d %d\n", x, y);
	int g = 10;
	x -= 2*speed;
	//printf("%d\n",roadstate);
	switch (roadstate)
	{
	case 2:
	case 4:		
		vy +=g;
		y+=vy;
		break;
	case 1:
	case 3:
		vy = 0;
	default:
		break;
	}
	if (roadstate==1) {
        roadstate=2;
    }
    if(roadstate==3){
        roadstate=4;
    }

}

void Enemy::shoot(){
	numBullet=1;
	b = new eBullet[numBullet];
	//b[numBullet - 1].initialize(x, y + 20);
	/*
	b[numBullet - 1].x = x;
	b[numBullet - 1].y = y + 20;
	b[numBullet - 1].exist = 1;
	*/


	//b[0].x = x;
	//b[0].y = y+20;
	//b[0].exist = 1;
	if(2==type)
	{
		b[0].initialize(x-10,y-22,1);
	}
	if(4==type)
	{
		b[0].initialize(x-25,y-43,2);
	}

	//printf("numBullet: %d",numBullet);
}

bool Enemy::checkHeroColision(Hero &hero)
{
    //printf("check hero enemy collision\n");
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

	/*
	if((x<=hero.x+25) && (x>=hero.x-25) && (y<=hero.y) && (y>=hero.y-80) )
	{
		return true;
	}*/


	return false;
}