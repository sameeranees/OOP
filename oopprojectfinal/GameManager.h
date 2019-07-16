#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Grass.h"
#include "Tile.h"
#include "Path.h"
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
#include <string>
#include <fstream>
class GameManager
{
    public:
        GameManager();
        ~GameManager();

        void Save(LinkedList&);
        void LoadGame(LinkedList&,LTexture*);

    protected:

    private:
        int Money;
        int Health;
        int x;
        int y;
};
