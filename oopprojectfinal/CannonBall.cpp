#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "CannonBall.h"

CannonBall::CannonBall()
{

}
CannonBall::CannonBall(LTexture* image, float x, float y)//overloaded constructor to assign values
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   1216;
    spriteClips[ 0 ].y =   710;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    spriteClips[ 1 ].x = 1237-spriteClips[0].x;
    spriteClips[ 1 ].y = 722-spriteClips[0].y;
    spriteClips[ 1 ].w = 22;
    spriteClips[ 1 ].h = 32;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
CannonBall::~CannonBall()
{
    spriteSheetTexture = NULL;
}
void CannonBall::Render(SDL_Renderer* gRenderer,float x,float y, float angle)//renders a cannonball
{
    this->x=x;
    this->y=y;
    if(spriteSheetTexture!=NULL)
    {
        spriteSheetTexture->Render(x, y, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
}
int CannonBall::thisx() // return x coordinate
{
    int m=int(x/64);
    m=m*64;
    return m;
}
int CannonBall::thisy() // return y coordinate
{
    int k=int(y/64);
    k=k*64;
    return k;
}
bool CannonBall::CheckCollison(GameObject* object) // checks if enemy has collided with bullet
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    //We are comparing the two rectangles which encloses the bullet and enemy, if either of these rectangle cross each other then check collision returns true
    SDL_Rect A= object->GiveRect();

    leftA = object->GetX();
    rightA = object->GetX()+A.w;
    topA = object->GetY();
    bottomA = object->GetY()+A.h;

    leftB = this->x;
    rightB = this->x+spriteClips[ 1 ].x;
    topB = this->y;
    bottomB = this->y+spriteClips[ 1 ].y;

    if ( (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)==false)// checks if the rectangles have collided
    {
        return true;
    }
    return false;
}
