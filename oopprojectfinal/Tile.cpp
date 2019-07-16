#include "Tile.h"
#include "LTexture.h"
#include "Grass.h"
using namespace std;

int lvl1[12][16]={ // assigns grass and path to tile(1 for path, 0 for grass)
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
Tile::Tile() //constructor loads the tile
{
    LoadTile(lvl1);
}
void Tile::LoadTile(int arr[12][16]) // assigns the tiles
{
    for (int row=0;row<12;row++)
    {
        for (int col=0;col<16;col++)
        {
            tile[row][col]=arr[row][col];
        }
    }
}
Tile::~Tile()
{

}
int Tile::ShowTile(int row, int col) // returns tile values
{
    return tile[row][col];
}
bool Tile::IsGrass(float x, float y) // return if the tile value points to grass
{
    bool isgrass=false;
    int latx=x/64;
    int laty=y/64;
    if ((tile[laty][latx])==0)
    {
        isgrass=true;
    }
    return isgrass;
}
bool Tile::IsPath(float x, float y)// return if the tile value points to path
{
    bool ispath=false;
    int latx=x/64;
    int laty=y/64;
    if ((tile[laty][latx])==1)
    {
        ispath=true;
    }
    return ispath;
}

bool Tile::IsThrone(float x, float y)// return if the tile value points to throne
{
    bool isthrone=false;
    int latx=x/64;
    int laty=y/64;
    if (latx == 15 && laty == 3)
    {
        isthrone = true;
    }
    return isthrone;

}
