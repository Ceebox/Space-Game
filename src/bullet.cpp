#include "bullet.h"
#include <stdio.h>

//Constructor
Bullet::Bullet(Vector2 spawnPosition)
{
    gameObjects.push_back(this); //Add to gameobjects
    bulletCollisionObjects.push_back(this); //Add to collision

    int random = GetRandomValue(0, 2);

    //Init texture
    Image bulletImage = LoadImage("../assets/bullet.png");
    if (random == 1) //Random texture
        bulletImage = LoadImage("../assets/bullet2.png");
    ImageRotateCW(&bulletImage); //Rotate to align
    texture = LoadTextureFromImage(bulletImage);
    texture.height *= 10;
    texture.width *= 10;

    //Assign speed
    bulletSpeed = 500;

    //Assign position
    position = spawnPosition;
    position.x += 180;

    //Assign collision properties
    //Dimensions
    collisionRect.height = texture.height;
    collisionRect.width = texture.width;
    //Position
    UpdateCollisionRectPosition();

    //Time alive
    timeAlive = 0;
}
//Methods
void Bullet::Update()
{
    position.x += bulletSpeed * GetFrameTime();

    if (timeAlive < 7)
    {
        timeAlive += GetFrameTime();
        UpdateCollisionRectPosition();
    }
    else
    {
        Destroy();
    }
}
void Bullet::Render()
{
    DrawTexture(texture, position.x - texture.width / 2, position.y - texture.height / 2, WHITE);
}
inline void Bullet::UpdateCollisionRectPosition()
{
    collisionRect.x = position.x - texture.width / 2;
    collisionRect.y = position.y - texture.height / 2;
}
Rectangle Bullet::GetRect()
{
    return collisionRect;
}
void Bullet::Destroy()
{
    delete this;
}

//Vars
//Deconstructor
Bullet::~Bullet()
{
    //Unload everything and delete from list
    bulletCollisionObjects.erase(std::remove(bulletCollisionObjects.begin(), bulletCollisionObjects.end(), this)); //delete from collision detection
    gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), this)); //delete gameobject from array
    UnloadTexture(texture);
}