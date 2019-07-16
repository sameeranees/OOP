#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <stdio.h>
#include "GameOverScreen.h"

using namespace std;

GameOverScreen::GameOverScreen()
{
    /* set goSound and goScreen to null */

    goScreen = NULL;
    goSound = NULL;
}

void GameOverScreen::Load()
{
    /* load the sound and the screen from the source */

    goSound = Mix_LoadWAV( "gameover.wav" );
	if( goSound == NULL )
	{
		printf( "Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}

    goScreen = SDL_LoadBMP( "gameover.bmp" );
    if( goScreen == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "gameover.png", SDL_GetError() );
    }
}

void GameOverScreen::Show(SDL_Surface* gScreenSurface, SDL_Window* gWindow)
{
    /* show game over screen, update window and play the game over sound */

    SDL_BlitSurface( goScreen, NULL, gScreenSurface, NULL );

    SDL_UpdateWindowSurface( gWindow );

    Mix_PlayChannel( -1, goSound, 0 );
}

GameOverScreen::~GameOverScreen()
{
    //once done delete screen and sound

    SDL_FreeSurface( goScreen );
    goScreen= NULL;
    delete goSound;

    Mix_FreeChunk( goSound );
	goSound = NULL;
}
