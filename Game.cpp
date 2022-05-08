#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Asteroid.h"
#include <SDL.h>
#include "Bum.h"
#include <iostream>
#include "Text.h"




using namespace std;


SDL_Renderer* Game::renderer = nullptr;
  GameObject* player;

 Bum* Vuno;
 SDL_Texture* gamemap;
 Map* map;



Asteroid* Thienthach[100];
 int kick=0;

 Textobject* level_game;
 string str_level = "LEVEL: 1";


SDL_Rect srcR,destR,an;




Game::Game()
{

}

Game::~Game()
{

}

void Game::init()
{


    player = new GameObject("images/ship.png", 0,0);
    kick=0;over=0;



    map= new Map(4);


   player->Cut();
   Vuno = new Bum("images/type_B.png");
   Vuno->Cut();
}



void Game::ran(int n)
{
    for (int i=1;i<=n;i++)
    {
        if (i%3==0) Thienthach[i] =  new Asteroid("images/rock_small.png");
        else Thienthach[i] =  new Asteroid("images/rock.png");
    Thienthach[i]->Cuttt();
    Thienthach[i]->Random();
    }
    level_game  = new Textobject("font/4.ttf",n);


//    level_game->Level();









}




void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)!=0)
    {
        /*if (menu->playne()==true)*/ player->Hand(event);
        /*else*/

    switch(event.type)
    {
    case SDL_QUIT:
        {
        //isRunning = false;
        Game::clean();
        break;
        }
    default:
        {

        break;
        }

    }

    }


}

void Game::update(int n)
{




    if (kick!=1)
    {player->Update();

    for (int j=1;j<=n;j++)
    {
        Thienthach[j]->Updatett();
        if (player->Vacham(player->Getship(),Thienthach[j]->Getrect()))
        {

            kick=1;


        }
        if (kick==1) break;

    }}
    if (kick==1)
    {

        Vuno->Update();over++;
        Vuno->Ghep(player->Getship());
    }











}


int Game::getkick()
{
    return kick;
}

void Game::render(int n)
{

   /* SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,gamemap,NULL,NULL);
    SDL_RenderPresent(renderer);*/
    //SDL_RenderClear(renderer);





    map->DrawMap();


    if (kick!=1) player->Render();

    for (int l=1;l<=n;l++)
        Thienthach[l]->Rendertt();
        Vuno->Render();
        if (over==100) isRunning=false;



    level_game->RenderText(renderer,1400,15,an,0.0,NULL,SDL_FLIP_NONE);






    //SDL_RenderPresent(renderer);



}

void Game::clean()

{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    level_game->Clean();
    Vuno->Clean();
    map->CleanMap();
    player->Clean();
    SDL_Quit();
    cout<<"game cleaned"<<endl;



}


void Game::comeback()
{
    isRunning=true;
}

bool Game::running()
{
return isRunning;
}
