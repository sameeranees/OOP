#pragma once
#include "Node.h"
#include "GameObject.h"
#include"LTexture.h"
#include "Tower.h"
#include "RocketTurret.h"
#include "Cannon.h"
#include "ElectricCannon.h"
#include "Enemy.h"
#include "Soldier.h"
#include "Throne.h"
#include "Explosion.h"
#include "EnemyProjectile.h"
#include "Tanks.h"
#include "LinkedList.h"
#include "Aircraft.h"

class LinkedList
{
private:
    Node* head;
    Node* tail;
    bool GameOver; //true is game is over
public:
    LinkedList();
    ~LinkedList();
    void Push(GameObject*);
    void Delete(Node*);
    int Size();
    void Save();
    void Clear();
    bool isGameOver();
    void Show(SDL_Renderer * gRenderer, long int);
    bool CheckMoney(int,SDL_Renderer *);
};
