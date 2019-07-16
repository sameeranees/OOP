#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tile.h"
#include "Path.h"
#include "Throne.h"

class EnemyProjectile
{
private:
    float x;
    float y;
    int width;
    int height;
    SDL_Rect spriteClips[22];
    LTexture* spriteSheetTexture;
public:
    EnemyProjectile();
    EnemyProjectile(LTexture*, float, float);
    void Hit(SDL_Renderer* gRenderer);
};
