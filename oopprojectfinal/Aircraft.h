#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tile.h"
#include "HealthBar.h"
#include "Path.h"
#include "AircraftProjectile.h"
#include "EnemyProjectile.h"
#include "GameObject.h"

class Aircraft:public Enemy
{
private:
    AircraftProjectile* aircraftprojectile; //projectile that it will shoot
    SDL_Rect spriteClips[2];
public:
    Aircraft(LTexture*, float, float,int,int);
    Aircraft();
    ~Aircraft();
    void Draw(SDL_Renderer*);
    void Move();
    bool Update(GameObject*, SDL_Renderer* gRenderer);
    SDL_Rect GiveRect();
    bool Attack(SDL_Renderer*);

};
