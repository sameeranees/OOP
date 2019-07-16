#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Aircraft.h"
#include "Tile.h"
#include "EnemyProjectile.h"
#include "AircraftProjectile.h"

using namespace std;

Aircraft::Aircraft():Enemy()
{

}

Aircraft::Aircraft(LTexture* image, float x, float y,int money,int Health):Enemy(image, x, y,money,Health)
{

    /*
    loads spriteclips, set health, set money, set speed, set projectile, construct a healthbar
    */

    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   18*64;
    spriteClips[ 0 ].y =   832-128;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    spriteClips[ 1 ].x =   1159;
    spriteClips[ 1 ].y =   705;
    spriteClips[ 1 ].w = 49;
    spriteClips[ 1 ].h = 63;

    this->health=Health;

    enemytype="Aircraft";
    isenemy=true;

    this->x = x;
    this->y = y;

    this->aircraftprojectile=NULL;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    this->speedx = 1;
    this->speedy = 0;

    healthbar = new HealthBar(image, this->x+10, this->y-10, 1);
}

void Aircraft::Draw(SDL_Renderer* gRenderer)
{
    /*
    set health, so that new health can be drawn
    add speed to current x, y positions and render
    */

    healthbar->SetHealth(health*50);
    healthbar->Draw(gRenderer,1);

    this->x = this->x + speedx;
    spriteSheetTexture->Render(this->x, this->y, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Aircraft::Move()
{
    /*
    move healthbar, by giving it new x, y positions
    */

    healthbar->Move(x,y);
}

SDL_Rect Aircraft::GiveRect()
{
    /*
    gives the sprite clip of the object
    */

    spriteClips[ 1 ].x = 1159-spriteClips[0].x;
    spriteClips[ 1 ].y = 705-spriteClips[0].y;
    return this->spriteClips[1];
}

bool Aircraft::Attack(SDL_Renderer* gRenderer)
{
    bool istrue=false;

    if (path.IsThrone(this->x+64, this->y) == true && aircraftprojectile==NULL)
    //once aircraft has reached throne, create a projectile
    {
        aircraftprojectile = new AircraftProjectile(spriteSheetTexture, this->x, this->y);
    }
    if (aircraftprojectile != NULL)
    //if projectile has been created, hit (draw) and move it
    {
        if(aircraftprojectile->Hit(gRenderer)==true)
        {
            istrue=true;
        }
        aircraftprojectile->Move();
    }
    if(aircraftprojectile!=NULL && aircraftprojectile->returnProjectileCollide()==true)
    //once projectile has collided, delete it
    {
        delete aircraftprojectile;
        aircraftprojectile=NULL;
    }

    //istrue determines whether attack was done or not.. if attack happens, istrue becomes true
    return istrue;
}


Aircraft::~Aircraft()
{
    /*
    delete aircraft
    */

    spriteSheetTexture=NULL;
    delete aircraftprojectile;
    delete healthbar;
}

bool Aircraft::Update(GameObject* object, SDL_Renderer* gRenderer)
{
    /*
    Move the aircraft
    If attack happened, decrease throne health by 3
    If x of aircraft exceeds screen width, delete it
    */
    Move();

    if(object->ISEnemy()==false)
    {
        if(Attack(gRenderer)==true)
        {
            object->DecreaseHealth(3);
        }
    }

    if(GetX()>1024)
    {
        health=0;
    }

    return false;
}
