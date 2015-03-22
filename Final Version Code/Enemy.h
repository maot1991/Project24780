#ifndef Enemy_h
#define Enemy_h
#include "EnemyBullet.h"
#include "HeroAction.h"

class Enemy {

private:
	int speed;
	int type;

public:
	int width, height, x, y, exist, vx, vy, roadstate;
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
	Enemy();
	Enemy(int label);
	~Enemy();
};
#endif Enemy