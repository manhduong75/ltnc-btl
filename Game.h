#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();

    void init();
    void ran(int n);
    void rant();



    void handleEvents();
    void update(int n);
    void render(int n);
    void clean();
    bool running();
    void comeback();
    int getkick();

    static SDL_Renderer* renderer;


private:
    bool isRunning=true;
    int over=0;
    SDL_Window *window;







};
#endif // Game_h

