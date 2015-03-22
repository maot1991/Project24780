

#include <iostream>
#include "HeroAction.h"
class Fire{
private:
    int x;
    int y;
    int f;
    int state;
public:
    Fire();
    void destroy();
    void draw();
    void init(int);
    void update(Hero &hero,int right);
    void hurt(int &blood);
    bool checkHit(int x,int y);
};

