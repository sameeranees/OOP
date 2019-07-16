#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Tile.h"
#include "Tower.h"
#include "RocketBall.h"
#include <chrono>
#include <cmath>
#include <ctime>
#include "GameObject.h"

class RocketTurret:public Tower
{
private:
    SDL_Rect spriteClips[2]; // two spriteclips
    RocketBall * rocketball;// gets rocketball
public:
    RocketTurret(LTexture* image, float x, float y,int,int); //overloaded constructor
    RocketTurret(); //constructor
    ~RocketTurret(); //distructor
    bool Update(GameObject*, SDL_Renderer* gRenderer);
    void Draw(SDL_Renderer* gRenderer);
    bool CheckAttack(GameObject*);
    bool Attack(SDL_Renderer * gRenderer);
    bool Reload(SDL_Renderer * gRenderer);
    SDL_Rect GiveRect();
};
