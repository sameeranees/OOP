#include<iostream>
#include "SDL.h"
#pragma once
using namespace std;

class Shape
{
private:
    int x;
    int y;
    int z;
    int m;
    int col1;
    int col2;
    int col3;
    int col4;
    SDL_Rect*rect;
public:
    void SetColors(int, int, int, int);
    int getcol1();
    int getcol2();
    int getcol3();
    int getcol4();

    Shape();
    Shape(int, int);
    virtual ~Shape();
    Shape(int,int,int,int);
    Shape(SDL_Rect*);
    virtual void Draw(SDL_Renderer*gRenderer);


};

#include "Point.h"
#include "Line.h"
#include "Rect.h"
