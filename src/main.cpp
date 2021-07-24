//All this code is mine, no yoinking systems from stackoverflow
//Includes are completely messed up, and the collision system sucks, but not bad for my first C++ program

#include "globals.h"
#include "raylib.h"
#include "gameobject.h"
#include "background.h"
#include "player.h"
#include "collisionhandler.h"
#include "enemyspawner.h"
#include "musicplayer.h"
#include "scoredisplay.h"
#include <list>
#include <iostream>

int main(void)
{
    // Init
    //Screen
    InitWindow(1920, 1080, "C++ Game");

    Background bg;
    CollisionHandler handler;
    Player player;
    EnemySpawner spawner;
    MusicPlayer musicPlayer;
    ScoreDisplay display;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        for (GameObject* gameObject : gameObjects)
        {
            gameObject->Update();
        }
        // Draw
        BeginDrawing();
        ClearBackground(WHITE);

        for (GameObject *gameObject : gameObjects)
        {
            gameObject->Render();
        }

        EndDrawing();
    }

    // De-Init
    CloseWindow(); // Close window and OpenGL context

    //End
    return 0;
}