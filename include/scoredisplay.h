#ifndef SCORE_DISPLAY_H
#define SCORE_DISPLAY_H

#include "globals.h"
#include "raylib.h"

class ScoreDisplay : public GameObject
{
    public:
        ScoreDisplay(void);
        virtual void Update();
        virtual void Render();
        ~ScoreDisplay(void);
};

#endif