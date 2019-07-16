#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "HealthBar.h"
#pragma once

using namespace std;

class GameObject
{
protected:
    float x;
    float y;
    int width;
    int height;
    int health;
    HealthBar* healthbar;
    int Money=0;
    bool isThrone=false;
    bool isenemy=false;
    bool istower=false;
    string towertype;
    string enemytype;
    LTexture* spriteSheetTexture;
public:
    GameObject();
    GameObject(LTexture*,float,float,int,int);
    float GetX(){return x;};
    float GetY(){return y;};
    void SetX(float x){this->x = x;};
    void SetY(float y){this->y = y;};
    void DecreaseHealth(int );
    int GetHealth();
    void SetHealth(int);
    bool IsThrone();
    void IncreaseMoney(int);
    bool ISEnemy();
    string EnemyType();
    bool ISTower();
    string TowerType();

    virtual ~GameObject();
    virtual bool Update(GameObject*, SDL_Renderer* gRenderer) = 0;
    virtual void Draw(SDL_Renderer*) = 0;
    void SetMoney(int);
    int GiveMoney();
    virtual SDL_Rect GiveRect() = 0;
};

