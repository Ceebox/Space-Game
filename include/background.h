#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "globals.h"
#include "raylib.h"

class Background : public GameObject
{
    public:
        Background(void);
        virtual void Update();
        virtual void Render();
        ~Background(void);
    private:
        Texture texture;
        Rectangle source;
        Rectangle destination;
};

#endif