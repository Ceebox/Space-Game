#include "musicplayer.h"

//Constructor
MusicPlayer::MusicPlayer()
{
    gameObjects.push_back(this); //Add to gameobjects

    //Init audio
    InitAudioDevice();

    //Init music
    music = LoadMusicStream("../assets/Music.mp3");
    PlayMusicStream(music);
    music.looping = true;
}
//Methods
void MusicPlayer::Update()
{
    UpdateMusicStream(music);
}
void MusicPlayer::Render()
{
    //No logic
}
//Vars
//Deconstructor
MusicPlayer::~MusicPlayer()
{
    UnloadTexture(texture);
}