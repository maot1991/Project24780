#include "HeroAction.h"
#include "Enemy.h"

class Runway
{
public:
    int x1,y1,h,l,w,id;
    void draw();
    void update(Hero &hero,int right,Enemy &enemy,int bossstate);
    void change();
    bool checkroll(double x, double y);
    void checkdie(Hero &hero);
    void checkmons(Enemy &enemy);
    void initialize(int x,int y,int hei,int leng,int width);
    
};






