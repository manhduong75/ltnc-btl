#include "Game.h"

class GameObject
{
public:
    GameObject(const char* texturesheet,int x,int y);
    ~GameObject();
    void Cut();
    void Hand(SDL_Event events);

    void Update();
    void Render();
    SDL_Rect Getship();
    bool Vacham(const SDL_Rect& object1, const SDL_Rect& object2);
    static SDL_Rect ship;
    void Clean();
//    static int i=1;

private:
    int xpos,trai=0,phai=0,len=0,xuong=0;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Rect cut[10];
    int phim;


};
