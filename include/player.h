#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "bullet.h"
#include <iostream>

class Player : public GameObject
{
public:
    Player();
    virtual void Update();
    virtual void Render();
    ~Player(void);

private:
    Vector2 position;
    float speed;
    Texture texture;

    float lastShotTime;
    float timeBetweenShots;

    Sound shotSound;
};

#endif