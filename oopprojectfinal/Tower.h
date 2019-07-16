#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Tile.h"
#include "GameObject.h"
#include "Sound.h"
#include <ctime>

class Tower:public GameObject  //Tower is an abstract class inheriting from GameObject
{
protected:
    float attackx; // x cordinate of bullet
    clock_t timer; // timer used in reload
    float attacky; // y cordinate of bullet
    float speedx; // speed of bullet
    float speedy;
    bool reload=false; // tells if tower has reloaded
    bool ammended; // used for firsttime ammendments and whenever necessary
    bool ammended2=false;
    bool isequal; // if the bullet has collided
    bool checked=false; // a first time check
    float angle;// angle of tower
    float angle2; // angle of bullet
    SDL_Rect spriteClips[1];
    Sound* SelectTowerSound;// sound when selcting tower
    Sound* TowerProjectileSound; // sound when shooting bullet

public:
    Tower(LTexture* image, float x, float y,int,int); //overloaded constructor
    Tower(); // constructor
    virtual ~Tower(); // virtual distructor
    virtual bool Update(GameObject*, SDL_Renderer* gRenderer)=0; //Update Function calls every type of function in tower and return a bool type to linkedlist
    virtual void Draw(SDL_Renderer* gRenderer)=0; // Draws the appropriate tower
    virtual bool Attack(SDL_Renderer* gRenderer)=0; // Attacks the bullet
    virtual bool CheckAttack(GameObject*)=0; //Checks the distance and attack situation
    virtual bool Reload(SDL_Renderer * gRenderer)=0; // Reloads the tower
    virtual SDL_Rect GiveRect() = 0; // returns the spriteclip for collision detection(primarily).
};
