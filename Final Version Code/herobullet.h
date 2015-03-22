#include <vector>
#include "fssimplewindow.h"
#include "HeroAction.h"
#include "item.h"
#include "enemy.h"
#include "Boss.h"
using namespace std;

class HeroBullet
{
public:
	int x,y,dir;
	int checkHit(const Enemy enemy) const;
	int checkHitb(const Boss boss) const;
	void moveBullet(const int vx, const int vy);
	void draw() const;
};

class Explosion : public HeroBullet
{
public:
	int r;
	void draw();
};

class BulletDrawing
{
private:
	std::vector <Explosion> exp;
	std::vector <HeroBullet> bullets;
public:
	BulletDrawing();
	~BulletDrawing();
	void cleanup();
	void addExplosion(const int x, const int y);
	void addBullet(const Hero hero);
	void drawing() const;
	void trace();
	int checkHitenemy(const Enemy enemy);
	int checkHitBoss(const Boss boss);
	void update(Hero &hero, element &elem, Enemy &enemy, Boss &boss, const int space, int bossstate,int dx);
	void drawmenu(const Hero hero, const Boss boss, const int bossstate);
};