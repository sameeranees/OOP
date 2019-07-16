#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "HealthBar.h"
#include "Enemy.h"
#include "Tile.h"
#include "Path.h"
#include "GameObject.h"
#include <stdlib.h>

class Throne:public GameObject
{
private:
    //Enemy* enemy;
    SDL_Rect spriteClips[13];
public:
    Throne();
    Throne(LTexture*, float, float,int,int);
    ~Throne();
    void Draw(SDL_Renderer*);
    int GiveMoney();
    void UpdateMoney(int);
    void ShowMoney(SDL_Renderer*);
    bool Update(GameObject*, SDL_Renderer* gRenderer);
    SDL_Rect GiveRect();

};
