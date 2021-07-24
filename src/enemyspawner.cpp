#include "enemyspawner.h"

//Constructor
EnemySpawner::EnemySpawner()
{
    gameObjects.push_back(this); //Add to gameobjects

    //Assign
    timeBetweenSpawns = 2.6f;
    timeAtLastSpawn = GetTime() - timeBetweenSpawns;
}
//Methods
void EnemySpawner::Update()
{
    if (timeAtLastSpawn + timeBetweenSpawns <= (float)GetTime())
    {
        Spawn();

        timeAtLastSpawn = (float)GetTime();
    }
}
void EnemySpawner::Render()
{
    //Render nothing
}
//Vars
//Deconstructor
EnemySpawner::~EnemySpawner()
{
    enemies.clear();
}

////////////////////////////////
void EnemySpawner::Spawn()
{
    Enemy* enemy = new Enemy();
    enemies.push_back(enemy);
}