#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tanks.h"
#include "Tile.h"
#include "EnemyProjectile.h"

using namespace std;

Tanks::Tanks():Enemy()
{
//    tankscount = 0;
}

Tanks::Tanks(LTexture* image, float x, float y,int money,int Health):Enemy(image, x, y,money,Health)
{
    /*
    loads spriteclips, set health, set money, set speed, set projectile, construct a healthbar
    */

    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   16*64;
    spriteClips[ 0 ].y =   832-128;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    spriteClips[ 1 ].x =   1027;
    spriteClips[ 1 ].y =   717;
    spriteClips[ 1 ].w = 59;
    spriteClips[ 1 ].h = 40;

    this->tanksprojectile=NULL;

    this->x = x;
    this->y = y;
    //this->angle=0.0;

    this->health=Health;
    enemytype="Tank";
    isenemy=true;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    this->speedx = 0;
    this->speedy = 0;

    healthbar = new HealthBar(image, this->x, this->y, 1);
}

void Tanks::Draw(SDL_Renderer* gRenderer)
{
    /*
    add speed to current co ordinates
    draw tank, normal if vertical, at 270 degree if horizontal
    set health and draw health bar
    */

    this->x = this->x + speedx;
    this->y = this->y + speedy;

    if (speedx > 0 || (speedx == 0 && speedy == 0))
    {
        spriteSheetTexture->Render(this->x, this->y, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if (speedy < 0)
    {
        spriteSheetTexture->Render(this->x, this->y, &spriteClips[0], 270.0, NULL, SDL_FLIP_NONE, gRenderer );
    }

    healthbar->SetHealth(health*33);
    healthbar->Draw(gRenderer,1);
}

void Tanks::Move()
{
        //change speed of tanks and provide co ordinates to health bar.. similar to soldier

        if (path.IsThrone(this->x+64, this->y+64) == true)
        {
            speedx = 0;
            speedy = 0;
        }
        else
        {
            if (path.IsPath(this->x+64, this->y+64) == true)
            {
                speedx = 0.5;
                speedy = 0;
            }
            if (path.IsPath(this->x+64, this->y+64) == false)
            {
                speedx = 0;
                speedy = -0.5;
            }
        }

        healthbar->Move(x,y);
}

SDL_Rect Tanks::GiveRect()
{
    //give sprite clip of object

    spriteClips[ 1 ].x = 1027-spriteClips[0].x;
    spriteClips[ 1 ].y = 717-spriteClips[0].y;
    return this->spriteClips[1];
}

bool Tanks::Attack(SDL_Renderer* gRenderer)
{

    bool istrue=false;

    if (path.IsThrone(this->x+64, this->y+64) == true && tanksprojectile==NULL)
    //once tank reaches throne and no projectile has been made, create one
    {
        tanksprojectile = new TanksProjectile(spriteSheetTexture, this->x, this->y);
    }

    if (tanksprojectile != NULL)
    //if projectile has been made, hit and move it forward
    {
        if(tanksprojectile->Hit(gRenderer)==true)
        {
            istrue=true;
        }
        tanksprojectile->Move();
    }

    if (tanksprojectile!=NULL && tanksprojectile->returnProjectileCollide()==true)
    //once collision is complete with explosion, delete
    {
        delete tanksprojectile;
        tanksprojectile = NULL;
    }

    return istrue;
}


Tanks::~Tanks()
{
    delete tanksprojectile;
    spriteSheetTexture = NULL;
    tanksprojectile = NULL;
}

bool Tanks::Update(GameObject* object, SDL_Renderer* gRenderer)
{
     /*
    Move the tank
    If attack happened, decrease throne health by 2
    */

    Move();
    if(object->ISEnemy()==false)
    {
        if(Attack(gRenderer)==true)
        {
            object->DecreaseHealth(2);
        }
    }
    return false;
}
