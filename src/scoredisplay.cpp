#include "scoredisplay.h"

//Constructor
ScoreDisplay::ScoreDisplay()
{
    gameObjects.push_back(this); //Add to gameobjects
}
//Methods
void ScoreDisplay::Update()
{
    //No logic
}
void ScoreDisplay::Render()
{
    DrawText(TextFormat("Score: %01i", score), 100, 25, 32, WHITE);
}
//Vars
//Deconstructor
ScoreDisplay::~ScoreDisplay()
{
    //No logic
}