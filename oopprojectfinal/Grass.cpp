#include "Grass.h"

Grass::Grass()
{

}
Grass::Grass(LTexture* image, float x, float y)//overloaded constructor assigns values
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   56;
    spriteClips[ 0 ].y =   56;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
Grass::~Grass()
{
    spriteSheetTexture = NULL;
}

void Grass::Draw(SDL_Renderer* gRenderer)// draws the grass wherever there is 0 in tile value
{
    int type=0;
    for (int row=0;row<12;row++)
    {
        for (int col=0;col<16;col++)
        {
            type=ShowTile(row,col);
            switch(type)
            {
            case 0:
                spriteSheetTexture->Render(col*64, row*64, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                break;
            }
        }
    }
}
