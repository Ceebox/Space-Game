////////////////////////////////////////////////////////////////////////////////////
// So, globals are supposed to be a really bad thing to do, but I don't really care.
///////////////////////////////////////////////////////////////////////////////////
#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobject.h"
#include <list>

//All gameobjects in the game
extern std::list<GameObject*> gameObjects;

extern int score;

#endif