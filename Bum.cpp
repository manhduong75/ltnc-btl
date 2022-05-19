#include "Bum.h"
#include "TextureManager.h"






Bum::Bum(const char* name)
{
    objTexture = TextureManager::LoadTexture(name);
}

Bum::~Bum()
{

}

void Bum::Cut()
{
    for (int i=1;i<=64;i++)
{

    No[i].x=(i-1)*192;
    No[i].y=0;
    No[i].h=192;
    No[i].w=192;
}

}



void Bum::Update()
{
    if (k64<64) k64++; else k64=0;
    srcRect.x=No[k64].x;
    srcRect.y=No[k64].y;
    srcRect.h=No[k64].h;
    srcRect.w=No[k64].w;

}


void Bum::Ghep(const SDL_Rect& ship)
{
    destRect.x=ship.x-63;
    destRect.y=ship.y-63;
    destRect.w=192;
    destRect.h=192;
}
void Bum::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}


void Bum::Clean()
{

    SDL_DestroyTexture(objTexture);
}
