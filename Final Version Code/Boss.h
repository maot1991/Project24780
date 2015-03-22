#ifndef Boss_h
#define  Boss_h

#include "EnemyBullet.h"

class Boss {

private:
	int speed;
	int type;

public:
	int width, height, x, y, exist, vx, vy, roadstate, blood,heading;
	int numBullet;
	void Update(Hero &hero,int right,int bossstate);
	eBullet *b;
	void Initialize(int, int, int, int, int);
	void remove();
	void Draw();
	void walk();
	void shoot();
	bool checkHeroColision(Hero &hero);
	int getType();
	Boss();
    Boss(int x);
	//~Boss();
};



#endif Boss_h