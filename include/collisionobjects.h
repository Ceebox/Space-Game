#ifndef COLLISION_OBJECTS_H
#define COLLISION_OBJECTS_H

#include <list>

class Bullet;
class Enemy;

//Objects to be processed for collision
extern std::list<Bullet *> bulletCollisionObjects;
extern std::list<Enemy *> enemyCollisionObjects;

#endif