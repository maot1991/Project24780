#include "fssimplewindow.h"
#include <vector>
#include "CannonFire.h"
#include "math.h"

using namespace std;

const int sizex = 5,sizey = 5;

void CannonItem::moveItem(const int vx, const int vy)
{
    
    
	itemx -= vx-10*sin(degree);
	itemy += vy+10*cos(degree);
    
}

int CannonItem::checkHit(int playerx, int playery, int playersizex, int playersizey) const
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

void CannonItem::draw() const
{
    int rad = 15;
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 0);
	
	for (int i = 0; i<64; i++)
	{
		double angle = (double)i*3.1415926 / 32.0;
		double cx = (double)itemx + cos(angle)*(double)rad;
		double cy = (double)itemy + sin(angle)*(double)rad;
		glVertex2d(cx, cy);
	}
    
	glEnd();
}



Cannonelement::Cannonelement()
{
}

Cannonelement::~Cannonelement()
{
	cleanup();
}

void Cannonelement::cleanup()
{
	cannonitems.resize(0);
}

void Cannonelement::addelement(int x, int y,double degree)
{
	//int a = rand() % 4;
	//int b = rand() % 2;
    
    
    CannonItem v;
    v.itemx = x;
    v.itemy = y;
    v.degree = degree;
    
    v.r = 0;
    v.g = 255;
    v.b = 0;
    v.type = 1; //effect = heal
    
    
    cannonitems.push_back(v);
	
	
}

void Cannonelement::drawing(void) const
{
	for (int i = 0; i<cannonitems.size(); ++i)
	{
		cannonitems[i].draw();
	}
}

void Cannonelement::trace(int dx)
{
    
	for (int i = 0; i < cannonitems.size(); ++i)
	{
		if (cannonitems[i].itemx < 0)
		{
			cannonitems.erase(cannonitems.begin() + i); //erase the ith item.
		}
		else
		{
			cannonitems[i].moveItem(dx, 0);
		}
	}
    
	drawing();
}

int	Cannonelement::checkHit(const Hero hero)
{
	for (int i = 0; i < cannonitems.size(); ++i)
	{
		if (cannonitems[i].checkHit(hero.x, hero.y, 50, 100) == 1)
		{
			int a = cannonitems[i].type;
			cannonitems.erase(cannonitems.begin()+i); //erase the ith item.
			return a;
		}
	}
	return 0;
}

void Cannonelement::update(Hero &hero, const int dx)
{
	trace(dx);
	int t = checkHit(hero);
	if (t == 1)
	{
		hero.blood -= 2;	
	}
	else
	{
		//do nothing
	}
}