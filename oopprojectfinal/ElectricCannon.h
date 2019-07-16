#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Tile.h"
#include "Tower.h"
#include "Electricity.h"
#include <cmath>
#include <ctime>

class ElectricCannon:public Tower
{
private:
    SDL_Rect spriteClips[2];
    Electricity * electricity; //the projectile it fires
public:
    ElectricCannon(LTexture* image, float x, float y,int,int);
    ElectricCannon();
    ~ElectricCannon();
    bool Update(GameObject*, SDL_Renderer* gRenderer);
    void Draw(SDL_Renderer* gRenderer);
    bool Attack(SDL_Renderer * gRenderer);
    bool CheckAttack(GameObject*);
    bool Reload(SDL_Renderer * gRenderer);
    SDL_Rect GiveRect();
};
