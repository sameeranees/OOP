#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Enemy.h"
#include "Tile.h"
#include "Path.h"
#include "Throne.h"
#include"EnemyProjectile.h"
#include "Soldier.h"

EnemyProjectile::EnemyProjectile()
{

}

EnemyProjectile::EnemyProjectile(LTexture* image, float x, float y)
{

}

void EnemyProjectile::Hit(SDL_Renderer* gRenderer)
{
    spriteSheetTexture=NULL;
}
