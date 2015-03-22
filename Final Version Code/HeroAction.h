//
//  HeroAction.h
//  project
//
//  Created by Jingsi Zhao on 11/17/14.
//  Copyright (c) 2014 CMU. All rights reserved.
//

#ifndef project_HeroAction_h
#define project_HeroAction_h

class Hero
{
public:
    int facing,blood,nbullet,stagestate,vy,g;
    int x,y;
    int keystate;
    int roadstate;
    int blockstate;
    
    void Initialize(int stage1);//use the heght of the first stage
    void Update(int stage2,int stage1,int bossstate,int right,int left,int up,int down,int space);// if boss appears, hero can move forward and back on the screen
    int CheckDie(void);
    void Draw(int facing, int roadstate);
    
};

#endif
