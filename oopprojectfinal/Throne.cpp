#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tile.h"
#include "Path.h"
#include "Throne.h"
using namespace std;

Throne::Throne():GameObject()
{

}


Throne::Throne(LTexture* image, float x, float y,int money,int Health):GameObject(image,x,y,money,Health)
{
    spriteSheetTexture = image;

    isThrone=true;

    spriteClips[ 0 ].x =   1216;
    spriteClips[ 0 ].y =   449;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    for (int i=1;i<11;i++)
    {
        spriteClips[ i ].x =   17+(30*(i-1)+(34*(i-1)));
        spriteClips[ i ].y =   783;
        spriteClips[ i ].w = 30;
        spriteClips[ i ].h = 35;
    }
    spriteClips[ 12 ].x =   717;
    spriteClips[ 12 ].y =   780;
    spriteClips[ 12 ].w = 39;
    spriteClips[ 12 ].h = 45;

    this->health=Health;
    this->Money=money;
    this->x = x;
    this->y = y;
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    healthbar = new HealthBar(image, 64,64, 2);

}
int Throne::GiveMoney()
{
    return this->Money;
}

void Throne::UpdateMoney(int x)
{
    Money=Money+x;
}
void Throne::Draw(SDL_Renderer* gRenderer)
{
    for (int i = 0; i < 3; i++)
    {
        spriteSheetTexture->Render(this->x, this->y + (i*64), &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    ShowMoney(gRenderer);
    healthbar->SetHealth(health);
    healthbar->Draw(gRenderer,2);
}

void Throne::ShowMoney(SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render(770, 20, &spriteClips[12], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if (Money<1000 && Money>99)
    {
        char buffer [3];
        sprintf(buffer,"%d",Money);
        for (int i=0;i<3;i++)
        {
            int buff;
            buff=int(buffer[i])-'0';
            spriteSheetTexture->Render(810 + (i*30), 20, &spriteClips[buff+1], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        }
    }
    else if(Money>=1000 && Money<10000)
    {
        char buffer [4];
        sprintf(buffer,"%d",Money);
        for (int i=0;i<4;i++)
        {
            int buff;
            buff=int(buffer[i])-'0';
            spriteSheetTexture->Render(810 + (i*30), 20, &spriteClips[buff+1], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        }
    }
    else if (Money>=10000)
    {
        char buffer [5];
        sprintf(buffer,"%d",Money);
        for (int i=0;i<5;i++)
        {
            int buff;
            buff=int(buffer[i])-'0';
            spriteSheetTexture->Render(810 + (i*30), 20, &spriteClips[buff+1], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        }
    }
    else if (Money==0)
    {
        spriteSheetTexture->Render(810, 20, &spriteClips[1], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
}
SDL_Rect Throne::GiveRect()
{
    SDL_Rect A;
    A.h=0;
    A.x=0;
    A.y=0;
    A.w=0;
    return A;
}

bool Throne::Update(GameObject* object, SDL_Renderer* gRenderer)
{
    //cout<<Money<<endl;
    if (object->GiveMoney()<0 && (-1*object->GiveMoney())<=this->Money)
    {
        UpdateMoney(object->GiveMoney());
        return true;
    }
    else if (object->GiveMoney()>0)
    {
        UpdateMoney(object->GiveMoney());
        return true;
    }

    //healthbar->Decrease(health);
    //cout<<health<<endl;
    return false;
}

Throne::~Throne()
{
    //delete spriteSheetTexture;
    delete healthbar;
    spriteSheetTexture = NULL;
    healthbar = NULL;
}
