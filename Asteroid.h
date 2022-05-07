#include "Game.h"
#include <iostream>

class Asteroid
{
public:
    Asteroid(const char* name);
    ~Asteroid();

    void Cuttt();
    void Random();
    void Updatett();
    void Rendertt();
    SDL_Rect Getrect();
    void Clean();

private:
    int k16=0,xpostt,ypostt,x,y;
    int A[2];


    SDL_Texture* objTexturett;
    SDL_Rect srcRectt, destRectt;
    SDL_Rect cuttt[17];

};
