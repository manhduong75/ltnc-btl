#include "Game.h"

class Map
{
public:
    Map(int n);
    ~Map();

    void LoadMap();
    void DrawMap();
    void CleanMap();

private:
    SDL_Rect src,dest;
    SDL_Texture* background;
    char* back[6];
    int map[20][25];
};
