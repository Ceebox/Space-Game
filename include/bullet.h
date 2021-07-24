#ifndef BULLET_H
#define BULLET_H

#include "globals.h"
#include "collisionobjects.h"
#include "raylib.h"
#include <algorithm>

class Bullet : public GameObject
{
    public:
        Bullet(Vector2 spawnPosition);
        virtual void Update();
        virtual void Render();
        virtual ~Bullet(void);

        void Destroy();
        Rectangle GetRect();

    private:
        void UpdateCollisionRectPosition();

        Vector2 position;
        float bulletSpeed;
        Texture texture;
        Sound spawnSound;

        float timeAlive;

        Rectangle collisionRect;
};

#endif