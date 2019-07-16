#include "Cannon.h"
#define PI 3.14159265
using namespace std;
Cannon::Cannon():Tower()
{

}
Cannon::Cannon(LTexture* image, float x, float y,int money,int Health):Tower(image,x,y,money,Health)// overloaded constructor that assigns values of variables
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x =   1217;
    spriteClips[ 0 ].y =   642;
    spriteClips[ 0 ].w = 64;
    spriteClips[ 0 ].h = 64;

    this->x = x;
    this->y = y;
    this->speedx=0.0;
    this->speedy=0.0;
    this->timer=clock();
    this->ammended=false;
    this->Money=money;
    istower=true;
    towertype="Cannon";//used for saving and loading
    this->isequal=false;
    cannonball=new CannonBall(spriteSheetTexture,x,y);// makes a new bullet
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    SelectTowerSound = new Sound("towerselect.wav");
    SelectTowerSound->Play();

    TowerProjectileSound = new Sound("towershoot.wav");

}
Cannon::~Cannon()
{
    delete cannonball;
    cannonball = NULL;
    spriteSheetTexture = NULL;
}

void Cannon::Draw(SDL_Renderer* gRenderer)// draws the cannon turret
{
    //takes the tile array value
    int m=int(x/64);
    int n=int(y/64);
    //at each possible coordinates the code has been coded in a way that turret will always spawn at the right location and direction
    if(n==9 && m < 5)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=180.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );

    }
    if(n==9 && m==5)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=135.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==11 && m<7)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=0.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==11 && m==7)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=315.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n>2 && m==5 && n<11)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=90.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==2 && m==5)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=135.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==2 && m>5 && m<13)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=180.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==2 && m==13)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=135.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n>4 && m==7 && n<11)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=270.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==4 && m==7)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=315.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==4 && m>7 && m<13)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=0.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
    if(n==4 && m==13)
    {
        if(this->ammended==false)
        {
            ammended=true;
            this->angle=45.0;
            this->attackx=m*64;
            this->attacky=n*64;
        }
        spriteSheetTexture->Render(m*64,n*64, &spriteClips[0],angle, NULL, SDL_FLIP_NONE, gRenderer );
    }
}

bool Cannon::Update(GameObject* enemy, SDL_Renderer* gRenderer)// calls every type of function and when tower hits enemy it return a true statement to linkedlist
{                                                               // which uses it to delete enemy if enemy health is 0;
    int m=int(this->x/64); // gets tile array value
    int n=int(this->y/64);
    bool istrue=false; // checks if tower attacked enemy
    if(IsThrone()==false && enemy->ISTower()==false) // if it is throne them the function will not work
    {
        if (this->CheckAttack(enemy)==true) //checks if enemy is within tower range
        {

        }
        if(this->Attack(gRenderer)==true) // attacks enemy if within range
        {
            istrue=true; //tower attacked enemy
            enemy->DecreaseHealth(1);// decrease enmy health by 1
            this->timer=clock(); // starts timer for reload
            reload=true; // reload becomes true
        }

        if(reload==true)
        {
            if(Reload(gRenderer)==true) // if tower has reloaded
            {
                reload=false;
                istrue=false;
                this->attackx=m*64;// assigns bullet coordinates again
                this->attacky=n*64;
                this->ammended2=false; // assigns bullet speed again
                this->checked=false;
            }
        }
    }
    return istrue;
}


