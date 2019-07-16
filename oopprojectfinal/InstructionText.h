#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include <iostream>

class InstructionText
{
private:
    float x;
    float y;
    int width;
    int height;
    SDL_Rect spriteClips[1];
    LTexture spriteSheetTexture;
public:
    InstructionText();
    ~InstructionText();
    void Load(SDL_Renderer* gRenderer);
    void Draw(SDL_Renderer* gRenderer);
};
