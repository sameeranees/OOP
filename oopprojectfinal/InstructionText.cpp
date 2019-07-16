#include "InstructionText.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

InstructionText::InstructionText()
{

}

void InstructionText::Load(SDL_Renderer* gRenderer)
{
    /*
    an instruction text, to tell player how to make new game, load or save
    load sprite clips after loading texture from source file
    */

    if( !spriteSheetTexture.LoadFromFile( "text.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
	}

	spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w = 512;
    spriteClips[ 0 ].h = 128;

    this->x = 64*8;
    this->y = 64*9;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}

void InstructionText::Draw(SDL_Renderer* gRenderer)
{
    //render the instructions

    spriteSheetTexture.Render(this->x, this->y, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

InstructionText::~InstructionText()
{
    spriteSheetTexture.Free();
}
