#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tile.h"
#include "Path.h"
#include "Throne.h"
#include "EnemyProjectile.h"
#include "TanksProjectile.h"

using namespace std;

TanksProjectile::TanksProjectile()
{

}

TanksProjectile::TanksProjectile(LTexture* image, float x, float y)
{
     /*
    load sprite clips
    construct explosion, projectile sound
    */

    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   1472-(64*2);
    spriteClips[ 0 ].y =   832-64;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    collide = false;

    ProjectileCollide = false;

    this->x = x;
    this->y = y;

    explosion = new Explosion(image, 15*64,3*64);
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    TanksProjectileSound = new Sound("enemyshoot.wav");
    TanksProjectileSound->Play();
}

bool TanksProjectile::Hit(SDL_Renderer* gRenderer)
{
    bool istrue = false;
    if (collide == true)
    //if collision has happened, and explosion complete, delete
    {
        if(explosion!=NULL && explosion->Hit(gRenderer)==true)
        {
            delete explosion;
            explosion=NULL;
            istrue = true;
        }


    }

    if (collide == false)
    //if collision has not happened, render
    {
        spriteSheetTexture->Render(this->x, this->y, &spriteClips[0], 90, NULL, SDL_FLIP_NONE, gRenderer );
    }

    return istrue;
}

void TanksProjectile::Move()
{
    //till projectile does not hit throne, keep moving
    if (this->x != 15*64-10.0 && this->y != 2*64)
    {
        this->x = this->x+0.5;
    }
    else
    {
        collide = true;
    }
}

bool TanksProjectile::returnCollide()
{
    return collide;
}

bool TanksProjectile::returnProjectileCollide()
{
    return ProjectileCollide;
}

TanksProjectile::~TanksProjectile()
{
    delete explosion;
    delete TanksProjectileSound;
    explosion = NULL;
    TanksProjectileSound = NULL;
    spriteSheetTexture = NULL;
}
