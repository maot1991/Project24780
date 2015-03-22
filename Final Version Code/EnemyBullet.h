#ifndef eBullet_h
#define eBullet_h
#include "heroAction.h"


class eBullet
{
private:
	int type;
public:
	int x, y, exist, vx, vy;
	int g;
	void Draw();
	void initialize(int cx, int cy, int label);
	eBullet();
	eBullet(int label);
	~eBullet();
	void Update(Hero &hero,int right,int bossstate);
	bool checkHeroColision(Hero &hero);
    void setV(int vx_, int vy_);
	int getType();
};
#endif eBullet