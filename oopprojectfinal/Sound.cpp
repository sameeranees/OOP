#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <stdio.h>
#include "Sound.h"

using namespace std;

Sound::Sound()
{
    sound0 = NULL;
}

Sound::Sound(string filepath)
{
    //load sound from provided file path, depends on which object calls for sound

    sound0 = Mix_LoadWAV( filepath.c_str() );
	if( sound0 == NULL )
	{
		printf( "Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}
}

void Sound::Play()
{
    //play sound
    Mix_PlayChannel( -1, sound0, 0 );
}

Sound::~Sound()
{
    //remove sound
    Mix_FreeChunk( sound0 );
	sound0 = NULL;
}
