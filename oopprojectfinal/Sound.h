#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

using namespace std;

class Sound
{
private:
    Mix_Chunk* sound0;
public:
    Sound();
    Sound(string);
    void Play();
    ~Sound();
};
