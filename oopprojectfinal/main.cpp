#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
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
#include "InstructionText.h"
#include "Tanks.h"
#include "LinkedList.h"
#include "GameManager.h"
#include "Aircraft.h"
#include "GameOverScreen.h"
#include <string>
#include <fstream>

using namespace std;
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Surface* gScreenSurface = NULL;

Mix_Music *gMusic = NULL;

LTexture gSpriteSheetTexture;

bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

			bool quit = false;                      //Main loop flag

			SDL_Event e;                            //Event handler

			long int frame = 0;

			//pointers to grass and path
			Tile *grass;
			Tile *path;

			//pointers to all types of enemies
			Enemy* soldiers;
			Enemy* tanks;
			Enemy* aircrafts;

			//linked list which will store game objects
			LinkedList gameobjects;

			//create pointer to throne, call it's constructor and push into linked list, since it stays on screen beforehand
			Throne* throne;
			throne = new Throne(&gSpriteSheetTexture,15*64,2*64,1500,100);
            gameobjects.Push(throne);

			//the screen that shows when game is over
			GameOverScreen gameoverscreen;

			//load instruction text
			InstructionText instructiontext;
			instructiontext.Load(gRenderer);

			//bools for save, load feature
            bool save=false;
            bool load=false;
            bool newgame=false;

            //bools for keypress functionality
			bool defalt=true;
			bool ppress=false;
			bool lpress=false;

			//making game manager, for save/load
			GameManager manager;

			//make towers, so user can create them
			Tower * rocketturret=NULL;
			Tower * cannon=NULL;
			Tower * electriccannon=NULL;

			bool mouseclicked=false;

            grass=new Grass(&gSpriteSheetTexture,0,0);
            path =new Path(&gSpriteSheetTexture,0,0);

            srand (time(NULL));

            //start playing background music, in an infinite loop, until game is over
            Mix_PlayMusic(gMusic, -1);

			while( !quit )                          //While application is running
			{

			    //frames are added so that enemies enter the game, at certain frequencies in time
                if(frame%800==599 && newgame==true)
                {
                    //create an aircraft and push it into linked list
                    aircrafts = new Aircraft(&gSpriteSheetTexture,0,64*3,0,2);
                    gameobjects.Push(aircrafts);
                }

                if(frame%400 == 0 && newgame==true)
                {
                    soldiers = new Soldier(&gSpriteSheetTexture,0,64*10,0,1);
                    gameobjects.Push(soldiers);
                }

                if(frame%1200 == 600 && newgame==true)
                {
                    tanks = new Tanks(&gSpriteSheetTexture,0,64*10,0,3);
                    gameobjects.Push(tanks);
                }

			    while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
				{

					//User requests quit

					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					if(e.type==SDL_KEYDOWN) //if a key is pressed
                    {
                        switch (e.key.keysym.sym)
                        {
                            //match key press for each case below
                            case SDLK_e: //if p is pressed set ppress to true
                                {
                                    ppress=true;
                                    defalt=false;
                                    lpress=false;
                                    break;
                                }
                            case SDLK_r: //if l is pressed set lpress to true
                                {
                                    lpress=true;
                                    defalt=false;
                                    ppress=false;
                                    break;
                                }
                            case SDLK_c: //if r is pressed set rpressed to true
                                {
                                    defalt=true;
                                    lpress=false;
                                    ppress=false;
                                    break;
                                }
                            case SDLK_s: //if s is pressed enable savegame feature
                                {
                                    save=true;
                                    break;
                                }
                            case SDLK_l: //if l is pressed enable load feature
                                {
                                    load=true;
                                    newgame=false;
                                    break;
                                }
                            case SDLK_n: //if n is pressed enable newgame feature
                                {
                                    newgame=true;
                                    load=false;
                                    break;
                                }
                        }
                    }

                    /*
                    once user clicks, if they click on grass, generate a tower
                    default is cannon, and if another tower is enable click that
                    */

					if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        int x, y;
                        SDL_GetMouseState( &x, &y );
                        if(grass->IsGrass(x,y)==true)
                        {
                            if (e.button.button == SDL_BUTTON_LEFT)
                            {
                                mouseclicked=true;
                            }
                            if(mouseclicked == true)
                            {
                                if(lpress==true)
                                {
                                    /*
                                    create rocket turret and decrease the amount from user
                                    */

                                    rocketturret= new RocketTurret(&gSpriteSheetTexture,x,y,1000,1000);
                                    gameobjects.Push(rocketturret);
                                    gameobjects.CheckMoney(-1000,gRenderer);

                                    mouseclicked=false;
                                }
                                if(defalt==true)
                                {
                                    /*
                                    create cannon and decrease the amount from user
                                    */

                                    cannon= new Cannon(&gSpriteSheetTexture,x,y,500,1000);
                                    gameobjects.Push(cannon);
                                    gameobjects.CheckMoney(-500,gRenderer);


                                    mouseclicked=false;
                                }
                                if(ppress==true)
                                {
                                    /*
                                    create electric cannon and decrease the amount from user
                                    */

                                    electriccannon= new ElectricCannon(&gSpriteSheetTexture,x,y,2000,1000);
                                    gameobjects.Push(electriccannon);
                                    gameobjects.CheckMoney(-2000,gRenderer);


                                    mouseclicked=false;
                                }
                            }
                        }
                    }
                    else{break;}
				}

				//load grass, path and instructions

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
                SDL_RenderClear( gRenderer );
			    grass->Draw(gRenderer);
                path->Draw(gRenderer);
                instructiontext.Draw(gRenderer);

                //if game is new show objects
                if(newgame==true)
                {
                    gameobjects.Show(gRenderer,frame);
                }

                //if game is being loaded show objects from previous game
                else if (load==true)
                {
                    gameobjects.Clear();
                    manager.LoadGame(gameobjects,&gSpriteSheetTexture);
                    gameobjects.Show(gRenderer,frame);
                    newgame=true;
                    load=false;
                }

                //if game is being saved, save objects
                if(save==true)
                {
                    manager.Save(gameobjects);
                    save=false;
                }

                //the gameover bool is true, when throne health is 0
                if (gameobjects.isGameOver()==true)
                {
                    /*
                    stops the music
                    load the game over screen and music
                    take 4 seconds delay
                    make quit true, which exits the game
                    */
                    Mix_HaltMusic();
                    gameoverscreen.Load();
                    gameoverscreen.Show(gScreenSurface, gWindow);
                    SDL_Delay( 4000 );
                    cout << "GAME OVER!" << endl;
                    quit = true;
                }
                ++frame;
                SDL_RenderPresent( gRenderer );
			}
			/*
			delete grass, path, game over screen, and instructions
			clear linked list
			*/
			delete grass;
			delete path;
			gameoverscreen.~GameOverScreen();
			instructiontext.~InstructionText();
			gameobjects.~LinkedList();
		}
	}

	//Free resources and close SDL
	close();
	return 0;
}
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
		    gScreenSurface = SDL_GetWindowSurface( gWindow );
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}

				//Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "towerDefense_tilesheet.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	//Load music
	gMusic = Mix_LoadMUS( "background.wav" );
	if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTexture.Free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Free the music
	Mix_FreeMusic( gMusic );
	gMusic = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
    Mix_Quit();
}
