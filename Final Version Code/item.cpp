#include "fssimplewindow.h"
#include <vector>
#include "item.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int sizex = 30,sizey = 30;

void Item::moveItem(const int vx, const int vy)
{
	itemx -= vx;
	itemy += vy;
}

int Item::checkHit(int playerx, int playery, int playersizex, int playersizey) const 
{
	int relativeX, relativeY;
	relativeX = itemx - playerx;
	relativeY = playery - itemy;
	if (((relativeX<0 && relativeX > (playersizex + sizex)/-2)||(relativeX >= 0 && relativeX < (playersizex + sizex)/2)) && relativeY >= -sizey/2 && relativeY < playersizey + sizey/2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Item::draw() const
{
	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3ub(175, 255, 0);
	glVertex2i(itemx - sizex / 2, itemy);
	glColor3ub(r, g, b);
	glVertex2i(itemx + sizex / 2, itemy);
	glColor3ub(r, g, b);
	glVertex2i(itemx + sizex / 2, itemy - sizey);
	glColor3ub(r, g, b);
	glVertex2i(itemx - sizex / 2, itemy - sizey);
	glEnd();
}



element::element()
{
}

element::~element()
{
	cleanup();
}

void element::cleanup()
{
	items.resize(0);
}

void element::addelement(int x, int y)
{
	int currenttime = (int)time(NULL);
	srand(currenttime);

	int a = rand() % 2;
	int b = rand() % 2;
    if (a == 0 && items.size() < 3) // 1/2 chance drop item.
	{
		//printf("a ===================================== %d", a);
		Item v;
		v.itemx = x;
		v.itemy = y;
		if (rand() % 2 == 0)
		{
			v.r = 0;
			v.g = 255;
			v.b = 0;
			v.type = 1; //effect = heal
		}
		else
		{
			v.r = 255;
			v.g = 0;
			v.b = 0;
			v.type = 2; //effect = ammo 
		}
		items.push_back(v);
	}
	else
	{
		//printf("a ===================================== %d", a);
	}
}

void element::drawing(void) const
{
	for (int i = 0; i<items.size(); ++i)
	{
		items[i].draw();
	}
}

void element::trace(int dx)
{

	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i].itemx < 0)
		{
			items.erase(items.begin() + i); //erase the ith item.
		}
		else
		{
			items[i].moveItem(dx, 0);
		}
	}

	drawing();
}

int	element::checkHit(const Hero hero) 
{
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i].checkHit(hero.x, hero.y, 50, 100) == 1)
		{
			int a = items[i].type;
			items.erase(items.begin()+i); //erase the ith item.
			return a;
		}
	}
	return 0;
}

void element::update(Hero &hero, const int dx)
{
	trace(dx);
	int t = checkHit(hero);
	if (t == 1)
	{
		hero.blood += 3;
		if (hero.blood > 10)
		{
			hero.blood = 10;
		}
	}
	else if (t == 2)
	{
		hero.nbullet += 50;
	}
	else
	{
		//do nothing
	}
}

