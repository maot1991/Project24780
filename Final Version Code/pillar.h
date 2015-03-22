
#include <iostream>
#include "HeroAction.h"
class Pillar{
public:
    int x;
    int y;
    int f;
    int state;
public:
    Pillar();
    void init(int,int);
    void draw();
    void update(Hero &hero,int right,int bossstate);
    void hurt(int &blood);
    bool checkHit (int x,int y);
};
