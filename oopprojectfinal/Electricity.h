#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "GameObject.h"
class Electricity
{
private:
    float x;
    float y;
    int width;
    int height;
    SDL_Rect spriteClips[2];
    LTexture* spriteSheetTexture;
public:
    Electricity(LTexture* image, float x, float y);
    Electricity();
    ~Electricity();
    void Render(SDL_Renderer * gRenderer,float x, float y,float angle);
    int thisx();
    int thisy();
    bool CheckCollison(GameObject*);
};
