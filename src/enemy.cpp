#include "enemy.h"

//Constructor
Enemy::Enemy()
{
    gameObjects.push_back(this); //Add to gameobjects
    enemyCollisionObjects.push_back(this);

    id = GetRandomValue(0, 2);

    switch (id)
    {
    case 0:
    {
        //Texture
        Image enemyImageOne = LoadImage("../assets/enemy1.png");
        ImageRotateCW(&enemyImageOne); //Rotate to align
        texture = LoadTextureFromImage(enemyImageOne);
        texture.height *= 10;
        texture.width *= 10;

        //Speed
        speed = -100;
        break;
    }
    case 1 : 
    {
        //Texture
        Image enemyImageTwo = LoadImage("../assets/enemy2.png");
        ImageRotateCW(&enemyImageTwo); //Rotate to align
        texture = LoadTextureFromImage(enemyImageTwo);
        texture.height *= 10;
        texture.width *= 10;

        //Speed
        speed = -150;
        break; 
    } case 2:
    {
        //Texture
        Image enemyImageThree = LoadImage("../assets/enemy3.png");
        ImageRotateCW(&enemyImageThree); //Rotate to align
        texture = LoadTextureFromImage(enemyImageThree);
        texture.height *= 10;
        texture.width *= 10;

        //Speed
        speed = -165;
        break;
    }
    default:
        printf("Uh oh");
        break;
    }

    position.x = GetScreenWidth() + 150;
    position.y = GetRandomValue(64, GetScreenHeight() - 64);

    //Collision
    //Dimensions
    collisionRect.height = texture.height;
    collisionRect.width = texture.width;
    //Position
    UpdateCollisionRectPosition();
}
//Methods
void Enemy::Update()
{
    position.x += speed * GetFrameTime();
    UpdateCollisionRectPosition();
}
void Enemy::Render()
{
    DrawTexture(texture, position.x - texture.width / 2, position.y - texture.height / 2, WHITE);
}
inline void Enemy::UpdateCollisionRectPosition()
{
    collisionRect.x = position.x - texture.width / 2;
    collisionRect.y = position.y - texture.height / 2;
}
Rectangle Enemy::GetRect()
{
    return collisionRect;
}
void Enemy::Destroy()
{
    delete this;
}
//Vars
//Deconstructor
Enemy::~Enemy()
{
    //Increase score
    ++score;

    //Unload everything
    enemyCollisionObjects.erase(std::remove(enemyCollisionObjects.begin(), enemyCollisionObjects.end(), this)); //delete from collision detection
    gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), this)); //delete gameobject from array
    UnloadTexture(texture);
}