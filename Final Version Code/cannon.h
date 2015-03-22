
#include "CannonFire.h"
#include <iostream>
#include "HeroAction.h"

class Cannon{
public:
    
    int x,y;
    int changer;
    int degStatus;
    int initchanger;
    double degree;
    
public:
    void DegreeChange();
    Cannon();
    void init(const int x,int dif); //dif = 100,200 400
    void draw();
    void update(Hero hero,int right,Cannonelement &e,int bossstate);
    void hurt (int &blood);
    bool checkHit(int x,int y);
    void ball(int x,int y);
};


