#include "player.h"

//Constructor
Player::Player()
{
    gameObjects.push_back(this); //Add to gameobjects

    //Init image
    Image playerImage = LoadImage("../assets/ship.png");
    ImageRotateCW(&playerImage); //Rotate to align
    texture = LoadTextureFromImage(playerImage);
    texture.height *= 10;
    texture.width *= 10;

    //Init position
    position = {(float)GetScreenWidth() / 8, (float)GetScreenHeight() / 2};

    //Init speed
    speed = -325;

    //Init shots
    timeBetweenShots = 0.45f;
    lastShotTime = (float)GetTime() - timeBetweenShots;

    //Init score
    score = 0;

    //Spawn sfx
    shotSound = LoadSound("../assets/shootSFX.mp3");
}
//Methods
void Player::Update()
{
    //Input
    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && position.y > 64) 
    {
        //Up
        position.y += speed * GetFrameTime();
    }
    else if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && position.y < GetScreenHeight() - 64)
    {
        //Down
        position.y -= speed * GetFrameTime();
    }

    if (IsKeyPressed(KEY_SPACE) && lastShotTime + timeBetweenShots <= (float)GetTime())
    {
        new Bullet(position);

        PlaySound(shotSound);

        lastShotTime = (float)GetTime();
    }
}
void Player::Render()
{
    DrawTexture(texture, position.x - texture.width / 2, position.y - texture.height / 2, WHITE);
}
//Vars
//Deconstructor
Player::~Player()
{
    UnloadTexture(texture);
    UnloadSound(shotSound);
}