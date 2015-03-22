#include "fssimplewindow.h"
#include "EnemyBullet.h"
#include <math.h>
#include <stdio.h>

const double YS_PI = 3.1415927;

eBullet::eBullet()
{
	//x = 0;
	//y = 0;
	//exist=0;
	//speed=1;
}

eBullet::eBullet(int label)
{
	type = label;
	//x = 0;
	//y = 0;
	//exist=0;
	//speed=1;
}



eBullet::~eBullet()
{
	if (1 == exist)
	{
		exist = 0;
		x = 0;
		y = 0;
	}
}

int eBullet::getType()
{
	return type;
}

bool eBullet::checkHeroColision(Hero &hero)
{
	if((x<=hero.x+25) && (x>=hero.x-25) && (y<=hero.y) && (y>=hero.y-80) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void eBullet::initialize(int cx, int cy, int label)
{
	x = cx;
	y = cy;
	g = 3;
	vx = 20;
	vy = 0;
	if(1==label)
	{
		vy = 0;
	}
	if(2==label)
	{
		vy = -20;
		vx =20;
	}
	if(3==label)
	{
		vy = 0;
		vx =0;
	}
	exist = 1;
	type = label;
}

void eBullet::setV(int vx_, int vy_)
{
	if(3==type)
	{
		vx = vx_;
		vy = vy_;
	}
}

void eBullet::Update(Hero &hero,int right,int bossstate)
{
	if (right == 1 && hero.y<=500 && hero.blockstate==0 && 0 == bossstate)
	{
            x-=10;
	}



	if (1 == exist)
	{
		//printf("spd: %d\n",speed);
		if(1==type)
		{
			x -= vx;
		}

		if(2==type)
		{
			x -=vx;
			vy +=g;
			y+=vy;
		}

		if(3==type)
		{
			x-=vx;
			y-=vy;
		}
	}



		//printf("%d %d %d %d\n", b[0].x, b[0].y, b[0].exist, b[0].speed);


}

void eBullet::Draw()
{
	//printf("draw enemy bullet ");
	int rad = 4;

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
    
    if(2==type)
    {
        rad = 5;
    }
    
    
	if(3==type)
	{
		rad = 6;
		glColor3d(1.0, 0.5, 0.0);
	}

	int i;
	for (i = 0; i<64; i++)
	{
		double angle = (double)i*YS_PI / 32.0;
		double cx = (double)x + cos(angle)*(double)rad;
		double cy = (double)y + sin(angle)*(double)rad;
		glVertex2d(cx, cy);
	}

	glEnd();
}