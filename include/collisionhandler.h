#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include "globals.h"
#include "raylib.h"
#include "collisionobjects.h"
#include "bullet.h"
#include "enemy.h"
#include <stdio.h>

class CollisionHandler : public GameObject
{
    public:
        CollisionHandler(void);
        virtual void Update();
        virtual void Render();
        ~CollisionHandler(void); 
};

#endif