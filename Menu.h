#include "Game.h"


class Menu
{
public:

    Menu(char* const background,char* const play,char* const exit,char* const gameover,char* const mainmenu);
    ~Menu();

    void renderback();
    void renderplay();
    void renderupdate();
    void rendergameover();
    void rendermainmenu();
    void Cut();
    void click(SDL_Event events);
    void Clean();
    bool playne();
    bool exitne();
    bool mainne();
private:
    SDL_Texture* textureback;
    SDL_Texture* textplay;
    SDL_Texture* textexit;
    SDL_Texture* textover;
    SDL_Texture* textmain;
    SDL_Rect src,dest,destp,deste,srco,desto,srcm1,destm1,srcm2;
    SDL_Rect cut[3];
    int Mx = 0;
    int My = 0;
    bool play1 = false,play2 = false,play3 = false,play4 = false,play5 = false,play6 = false;



};
