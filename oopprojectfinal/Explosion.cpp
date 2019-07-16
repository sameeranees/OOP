#include"Explosion.h"
using namespace std;
Explosion::Explosion()
{

}
Explosion::Explosion(LTexture* image, float x, float y)
{
    /*
    load sprite clips
    make sound for explosion
    */

    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   1472-(64*3);
    spriteClips[ 0 ].y =   832-128;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    int k = 0;
    int l = 0;
    for (int i = 1; i < 22; i++)
    {
        spriteClips[ i ].x =   1472 + k*64;
        if (i%7 == 0)
        {
            l++;
            k=0;
        }
        spriteClips[ i ].y =  l*64;
        spriteClips[ i ].w = 64;
        spriteClips[ i ].h = 64;
        k++;
    }

    this->x = x;
    this->y = y;

    ExplosionSound = new Sound("explosionsound.wav");

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
Explosion::~Explosion()
{
    delete ExplosionSound;
    ExplosionSound = NULL;
    spriteSheetTexture = NULL;

}
bool Explosion::Hit(SDL_Renderer* gRenderer)
{
    /*
    render explosion
    i is a variable used, so all sprites of explosion can be rendered
    play explosion sound when very first explosion sprite renders
    */

    bool istrue=false;

    if(i==1)
        ExplosionSound->Play();

    if(i!=66)
    {
        spriteSheetTexture->Render(this->x, this->y, &spriteClips[int(i/3)], 0, NULL, SDL_FLIP_NONE, gRenderer );
        i++;
    }

    else
    {
        istrue=true;
    }

    //istrue determines if all explosion sprites have been rendered

    return istrue;
}
