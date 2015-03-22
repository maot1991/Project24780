//
//  DrawMonster.h
//  Quiz1
//
//  Created by Li Wan on 11/17/14.
//  Copyright (c) 2014 CMU. All rights reserved.
//

#ifndef __Quiz1__DrawMonster__
#define __Quiz1__DrawMonster__

#include <stdio.h>
#include "fssimplewindow.h"
#include <math.h>

const double PI=3.1415927;
void DrawCircle(int cx,int cy,int rad,int indicator);
void DrawSemicircle(int cx,int cy,int rad, int orientation);
void DrawMonster1(int x, int y,int state,double theta);
void DrawMonster2(int x,int y,int state);
void DrawMonster3(int x,int y,int state);
void DrawMonster4(int x,int y,int state);
void DrawBoss(int x,int y,int state,double theta);
#endif /* defined(__Quiz1__DrawMonster__) */
