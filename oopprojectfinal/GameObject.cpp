#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "LTexture.h"
#include <iostream>

using namespace std;

GameObject::GameObject()
{

}

GameObject::GameObject(LTexture* image, float x, float y,int money,int Health)
{

}

GameObject::~GameObject()
{
    delete spriteSheetTexture;
}

void GameObject::SetMoney(int val)
{
    Money = val;
}

int GameObject::GetHealth()
{
    return health;
}

void GameObject::DecreaseHealth(int h)
{
    health = health - h;
}

bool GameObject::ISTower()
{
    return istower;
}

string GameObject::TowerType()
{
    return towertype;
}

void GameObject::IncreaseMoney(int money)
{
    Money=Money+money;
}

string GameObject::EnemyType()
{
    return enemytype;
}

bool GameObject::ISEnemy()
{
    return isenemy;
}

bool GameObject::IsThrone()
{
    return isThrone;
}

int GameObject::GiveMoney()
{
    return Money;
}

void GameObject::SetHealth(int h)
{
    health=h;
}
