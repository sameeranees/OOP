#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"

class HealthBar
{
private:
    float x;
    float y;
    int width;
    int height;
    float health;
    float speedx;
    float speedy;
    SDL_Rect spriteClips[2];
    LTexture* spriteSheetTexture;
public:
    HealthBar();
    HealthBar(LTexture*, float, float, int);
    void Move(float, float);
    void Draw(SDL_Renderer*, int);
    void SetHealth(int);
    ~HealthBar();
};
