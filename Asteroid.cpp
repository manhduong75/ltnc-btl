#include "Asteroid.h"
#include "TextureManager.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

void Asteroid::Cuttt()
{

for (int i=1;i<=16;i++)
{

    cuttt[i].x=(i-1)*64;
    cuttt[i].y=0;
    cuttt[i].h=64;
    cuttt[i].w=64;
}






}


Asteroid::Asteroid(const char* name)
{
   objTexturett = TextureManager::LoadTexture(name);
}

Asteroid::~Asteroid()
{

}



void Asteroid::Random()
{
    A[0]=11;A[1]=-1;
     xpostt = -6 + (rand() % (22 +1 +6));
    if (xpostt<0) ypostt= (-1 + (rand() % (1+1+1)))*100;
    if (xpostt>16) ypostt=(-1 + (rand() % (1+1+1)))*100;
    if ((xpostt>=0)&&(xpostt<=16)) ypostt=100*(A[(0+rand()%2)]);

    xpostt=xpostt*100;x=xpostt;y=ypostt;

}


void Asteroid::Updatett()
{

    if (k16<16) k16++; else k16=1;
    srcRectt.h = cuttt[k16].h;
    srcRectt.w = cuttt[k16].w;
    srcRectt.x = cuttt[k16].x;
    srcRectt.y = cuttt[k16].y;
    if ((xpostt<0)&&(ypostt<490))                      {x+=4 + (rand() % (10 +1 -4));y+=1 + (rand() % (6 +1 -1));}
    if ((xpostt<0)&&(ypostt>=490))                     {x+=4 + (rand() % (10 +1 -4));y-=1 + (rand() % (6 +1 -1));}
    if ((xpostt>=0)&&(xpostt<750)&&(ypostt==-100))     {x+=3 + (rand() % (8 +1 -3));y+=2 + (rand() % (8 +1 -2));}
    if ((xpostt>=0)&&(xpostt<750)&&(ypostt==1100))     {x+=3 + (rand() % (8 +1 -3));y-=2 + (rand() % (8 +1 -2));}
    if ((xpostt>=750)&&(xpostt<=1600)&&(ypostt==-100)) {x-=3 + (rand() % (8 +1 -3));y+=2 + (rand() % (8 +1 -2));}
    if ((xpostt>=750)&&(xpostt<=1600)&&(ypostt==1100)) {x-=3 + (rand() % (8 +1 -3));y-=2 + (rand() % (8 +1 -2));}
    if ((xpostt>1600)&&(ypostt<490))                   {x-=4 + (rand() % (10 +1 -4));y+=1 + (rand() % (6 +1 -1));}
    if ((xpostt>1600)&&(ypostt>=490))                  {x-=4 + (rand() % (10 +1 -4));y-=1 + (rand() % (6 +1 -1));}
    destRectt.x = x;
    destRectt.y = y;
    destRectt.w = srcRectt.w*1.5;
    destRectt.h = srcRectt.h*1.5;

}

SDL_Rect Asteroid::Getrect()
{
   return destRectt;
}

void Asteroid::Rendertt()
{
    SDL_RenderCopy(Game::renderer, objTexturett, &srcRectt, &destRectt);


}


void Asteroid::Clean()
{
    SDL_DestroyTexture(objTexturett);
}
