#include "collisionhandler.h"

/////////////////////////////////////////////////////////////////////
// I would like to formally appologise if you have to read this code.
/////////////////////////////////////////////////////////////////////

//Constructor
CollisionHandler::CollisionHandler()
{
    gameObjects.push_back(this); //Add to gameobjects
}
//Methods
void CollisionHandler::Update()
{
    //Check collision, i = bullet, j = enemy
    for (Bullet* &bullet : bulletCollisionObjects)
    {
        for (Enemy* &enemy : enemyCollisionObjects)
        {
            bool collided = CheckCollisionRecs(bullet->GetRect(), enemy->GetRect());
            if (collided)
            {
                bullet->Destroy();
                enemy->Destroy();
            }
        }
    }
}
void CollisionHandler::Render()
{
    //Don't render anything
}
//Vars
//Deconstructor
CollisionHandler::~CollisionHandler()
{
    //Nope
}