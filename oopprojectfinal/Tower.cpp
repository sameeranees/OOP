#include "Tower.h"

Tower::Tower():GameObject()
{

}
Tower::Tower(LTexture* image, float x, float y,int money,int Health):GameObject(image,x,y,money,Health)
{

}
Tower::~Tower()
{
    delete TowerProjectileSound;
    delete SelectTowerSound;
}
