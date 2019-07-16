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
#include "Explosion.h"
#include "Explosion.h"

class SoldierProjectile
{
private:
    float x;
    float y;
    int width;
    int height;
    bool collide;
    bool ProjectileCollide;
    Explosion* explosion; //explosion
    SDL_Rect spriteClips[1];
    LTexture* spriteSheetTexture;
    Sound* SoldierProjectileSound; //sound of it's projectile firing
public:
    SoldierProjectile();
    SoldierProjectile(LTexture*, float, float);
    ~SoldierProjectile();
    bool Hit(SDL_Renderer* gRenderer);
    void Move();
    bool returnCollide();
    bool returnProjectileCollide();
    //bool returnDecreaseHealth();
};
