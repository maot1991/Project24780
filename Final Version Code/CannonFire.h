#include "fssimplewindow.h"
#include <vector>
#include "HeroAction.h"
using namespace std;

class CannonItem
{
public:
	int itemx, itemy,r, g, b, type;
    double degree;
	void moveItem(const int vx, const int vy);
	int checkHit(int playerX, int playerY, int playersizex, int playersizey) const;
	void draw() const;
};


class Cannonelement
{
private:
	vector <CannonItem> cannonitems;
public:
	Cannonelement();
	~Cannonelement();
	void cleanup();
	void addelement(const int x, const int y,double degree);
	void drawing() const;
	void trace(const int dx);
	int checkHit(const Hero hero);
	void update(Hero &hero, int dx);
};