#include "background.h"

//Constructor
Background::Background()
{
    gameObjects.push_back(this); //Add to gameobjects

    //Init texture
    Image backgroundImage = LoadImage("../assets/background.png");
    texture = LoadTextureFromImage(backgroundImage);
    SetTextureFilter(texture, FILTER_POINT);
    //Texture rect
}
//Methods
void Background::Update()
{
    //No logic
}
void Background::Render()
{
    // DrawTexture(texture, GetScreenWidth() / 2 - texture.width / 2, GetScreenHeight() / 2 - texture.height / 2, WHITE);
    Rectangle source = {(float)GetScreenWidth() / 2, (float)GetScreenWidth() / 2 - texture.width, (float)GetScreenHeight() / 2, (float)GetScreenHeight() / 2 - texture.height};
    Rectangle destination = {0, 0, (float)GetScreenWidth() * 2, (float)GetScreenHeight() * 2};
    DrawTextureTiled(texture, source, destination, {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, 0, 10, WHITE);
}
//Vars
//Deconstructor
Background::~Background()
{
    UnloadTexture(texture);
}