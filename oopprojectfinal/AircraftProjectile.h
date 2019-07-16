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
#include "EnemyProjectile.h"
#include "Explosion.h"

class AircraftProjectile
{
private:
    float x;
    float y;
    int width;
    int height;
    bool collide;
    bool ProjectileCollide;
    SDL_Rect spriteClips[1];
    LTexture* spriteSheetTexture;
    Explosion* explosion;
    Sound* AircraftProjectileSound;
public:
    AircraftProjectile();
    ~AircraftProjectile();
    AircraftProjectile(LTexture*, float, float);
    bool Hit(SDL_Renderer* gRenderer);
    void Move();
    bool returnCollide();
    bool returnProjectileCollide();
};
