#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "HealthBar.h"
#include "Tile.h"
#include "Path.h"
#include "TanksProjectile.h"
#include "EnemyProjectile.h"
#include "GameObject.h"

class Tanks:public Enemy
{
private:
    TanksProjectile* tanksprojectile; //it's projectile
    SDL_Rect spriteClips[2];
public:
    Tanks(LTexture*, float, float,int,int);
    Tanks();
    ~Tanks();
    void Draw(SDL_Renderer*);
    void Move();
    SDL_Rect GiveRect();
    bool Attack(SDL_Renderer*);
    bool Update(GameObject*, SDL_Renderer* gRenderer);

    //virtual void GetDestroyed()=0;

};
