#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "GameObject.h"
#include "Tile.h"
#include "Path.h"

class Enemy:public GameObject
{
protected:
    float speedx;
    float speedy;
    int i=0;
    Path path; //to track which path enemy is currently on
    SDL_Rect spriteClips[1];
public:
    Enemy(LTexture*, float, float,int,int);
    Enemy();
    virtual bool Update(GameObject*, SDL_Renderer* gRenderer)=0;
    virtual ~Enemy();
    virtual void Move() = 0;
    virtual void Draw(SDL_Renderer*)=0;
    virtual SDL_Rect GiveRect()=0;
    virtual bool Attack(SDL_Renderer*)=0;
    //virtual void Attack()=0;
    //virtual void GetDestroyed()=0;

};
