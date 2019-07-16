#include "Shape.h"
#include <iostream>
Shape::Shape()
{

}
Shape::~Shape()
{

}
Shape::Shape(int x, int y)
{
    this->x = x;
    this->y = y;
}
Shape::Shape(int x, int y,int z,int m)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->m = m;
}
Shape::Shape(SDL_Rect* rect)
{
    this->rect=rect;
}
void Shape:: Draw(SDL_Renderer*gRenderer)
{

}

void Shape::SetColors(int a, int b, int c, int d)
{
    //set colors of each shape so every undo and redo gives the shape same color as before
    col1 = a;
    col2 = b;
    col3 = c;
    col4 = d;
}

int Shape::getcol1()
{
    return col1;
}

int Shape::getcol2()
{
    return col2;
}

int Shape::getcol3()
{
    return col3;
}

int Shape::getcol4()
{
    return col4;
}
