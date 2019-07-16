#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "RocketBall.h"

RocketBall::RocketBall()
{

}
RocketBall::RocketBall(LTexture* image, float x, float y)//overloaded constructor to assign values
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   1345;//1366
    spriteClips[ 0 ].y =   647;//656
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    spriteClips[ 1 ].x = 1366-spriteClips[0].x;//1366
    spriteClips[ 1 ].y = 656-spriteClips[0].y;
    spriteClips[ 1 ].w = 19;
    spriteClips[ 1 ].h = 32;
    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
RocketBall::~RocketBall()
{
    //delete spriteSheetTexture;
    spriteSheetTexture = NULL;
}
void RocketBall::Render(SDL_Renderer* gRenderer,float x,float y, float angle)// renders rocketball
{
    this->x=x;
    this->y=y;
    if(spriteSheetTexture!=NULL)
    {
        spriteSheetTexture->Render(x, y, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
}
int RocketBall::thisx()// return x coordinate
{
    int m=int(x/64);
    m=m*64;
    return m;
}
int RocketBall::thisy() //return y coordinate
{
    int k=int(y/64);
    k=k*64;
    return k;
}
bool RocketBall::CheckCollison(GameObject* object)// checks if enemy has collided with bullet
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    SDL_Rect A= object->GiveRect();
    //We are comparing the two rectangles which encloses the bullet and enemy, if either of these rectangle cross each other then check collision returns true
    leftA = object->GetX();
    rightA = object->GetX()+A.w;
    topA = object->GetY();
    bottomA = object->GetY()+A.h;

    leftB = this->x;
    rightB = this->x+spriteClips[ 1 ].x;
    topB = this->y;
    bottomB = this->y+spriteClips[ 1 ].y;

    if ( (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)==false)// checks if rectangles have crossed each other
    {
        return true;
    }
    return false;
}
