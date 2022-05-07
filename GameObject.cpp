#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet,int x,int y)
{

   objTexture = TextureManager::LoadTexture(texturesheet);

   xpos = x;
   ypos = y;

}

GameObject::~GameObject()
{

}


void GameObject::Cut()
{
    xpos=730;
    ypos=450;
    cut[1].x=0;
    cut[1].y=0;
    cut[1].h=40;
    cut[1].w=36;

    cut[2].x=36;
    cut[2].y=0;
    cut[2].h=40;
    cut[2].w=44;

    cut[3].x=80;
    cut[3].y=0;
    cut[3].h=40;
    cut[3].w=36;

    cut[4].x=0;
    cut[4].y=40;
    cut[4].h=44;
    cut[4].w=36;

    cut[5].x=36;
    cut[5].y=40;
    cut[5].h=44;
    cut[5].w=44;

    cut[6].x=80;
    cut[6].y=40;
    cut[6].h=44;
    cut[6].w=36;

    cut[7].x=0;
    cut[7].y=84;
    cut[7].h=44;
    cut[7].w=36;

    cut[8].x=36;
    cut[8].y=84;
    cut[8].h=44;
    cut[8].w=44;

    cut[9].x=80;
    cut[9].y=84;
    cut[9].h=44;
    cut[9].w=36;

}

void GameObject::Hand(SDL_Event events)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                phim=9;phai=1;

            }
            break;
        case SDLK_LEFT:
            {
                phim=7;trai=1;
            }
            break;
        case SDLK_UP:
            {
                phim=5;len=1;
            }
            break;
        case SDLK_DOWN:
            {
                phim=2;xuong=1;
            }
            break;
        }


    }
    else if (events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                phim=8;phai=0;

            }
            break;
        case SDLK_LEFT:
            {
                phim=8;trai=0;
            }
            break;
        case SDLK_UP:
            {
                phim=8;len=0;
            }
            break;
        case SDLK_DOWN:
            {
                phim=8;xuong=0;
            }
            break;
        }
    }
    else
    {
        phim=8;
    }

}


void GameObject::Update()
{



    srcRect.h = cut[phim].h;
    srcRect.w = cut[phim].w;
    srcRect.x = cut[phim].x;
    srcRect.y = cut[phim].y;
    if ((xpos>=10)&&(xpos<=1450)) xpos=xpos+phai*10-trai*10;
    if (xpos<10) xpos+=phai*10;
    if (xpos>1450) xpos-=trai*10;
    if ((ypos>=10)&&(ypos<=890))  ypos=ypos-len*10+xuong*10;
    if (ypos<10) ypos+=xuong*10;
    if (ypos>890) ypos-=len*10;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w*1.5;
    destRect.h = srcRect.h*1.5;

}


SDL_Rect GameObject::Getship()
{
    return destRect;
}






bool GameObject::Vacham(const SDL_Rect& object1, const SDL_Rect& object2)
{
  int left_a = object1.x+20;
  int right_a = object1.x + object1.w-20;
  int top_a = object1.y+20;
  int bottom_a = object1.y + object1.h-20;

  int left_b = object2.x+20;
  int right_b = object2.x + object2.w-20;
  int top_b = object2.y+20;
  int bottom_b = object2.y + object2.h-20;


  if (left_a > left_b && left_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }
  if (left_a > left_b && left_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }
  if (right_a > left_b && right_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }
  if (right_a > left_b && right_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }
  if (left_b > left_a && left_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }
  if (left_b > left_a && left_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }
  if (right_b > left_a && right_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }
  if (right_b > left_a && right_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }

  return false;
}



void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}


void GameObject::Clean()
{
    SDL_DestroyTexture(objTexture);
}
