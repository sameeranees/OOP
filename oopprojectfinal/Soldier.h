#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tile.h"
#include "Path.h"
#include "SoldierProjectile.h"
#include "EnemyProjectile.h"
#include "GameObject.h"
#include "Explosion.h"
#include "HealthBar.h"

class Soldier:public Enemy
{
private:
    SoldierProjectile* soldierprojectile;
    SDL_Rect spriteClips[2];
public:
    Soldier(LTexture*, float, float,int,int);
    Soldier();
    ~Soldier();
    void Draw(SDL_Renderer*);
    bool Update(GameObject*, SDL_Renderer* gRenderer);
    void Move();
    SDL_Rect GiveRect();
    bool Attack(SDL_Renderer*);
    //virtual void Attack()=0;
    //virtual void GetDestroyed()=0;

};
