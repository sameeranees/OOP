#pragma once
#include"SDL.h"
#include "Shape.h"
#include "Point.h"
class Line:public Shape
{
private:
    int x;
    int y;
    int z;
    int m;
public:
    Line();
    Line(int, int, int, int);
    void Draw(SDL_Renderer*);
};
