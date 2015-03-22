
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <stdio.h>
#include <stdlib.h>
#include "DrawHero.h"
#include "HeroAction.h"

//hero's y is its foot's height


void Hero::Initialize(int stage1)
{
    facing=1;
    vy=0;
    x=200;
    g=10;
    y=stage1;
    blood=10;
    keystate=0;
    roadstate=1;
	nbullet=100;
    blockstate=0;
}
int Hero::CheckDie(void){
    
    if (blood<=0||y>700) {
        printf("die\n");
        return 1;
        
    }
    else{
        return 0;
    }
    
}
void Hero::Draw(int facing, int roadstate){
    
    if((facing==1 && y==500)||(facing==1 && y==300 && vy==0)){
        DrawHero(x, y, 0);
    }
    else if((facing==2 && y==500)||(facing==2 && y==300 && vy==0)){
        DrawHero(x, y, 1);
    }
    else if((facing==1 && roadstate==2)||(facing==1 && roadstate==4)){
        DrawHero(x, y, 2);
    }
    else if((facing==2 && roadstate==2)||(facing==2 && roadstate==4)){
        DrawHero(x, y, 3);
    }
}



void Hero::Update(int stage2,int stage1,int bossstate, int right, int left, int up, int down, int space){
  
    
    //printf("%d %d \n",facing, roadstate);
    if(right==1 && bossstate==0)//walking
    {
        facing=1;
    }
    if(left==1 && bossstate==0)//walking
    {
        facing=2;
    }
    if(right==1 && bossstate==1)//walking
    {
        facing=1;
        x=x+20;
        if (x>750) {
            x=750;
        }
        if (x<50) {
            x=50;
        }
    }
    if(left==1 && bossstate==1)//walking
    {
        facing=2;
        x=x-20;
        if (x>750) {
            x=750;
        }
        if (x<50) {
            x=5;
        }
        
    }
    
    
    //if (up==1 && vy==0) {
        //keystate=1;
   // }
    //else if (down==1 && vy==0){
        //keystate=2;
   // }
    
    
    

    
   
    if (up==1){
        switch (roadstate) {
            case 1:
                roadstate = 2;
                vy=-70;
                break;
            case 3:
                roadstate = 4;
                vy=-70;
                break;
            case 2:
            case 4:
                break;
            default:
                break;
            }

            
        }
    if (down==1){
        switch (roadstate) {
            case 3:
                roadstate = 2;
                vy=70;
                break;
            case 1:
            case 2:
            case 4:
                break;
            default:
                break;
        }
        
        
    }
  
   
    
    
    
    
    
    
    if (space==1) //shoot
    {
        //printf("shoot\n");
        //DrawHero(x, y, 1);//test
    }
    if (blood==0)//check die
    {
        //DrawHero(x, y, 1);
        //Die();
    }
    
    //printf("%d\n",y);
    //printf("%d\n",vy);
    if (roadstate==2||roadstate==4) {
        vy=vy+g;
        y=y+vy;
    }
    
    if (roadstate==1) {
        roadstate=2;
    }
    if(roadstate==3){
        roadstate=4;
    }
    blockstate=0;
    //printf("%d\n",y);
    Draw(facing, roadstate);
}

