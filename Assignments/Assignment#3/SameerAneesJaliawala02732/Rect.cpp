#include"Rect.h"
#include "cstdlib"

Rect::Rect(SDL_Rect* rect)
{
    fillRect= new SDL_Rect;
    fillRect->h = rect->h;
    fillRect->w = rect->w;
    fillRect->x = rect->x;
    fillRect->y = rect->y;
}


/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer)
{
    SDL_RenderFillRect( gRenderer, fillRect);
}
