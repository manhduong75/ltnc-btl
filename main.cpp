
#include "Game.h"
#include<SDL.h>
#include<SDL_ttf.h>
#include "Text.h"
#include "Menu.h"


#undef main


Game *game = new Game();


using namespace std;

SDL_Window *window;
//SDL_Renderer *renderer;


void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags=0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(window)
        {
            cout<<"window created"<<endl;
        }
        Game::renderer = SDL_CreateRenderer(window,-1,0);
        if(Game::renderer)
        {
            SDL_SetRenderDrawColor(Game::renderer,255,255,255,255);
            cout<<"renderer created"<<endl;
        }
       // isRunning = true;
    } else
    {
        //isRunning = false;
    }


}

int main(int argc, const char *argv[])
{
    game->init();
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;








    if (TTF_Init()==-1) cout<<"ok"<<endl;
    int k=0;










    init("ASTEROIDS DISASTER",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1536,960,false);

    Menu* menu;

    bool comeback=true;




    while(comeback==true)
    {
        SDL_Event eventt;
        SDL_PollEvent(&eventt);

        //game=new Game();
    menu= new Menu("images/background6.png","images/play.png","images/exit.png","images/gameover.png","images/mainmenu.png");
    menu->Cut();
    game->init();
    menu->playne();
    Textobject* highscore = new Textobject("font/4.ttf",10);
    SDL_Rect an;









    while(SDL_PollEvent(&eventt) || menu->playne()==false)
    {
        menu->click(eventt);
        SDL_RenderClear(Game::renderer);
        menu->renderback();
        menu->renderplay();
        highscore->RenderHigh(Game::renderer,1400,15,an,0.0,NULL,SDL_FLIP_NONE);
        //menu->rendermainmenu();
        //menu->rendergameover();
        SDL_RenderPresent(Game::renderer);
        if (menu->exitne()==true) {game->clean();comeback=false;menu->Clean();SDL_DestroyWindow(window);break;}


        switch(eventt.type)
    {
    case SDL_QUIT:
        {
        game->clean();
        menu->Clean();
        comeback=false;
        break;
        }
    default:
        {

        break;
        }

    }
    game->comeback();

    }

    int n=0,dem=289;






    while (game->running())
    {


         if (dem==289)
         {
             n++;
             game->ran(n);
             dem=0;
             cout<<n<<endl;//Textobject::level=n;
             //cout<<Textobject::level<<endl;
         }
         else
         {
             dem++;
         }



        frameStart = SDL_GetTicks();


        game->handleEvents();
        game->update(n);
        SDL_RenderClear(Game::renderer);
        game->render(n);

        if (game->getkick()==1)
        {

            menu->rendergameover();

        }
        SDL_RenderPresent(Game::renderer);


        frameTime = SDL_GetTicks() - frameStart;


        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    while(SDL_PollEvent(&eventt) || menu->mainne()==false)
    {
        menu->click(eventt);
        SDL_RenderClear(Game::renderer);
        menu->renderback();
        //menu->renderplay();
        menu->rendermainmenu();
        //menu->rendergameover();
        SDL_RenderPresent(Game::renderer);
        //if (menu->exitne()==true) {game->clean();comeback=false;}


        switch(eventt.type)
    {
    case SDL_QUIT:
        {
        game->clean();
        menu->Clean();
        comeback=false;
        break;
        }
    default:
        {

        break;
        }

    }


    }





    }





    game->clean();
    menu->Clean();
    SDL_DestroyWindow(window);


    return 0;
}
