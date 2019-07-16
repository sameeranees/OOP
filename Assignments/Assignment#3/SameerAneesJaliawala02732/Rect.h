#pragma once
#include"SDL.h"
#include "Shape.h"

class Rect:public Shape
{
private:
    SDL_Rect* fillRect;
public:
    Rect(SDL_Rect*);
    void Draw(SDL_Renderer*);

};
