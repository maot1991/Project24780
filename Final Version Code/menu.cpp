#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <stdio.h>
#include "DrawHero.h"
#include "menu.h"


void GameMenu::Initialize(void)
{
    lastKey=0;
}



void GameMenu::RunGameMenuOneStep(void)
{
	lastKey = FsInkey();
    
    glColor3ub(0, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(260, 300);
    glVertex2i(550, 300);
    glVertex2i(550, 340);
    glVertex2i(260, 340);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex2i(240, 390);
    glVertex2i(570, 390);
    glVertex2i(570, 430);
    glVertex2i(240, 430);
    glEnd();
    
    glColor3ub(255,200,255);
    
    glRasterPos2d(270,180);
    YsGlDrawFontBitmap20x32("Phoenix Legend");
    
    glColor3ub(0,0,0);
    
    glRasterPos2d(280,330);
    YsGlDrawFontBitmap16x24("Press S to Start");
    
    glRasterPos2d(260,420);
    YsGlDrawFontBitmap16x24("Press ESC to Close");
    
    FsSwapBuffers();
    
    FsSleep(10);
}

/*int main(void)
{
    FsOpenWindow(16,16,800,600,1);
    
    int state=0; // 0:menu  1:game  2:terminate
    GameMenu menu;
    
    while(2!=state)
    {
        switch(state)
        {
            case 0:
            {
                menu.RunGameMenuOneStep();
                if(FSKEY_S==menu.lastKey)
                {
                    state=1;
                    //RunGame();
                    printf("1");//test
                }
                else if(FSKEY_ESC==menu.lastKey)
                {
                    state=2;
                }
            }
                break;
            case 1:
            {
                state=0;
            }
                break;
        }
    }
    return 0;
}*/

