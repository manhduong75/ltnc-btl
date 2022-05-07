#include "Map.h"
#include "TextureManager.h"




Map::Map(int n)
{
    back[1]="images/background1.png";
    back[2]="images/background2.png";
    back[3]="images/background3.png";
    back[4]="images/background4.png";
    back[5]="images/background5.png";
    back[6]="images/background6.png";

    background = TextureManager::LoadTexture(back[n]);
    src.x=src.y=0;
    src.w=2560;
    src.h=1600;
    dest.w=1536;
    dest.h=960;
    dest.x=dest.y=0;
}

Map::~Map()
{

}

void Map::LoadMap()
{

}

void Map::DrawMap()
{
    TextureManager::Draw(background,src,dest);
}



void Map::CleanMap()
{
    SDL_DestroyTexture(background);
}
