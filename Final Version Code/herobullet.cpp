#include <vector>
#include "fssimplewindow.h"
//#include "herobullet.h"
#include "herobullet.h"
#include "ysglfontdata.h"
#include <iostream>
#include <math.h>
using namespace std;


int HeroBullet::checkHit(const Enemy enemy) const 
{
	int relativeX, relativeY;
	relativeX = x - enemy.x;
	relativeY = y - enemy.y;
	if (relativeX >= 0 && relativeX < enemy.width && relativeY <= 0 && relativeY > -enemy.height)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int HeroBullet::checkHitb(const Boss boss) const 
{
	int relativeX, relativeY;
	relativeX = x - boss.x;
	relativeY = y - boss.y;
	if (relativeX >= 0 && relativeX < boss.width && relativeY <= 0 && relativeY > -boss.height)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void HeroBullet::moveBullet(const int vx, const int vy)
{
	x += vx*(3 - 2*dir);
	y += vy;
}

void HeroBullet::draw() const
{
	int rad = 3;

	glColor3d(0.0, 0.0, 0.0);

	glBegin(GL_POLYGON);


	int i;
	for (i = 0; i<64; i++)
	{
		double angle = (double)i*3.1415927 / 32.0;
		double cx = (double)x + cos(angle)*(double)rad;
		double cy = (double)y + sin(angle)*(double)rad;
		glVertex2d(cx, cy);
	}

	glEnd();
}
//-------------------------------------------------------------------------------------------------

void Explosion::draw()
{
	glBegin(GL_POLYGON);
	glColor3ub(255,0,0);
    for(int angle=0; angle<=360; angle+=30)
    {
        double a=(double)angle*2.0*3.1415927/360.0;
        double s=sin(a);
        double c=cos(a);
        
        glVertex2d(x-20+c*r,y+10+s*r);
    }
    glEnd();
}



//-------------------------------------------------------------------------------------------------

BulletDrawing::BulletDrawing()
{
}

BulletDrawing::~BulletDrawing()
{
	cleanup();
}

void BulletDrawing::cleanup()
{
	bullets.resize(0);
	exp.resize(0);
}

void BulletDrawing::addExplosion(const int x, const int y)
{
	Explosion e;
	e.x = x;
	e.y = y;
	e.r = 0;
	exp.push_back(e);
}

void BulletDrawing::addBullet(const Hero hero)
{
	HeroBullet v;
	v.x = hero.x;
	v.y = hero.y-50;
	v.dir = hero.facing;
	bullets.push_back(v);
}

void BulletDrawing::drawing(void) const
{
	for (int i = 0; i<bullets.size(); ++i)
	{
		bullets[i].draw();
	}
}

void BulletDrawing::trace()
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].x > 800||bullets[i].x < 0)
		{
			bullets.erase(bullets.begin() + i); //erase the ith bullet.
		}
		else
		{
			bullets[i].moveBullet(30, 0);
		}
	}

	drawing();
}

int BulletDrawing::checkHitenemy(const Enemy enemy) 
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].checkHit(enemy) == 1)
		{
			addExplosion(bullets[i].x,bullets[i].y);
			bullets.erase(bullets.begin()+i); //erase the ith bullet.
			return 1;
		}
	}

	return 0;
}

int BulletDrawing::checkHitBoss(const Boss boss)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].checkHitb(boss) == 1)
		{
			addExplosion(bullets[i].x,bullets[i].y);
			bullets.erase(bullets.begin()+i); //erase the ith bullet.
			return 1;
		}
	}

	return 0;
}

void BulletDrawing::update(Hero &hero, element &elem, Enemy &enemy, Boss &boss, const int space, int bossstate, int dx)
{
	trace();
	if (space == 1 && hero.nbullet > 0)
	{
		addBullet(hero);
		hero.nbullet -=1; 
	}
	else
	{

	}
	if(bossstate == 0)
	{
		if (checkHitenemy(enemy) == 1)
		{
			enemy.remove();
			elem.addelement(enemy.x,enemy.y);
		}
	}
	else
	{
		if (checkHitBoss(boss) == 1)
		{
			boss.blood-=10;
			int x = 50+rand()%700;
			elem.addelement(x,500);
			printf("bosshealth = %d/n", boss.blood);
		}
	}

	for (int i = 0; i < exp.size(); i++)
	{
		exp[i].draw();
		exp[i].r +=3;
		exp[i].x -= dx;
		if (exp[i].r > 30)
		{
			exp.erase(exp.begin()+i);
		}
	}

}

void BulletDrawing::drawmenu(const Hero hero,const Boss boss, const int bossstate)
{
	char a[10];
	sprintf(a, "%d", hero.nbullet);
	glColor3ub(0,0,0);
	glRasterPos2d(10,25);
	YsGlDrawFontBitmap16x20("Ammo:");
	glRasterPos2d(100,25);
	YsGlDrawFontBitmap16x20(a);

	int l = hero.blood;
	if (l<0)
	{
		l = 0;
	}
	glRasterPos2d(10,50);
	YsGlDrawFontBitmap16x20("Health:");
	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3ub(255,0,0);
	glVertex2i(120,33);
	glColor3ub((5-l/2)*51,l/2*51,0);
	glVertex2i(120+l*20,33);
	glColor3ub((5-l/2)*51,l/2*51,0);
	glVertex2i(120+l*20,48);
	glColor3ub(255,0,0);
	glVertex2i(120,48);
	glEnd();

	if(bossstate == 1)
	{
		int m = boss.blood;
		glBegin(GL_QUADS);
		glColor3ub(255,125,0);
		glVertex2i(750,550);
		glVertex2i(750-m*5,550);
		glVertex2i(750-m*5,565);
		glVertex2i(750,565);
		glEnd();
	}
}


