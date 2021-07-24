#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include "globals.h"
#include "collisionhandler.h"
#include "enemy.h"
#include <iostream>

class EnemySpawner : public GameObject
{
    public:
        EnemySpawner();
        virtual void Update();
        virtual void Render();
        ~EnemySpawner(void);

    private:
        std::list<GameObject *> enemies;
        void Spawn();
        float timeAtLastSpawn;
        float timeBetweenSpawns;
};

#endif