#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Tile.h"
#include "Tower.h"
#include "CannonBall.h"
#include "RocketBall.h"
#include "Electricity.h"

class Explosion
{
private:
    float x;
    float y;
    int i=1;
    int width;
    int height;
    SDL_Rect spriteClips[22];
    LTexture* spriteSheetTexture;
    Sound* ExplosionSound; //the explosion sound
public:
    Explosion();
    ~Explosion();
    Explosion(LTexture*, float, float);
    bool Hit(SDL_Renderer*);
};