bool Cannon::CheckAttack(GameObject* object)// the following function checks if enemy is within range of turret and also checks collision
{
    bool istrue=false;
    // assigns tile coordinates to m and k
    int m=int(x/64);
    m=m*64;
    int k=int(y/64);
    k=k*64;

    int w=object->GetX(); // assigns enemy's location to w and n
    int n=object->GetY();

    //calculates the distance of enemy from turret by using equation distance=squareroot((x2-x1)^2 +(y2-y1)^2)
    int distancex = (k -n)*(k-n);
    int distancey = (m - w)*(m-w);
    int calcdistance = int(sqrt(distancex + distancey));
    //checks if enemy is within 120 unit range of tower
    if(calcdistance<=120)
    {
        float result=atan2 ((k-n),(m-w)) * 180 / PI;
        this->angle=result-90;
        //if enemy is within range then the tower will turn to enemy (by using the trignometric function arctan=y/x) and angle will be assigned by using the following method
        if (calcdistance<=95)
        {
            // if enemy range is within 95 units of tower
            if(ammended2==false) // checks for first time ammendment. if it is being ammended for the first time or after reload
            {
                angle2=angle; // the bullet angle becomes tower angle
                this->speedx=0; //initializes bullet speed
                this->speedy=0;
                ammended2=true;
                TowerProjectileSound->Play(); // plays the sound when tower is placed on tile

                if(m>w)
                {
                    speedx=-1;// if tower is ahead of enemy with respect to x
                }
                if(m+1<w)
                {
                    speedx=1;//if tower is behind enemy with respect to x
                }
                if(k<n)
                {
                    speedy=1;//if tower is behind enemy with respect to y
                }
                if(k>n+2)
                {
                    speedy=-1; // if tower is ahead of enemy with respect to y
                }
            }
            istrue=true; // returns that enemy is within tower range
            this->checked=true; // makes sure all ammendments to cannonball has been performed
        }
        int rocketx=0; // initializes cannonballs coordinates
        int rockety=0;
        if(cannonball)
        {
            rocketx=cannonball->thisx(); // assigns cannonball coordinates
            rockety=cannonball->thisy();
        }
        // what we are doing here is that we check that due to a certain glitch if cannonball has missed enemy it still would be able to reduce enemy's health.(its due to a glitch)
        distancex = (k -rockety)*(k-rockety);// calculates distance between cannonball and turret by using equation distance=squareroot((x2-x1)^2 +(y2-y1)^2)
        distancey = (m - rocketx)*(m-rocketx);
        calcdistance = int(sqrt(distancex + distancey));
        if (cannonball && (cannonball->CheckCollison(object) || calcdistance>=200))// if cannonball exists and (cannonball has collided with enemy or the cannonball is outside 200 units of rockets range)
        {
            istrue= false;
            isequal=true;
        }
    }
    return istrue;
}
bool Cannon:: Attack(SDL_Renderer * gRenderer)// following function attacks enemy and delets bullet
{
    //checks if enemy is within range, and all the ammendments to cannonball has been performed, then it attacks the enemy
    if(isequal==false && cannonball!=NULL && checked==true)
    {
        cannonball->Render(gRenderer,attackx,attacky,angle2);
        this->attackx=attackx+ speedx;// the coordinates of cannonball gets updated
        this->attacky=attacky+ speedy;
    }
    if(isequal==true && cannonball==NULL)//makes sure that this function does not get stuck in loop
    {
        isequal=false;
    }
    if (isequal==true && cannonball!=NULL)//deletes cannonball if enemy has been destroyed
    {
        delete cannonball;
        cannonball=NULL;
    }
    return isequal;
}
bool Cannon::Reload(SDL_Renderer * gRenderer)// following function deletes bullet
{
    bool timereached=false; // checks if reload has been achieved
    int t=0;
    if(timer!=0) // makes sure timer is not set to 0
    {
        t=(clock()-timer)/CLOCKS_PER_SEC; //calculates time between now and timer
    }
    if(t==5) // if the time has been 5 seconds then a new cannonball is made
    {
        cannonball=new CannonBall(spriteSheetTexture,x,y);
        timereached=true;// return the reload has been achieved
    }
    return timereached;
}
SDL_Rect Cannon::GiveRect()
{
    SDL_Rect A;// gives empty rectangle
    A.x=0;
    A.w=0;
    A.y=0;
    A.h=0;
    return A;
}
