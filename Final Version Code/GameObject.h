//
//  GameObject.h
//  worldstate
//
//  Created by TangMao on 14-11-21.
//  Copyright (c) 2014年 TangMao. All rights reserved.
//

#ifndef __worldstate__GameObject__
#define __worldstate__GameObject__

#include <iostream>

class GameObject
{
public:    
    int x,y;
    void Initialize();
    void Update();
    void Draw();
};



#endif /* defined(__worldstate__GameObject__) */
