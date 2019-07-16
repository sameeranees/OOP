#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tile.h"
#include "Path.h"
#include "Throne.h"
#include "AircraftProjectile.h"

using namespace std;

AircraftProjectile::AircraftProjectile()
{

}

AircraftProjectile::AircraftProjectile(LTexture* image, float x, float y)
{
    /*
    load sprite clips
    construct explosion, projectile sound
    */

    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   1472-64;
    spriteClips[ 0 ].y =   832-(64*3);
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    explosion = new Explosion(this->spriteSheetTexture,15*64,3*64);

    collide = false;
    ProjectileCollide = false;

    this->x = x;
    this->y = y;

    AircraftProjectileSound = new Sound("enemyshoot.wav");
    AircraftProjectileSound->Play();

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}

bool AircraftProjectile::Hit(SDL_Renderer* gRenderer)
{
    bool istrue = false;

    if (collide == true)
    //if collision has happened and explosion has been created and hit, delete it
    {
        if(explosion!=NULL && explosion->Hit(gRenderer)==true)
        {
            delete explosion;
            explosion=NULL;
            istrue = true;
        }
    }

    if (collide == false)
    //if collision has not happened, render the projectile
    {
        spriteSheetTexture->Render(this->x, this->y, &spriteClips[0], 90, NULL, SDL_FLIP_NONE, gRenderer );
    }

    //istrue is a bool that is true when explosion has completed

    return istrue;
}

void AircraftProjectile::Move()
{
    //if projectile has not reached throne, keep moving forward

    if (this->x != 15*64-10.0 && this->y != 2*64)
    {
        this->x = this->x+0.5;
    }
    else
    {
        collide = true;
    }
}

bool AircraftProjectile::returnCollide()
{
    return collide;
}

bool AircraftProjectile::returnProjectileCollide()
{
    return ProjectileCollide;
}

AircraftProjectile::~AircraftProjectile()
{
    delete explosion;
    delete AircraftProjectileSound;
    spriteSheetTexture = NULL;
}
