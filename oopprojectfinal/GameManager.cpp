#include "GameManager.h"

GameManager::GameManager()//constructor
{

}

GameManager::~GameManager()//distructor
{

}
void GameManager::Save(LinkedList &lst)//calls save in linked list
{
    lst.Save();
}
void GameManager::LoadGame(LinkedList &gameobjects,LTexture* image)//Loads the game from file
{
    //following function loads from save file where it first checks for what type of object is there and then checks the coordinates, health and money and assigns it to gameobject
    // after assigning values and making objects it pushes them into linked list
    ifstream Load("game_save.txt");//opens save file
    while(Load!=NULL)//while Load has not reached empty line
    {
        float x;
        float y;
        int health;
        int money;
        string ObjectType;
        Load>>ObjectType;
        if(ObjectType=="Throne")
        {
            Load.ignore();
            Load>>money;
            Load>>health;
            //cout<<money<<endl;
            //cout<<health<<endl;
            Throne* throne= new Throne(image,15*64,2*64,money,health);
            gameobjects.Push(throne);
            Load.ignore();
        }
        if(ObjectType=="Soldier")
        {
            Load.ignore();
            Load>>x;
            Load>>y;
            Load>>health;
            Enemy* soldiers = new Soldier(image,x,y,money,health);
            gameobjects.Push(soldiers);
            Load.ignore();
        }
        if(ObjectType=="Aircraft")
        {
            Load.ignore();
            Load>>x;
            Load>>y;
            Load>>health;
            Enemy* aircraft = new Aircraft(image,x,y,money,health);
            gameobjects.Push(aircraft);
            Load.ignore();
        }
        if(ObjectType=="Tank")
        {
            Load.ignore();
            Load>>x;
            Load>>y;
            Load>>health;
            Enemy* tank = new Tanks(image,x,y,money,health);
            gameobjects.Push(tank);
            Load.ignore();
        }
        if(ObjectType=="RocketTurret")
        {
            Load.ignore();
            Load>>x;
            Load>>y;
            Load>>money;
            Tower* rocketturret=new RocketTurret(image,x,y,money,0);
            gameobjects.Push(rocketturret);
            Load.ignore();
        }
        if(ObjectType=="Cannon")
        {
            Load.ignore();
            Load>>x;
            Load>>y;
            Load>>money;
            Tower* cannon=new Cannon(image,x,y,money,0);
            gameobjects.Push(cannon);
            Load.ignore();
        }
        if(ObjectType=="ElectricCannon")
        {
            Load.ignore();
            Load>>x;
            Load>>y;
            Load>>money;
            Tower* electriccannon=new ElectricCannon(image,x,y,money,0);
            gameobjects.Push(electriccannon);
            Load.ignore();
        }
    }
}
