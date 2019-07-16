#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Tile.h"

class Grass:public Tile
{
private:
    float x;
    float y;
    int width;
    int height;
    SDL_Rect spriteClips[1];
    LTexture* spriteSheetTexture;
public:
    Grass(LTexture* image, float x, float y);
    Grass();
    ~Grass();
    void Draw(SDL_Renderer* gRenderer);
};
