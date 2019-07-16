#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Soldier.h"
#include "Tile.h"

using namespace std;

Soldier::Soldier():Enemy()
{

}

Soldier::~Soldier()
{
    delete soldierprojectile;
    soldierprojectile = NULL;
}

Soldier::Soldier(LTexture* image, float x, float y,int money,int Health):Enemy(image, x, y,money,Health)
{
    /*
    loads spriteclips, set health, set money, set speed, set projectile, construct a healthbar
    */

    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   1025;
    spriteClips[ 0 ].y =   641;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    spriteClips[ 1 ].x =   1045;
    spriteClips[ 1 ].y =   658;
    spriteClips[ 1 ].w = 20;
    spriteClips[ 1 ].h = 25;
    this->x = x;
    this->y = y;

    this->health=Health;
    enemytype="Soldier";
    isenemy=true;
    this->soldierprojectile=NULL;
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    this->speedx = 0;
    this->speedy = 0;

    healthbar = new HealthBar(image, this->x+20, this->y+10, 0);
}

bool Soldier::Update(GameObject* object, SDL_Renderer* gRenderer)
{
    /*
    Move the aircraft
    If attack happened, decrease throne health by 1
    */

    Move();
    if(object->ISEnemy()==false)
    {
        if(Attack(gRenderer)==true)
        {
            object->DecreaseHealth(1);
        }
    }
    return false;

}
void Soldier::Draw(SDL_Renderer* gRenderer)
{
    /*
    add speed to co-ordinates
    draw normal if moving horizontal, at 270 degree when moving vertical
    set health and draw the health bar
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

    healthbar->SetHealth(health*100);
    healthbar->Draw(gRenderer,1);
}

void Soldier::Move()
{
    /*
    set speed of soldier, if throne in front, speeds are 0
    if path in front, move in x direction
    if no path, move in y direction
    move health bar
    */

    if (path.IsThrone(this->x+64, this->y+64) == true)
    {
        speedx = 0;
        speedy = 0;
    }
    else
    {
        if (path.IsPath(this->x+64, this->y+64) == true)
        {
            speedx = 1;
            speedy = 0;
        }
        if (path.IsPath(this->x+64, this->y+64) == false)
        {
            speedx = 0;
            speedy = -1;
        }
    }
    healthbar->Move(x,y);
}

SDL_Rect Soldier::GiveRect()
{
    //give sprite clip of object

    spriteClips[ 1 ].x = 1045-spriteClips[0].x;
    spriteClips[ 1 ].y = 658-spriteClips[0].y;
    return this->spriteClips[1];
}
bool Soldier::Attack(SDL_Renderer* gRenderer)
{
    bool istrue=false;

    if (path.IsThrone(this->x+64, this->y+64) == true && soldierprojectile == NULL)
    //once soldier reaches throne and no projectile has been made, create one
    {
        soldierprojectile = new SoldierProjectile(spriteSheetTexture, this->x, this->y);
    }

    if (soldierprojectile != NULL)
    //if projectile has been made, hit and move it forward
    {
        if(soldierprojectile->Hit(gRenderer)==true)
        {
            istrue=true;
        }
        soldierprojectile->Move();
    }

    if (soldierprojectile!=NULL && soldierprojectile->returnProjectileCollide()==true)
    //once collision is complete with explosion, delete
    {
        delete soldierprojectile;
        soldierprojectile=NULL;
    }

    return istrue;
}

