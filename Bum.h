#include "Game.h"
#include <iostream>



class Bum
{
public:
    Bum(const char* name);
    ~Bum();

    void Cut();
    void Update();
    void Ghep(const SDL_Rect& ship);
    void Render();
    void Clean();

private:
    int k64=0;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Rect No[65];
};

