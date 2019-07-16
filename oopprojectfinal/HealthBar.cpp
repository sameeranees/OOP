#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "HealthBar.h"

HealthBar::HealthBar()
{

}

HealthBar::HealthBar(LTexture* image, float x, float y, int val)
{
    /*
    load sprite clips
    set health to 100
    depending on the val, the size of the healthbar is different, depending on the object it is for
    */

    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   842;
    spriteClips[ 0 ].w = 284;
    spriteClips[ 0 ].h = 28;


    spriteClips[ 1 ].x =   284;
    spriteClips[ 1 ].y =   842;
    spriteClips[ 1 ].w = 284;
    spriteClips[ 1 ].h = 28;

    if (val == 0)
    {
        spriteClips[ 0 ].w = 284/15;
        spriteClips[ 0 ].h = 28/7;

        spriteClips[ 1 ].w = 284/15;
        spriteClips[ 1 ].h = 28/7;
    }

    if (val == 1)
    {
        spriteClips[ 0 ].w = 284/10;
        spriteClips[ 0 ].h = 28/7;

        spriteClips[ 1 ].w = 284/10;
        spriteClips[ 1 ].h = 28/7;
    }

    this->x = x;
    this->y = y;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    health = 100;
}

void HealthBar::Draw(SDL_Renderer* gRenderer, int val)
{
    /*
    first draw white healthbar, above it draw blue one so it shows contrast
    for blue healthbar, change width depending on what the health is
    so when health decreases, the healthbar decreases
    */

    spriteSheetTexture->Render(this->x, this->y, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    if (val == 0)
    {
        spriteClips[1].w = int((284/15) * (health/100));
    }

    if (val == 1)
    {
        spriteClips[1].w = int((284/10) * (health/100));
    }

    if (val == 2)
    {
        spriteClips[1].w = int((284) * (health/100));
    }

    spriteSheetTexture->Render(this->x, this->y, &spriteClips[1], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void HealthBar::SetHealth(int bar)
{
    health = bar;
}

void HealthBar::Move(float x, float y)
{
    /*
    when used with enemy, the healthbar must move along with them
    the function takes the enemy's co-ordinates and replicates it for healthbar
    */

    this->x = x;
    this->y = y;
}

HealthBar::~HealthBar()
{
    spriteSheetTexture = NULL;
}
