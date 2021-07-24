#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include "globals.h"
#include "raylib.h"

class MusicPlayer : public GameObject
{
public:
    MusicPlayer(void);
    virtual void Update();
    virtual void Render();
    ~MusicPlayer(void);

private:
    Texture texture;
    Music music;
};

#endif