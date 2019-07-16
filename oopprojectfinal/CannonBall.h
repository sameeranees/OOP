#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"GameObject.h"
class CannonBall
{
private:
    float x;
    float y;
    int width;
    int height;
    SDL_Rect spriteClips[2];
    LTexture* spriteSheetTexture;
public:
    CannonBall(LTexture* image, float x, float y);
    CannonBall();
    ~CannonBall();
    void Render(SDL_Renderer * gRenderer,float x, float y,float angle);
    int thisx();
    int thisy();
    bool CheckCollison(GameObject*);
};
