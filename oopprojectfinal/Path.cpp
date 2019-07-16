#include "Path.h"
using namespace std;
Path::Path()
{

}
Path::Path(LTexture* image, float x, float y) // overloaded constructor assigns values
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   53;
    spriteClips[ 0 ].y =   246;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
Path::~Path()
{
    spriteSheetTexture = NULL;
}
void Path::Draw(SDL_Renderer* gRenderer) // draws the path wherever there is 1 in tile value
{
    int type=1;
    for (int row=0;row<12;row++)
    {
        for (int col=0;col<16;col++)
        {
            type=ShowTile(row,col);
            switch(type)
            {
            case 1:
                spriteSheetTexture->Render(col*64, row*64, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                break;
            }
        }
    }
}
