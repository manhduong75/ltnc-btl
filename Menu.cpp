#include "TextureManager.h"
#include "Menu.h"
#include "Game.h"
#include <iostream>
using namespace std;

Menu::Menu(char* const background,char* const play,char* const exit,char* const gameover,char* const mainmenu)

{
  textureback=TextureManager::LoadTexture(background);
  textplay=TextureManager::LoadTexture(play);
  textexit=TextureManager::LoadTexture(exit);
  textover=TextureManager::LoadTexture(gameover);
  textmain=TextureManager::LoadTexture(mainmenu);
  src.x=src.y=0;
  srco.x=190;
  srco.y=0;
  srco.h=30;
  srco.w=190;
    src.w=5000;
    src.h=5000;
    dest.w=1536;
    dest.h=960;
    dest.x=dest.y=0;
    destp.x=(1536-400)/2;
    destp.y=(960-100)/2-100;
    destp.h=100;
    destp.w=400;
    deste.x=(1536-400)/2;
    deste.y=(960-100)/2+100;
    deste.h=100;
    deste.w=400;
    desto.x=(1536-190*3)/2;
    desto.y=(960-30*3)/2;
    desto.h=30*3;
    desto.w=190*3;
    srcm1.x=0;
    srcm1.y=0;
    srcm1.h=80;
    srcm1.w=200;
    srcm1.x=400;
    srcm2.y=0;
    srcm2.h=80;
    srcm2.w=200;
    destm1.x=100;
    destm1.y=100;
    destm1.h=80;
    destm1.w=200;


}

Menu::~Menu()
{

}


void Menu::Cut()
{
    for (int i=1;i<=3;i++)
{

    cut[i].x=(i-1)*400;
        cut[i].y=0;
        cut[i].h=100;
        cut[i].w=400;
}

}


void Menu::renderback()
{
SDL_RenderCopy(Game::renderer,textureback,&src,&dest);

}

void Menu::renderplay()
{
if (play2==true) SDL_RenderCopy(Game::renderer,textplay,&cut[2],&destp);
else SDL_RenderCopy(Game::renderer,textplay,&cut[1],&destp);

if (play4==true) SDL_RenderCopy(Game::renderer,textexit,&cut[2],&deste);
else SDL_RenderCopy(Game::renderer,textexit,&cut[1],&deste);
//SDL_RenderCopy(Game::renderer,textover,&srco,&desto);





}



void Menu::rendergameover()
{
SDL_RenderCopy(Game::renderer,textover,&srco,&desto);
}

void Menu::renderupdate()
{

}

void Menu::click(SDL_Event events)
{

    SDL_PollEvent(&events);
SDL_GetMouseState(&Mx, &My);
if (Mx >= destp.x &&
    Mx <= destp.x + destp.w &&
    My >= destp.y &&
    My <= destp.y + destp.h)
{
    play2=true;


    switch (events.type)
    {
    case SDL_MOUSEBUTTONDOWN:
        {
            play1=true;


        }break;
    case SDL_MOUSEBUTTONUP:
        {
            play1=false;

        }break;
    }




    /*if (events.type == SDL_MOUSEBUTTONUP) {play1=false;cout<<"false"<<endl;}
    else if (events.type == SDL_MOUSEBUTTONDOWN)
    {
        if (events.button.button == SDL_BUTTON_LEFT) {play1=true;cout<<"true"<<endl;}
    }*/

}
else
{
    play2=false;
}


if (Mx >= deste.x &&
    Mx <= deste.x + deste.w &&
    My >= deste.y &&
    My <= deste.y + deste.h)
{
    play4=true;
    if (events.type == SDL_MOUSEBUTTONDOWN)
    {
        if (events.button.button == SDL_BUTTON_LEFT) play3=true;
    }

}
else
{
    play4=false;
}



if (Mx >= destm1.x &&
    Mx <= destm1.x + destm1.w &&
    My >= destm1.y &&
    My <= destm1.y + destm1.h)
{
    play6=true;
    if (events.type == SDL_MOUSEBUTTONDOWN)
    {
        if (events.button.button == SDL_BUTTON_LEFT) play5=true;
    }

}
else
{
    play6=false;
}


}

void Menu::rendermainmenu()
{
    if (play6==true) SDL_RenderCopy(Game::renderer,textmain,&srcm1,&destm1);
    else SDL_RenderCopy(Game::renderer,textmain,&srcm2,&destm1);
}


void Menu::Clean()
{
    SDL_DestroyTexture(textureback);
    SDL_DestroyTexture(textplay);
    SDL_DestroyTexture(textexit);
    SDL_DestroyTexture(textmain);
    SDL_DestroyTexture(textover);

}


bool Menu::playne()
{
    return play1;
}


bool Menu::exitne()
{
    return play3;
}

bool Menu::mainne()
{
    return play5;
}
