#pragma once
#include "SDL.h"
#include "Shape.h"
struct Point:public Shape
{
    int x;
    int y;

    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y):Shape(x,y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point& point)
    {
        x = point.x;
        y = point.y;
    }
    void Draw(SDL_Renderer* gRenderer)
    {
        SDL_RenderDrawPoint( gRenderer,x,y);
    }

};
