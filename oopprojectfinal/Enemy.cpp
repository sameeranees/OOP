#include "Enemy.h"
#include"LTexture.h"

#include <iostream>

using namespace std;

Enemy::Enemy():GameObject() //Enemy will inherit from GameObject
{

}

Enemy::Enemy(LTexture* image, float x, float y,int money,int Health):GameObject(image,x,y,money,Health)
{

}
Enemy::~Enemy()
{
    delete healthbar;
}

