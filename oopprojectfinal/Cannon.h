#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Tile.h"
#include "Tower.h"
#include "CannonBall.h"
#include <cmath>
#include <ctime>

class Cannon:public Tower
{
private:
    SDL_Rect spriteClips[2];// two spriteclips
    CannonBall * cannonball;//gets cannonball
public:
    Cannon(LTexture* image, float x, float y,int,int);//overloaded constructor
    Cannon();//constructor
    ~Cannon();//destructor
    bool Update(GameObject*, SDL_Renderer* gRenderer);
    void Draw(SDL_Renderer* gRenderer);
    bool Attack(SDL_Renderer * gRenderer);
    bool CheckAttack(GameObject*);
    bool Reload(SDL_Renderer * gRenderer);
    SDL_Rect GiveRect();
};

