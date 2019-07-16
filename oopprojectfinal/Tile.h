#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"

class Tile
{
public:
    Tile();
    virtual ~Tile();
    void LoadTile(int [12][16]);
    virtual void Draw(SDL_Renderer* gRenderer)=0;
    int ShowTile(int, int);
    bool IsGrass(float,float);
    bool IsPath(float,float);
    bool IsThrone(float, float);
private:
    int tile[12][16];
};
