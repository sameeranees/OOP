#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
//#include "Sound.h"

class GameOverScreen
{
private:
    SDL_Surface* goScreen;
    Mix_Chunk* goSound;
public:
    GameOverScreen();
    ~GameOverScreen();
    void Load();
    void Show(SDL_Surface*, SDL_Window*);
};
