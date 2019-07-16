#include"Line.h"

Line::Line()
{
    this->x=0;
    this->y=0;
    this->z=0;
    this->m=0;
}

Line::Line(int x, int y, int z, int m):Shape(x,y,z,m)
{
    this->x=x;
    this->y=y;
    this->z=z;
    this->m=m;
}


/** Draws the Lineangle **/
void Line::Draw(SDL_Renderer* gRenderer)
{
    SDL_RenderDrawLine( gRenderer,x,y,z,m );
}
