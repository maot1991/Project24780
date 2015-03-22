#include "fssimplewindow.h"
#include <vector>
#include "HeroAction.h"
using namespace std;

class Item
{
public:
	int itemx, itemy, r, g, b, type;
	void moveItem(const int vx, const int vy);
	int checkHit(int playerX, int playerY, int playersizex, int playersizey) const;
	void draw() const;
};


class element
{
private:
	vector <Item> items;
public:
	element();
	~element();
	void cleanup();
	void addelement(const int x, const int y);
	void drawing() const;
	void trace(const int dx);
	int checkHit(const Hero hero);
	void update(Hero &hero, int dx);
};