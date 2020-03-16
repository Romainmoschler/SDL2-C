#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "createForm.h"

void initsdl(SDL_Window *window,SDL_Renderer *renderer)
{
        //creee la fenetre
        window = SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);

        if(window!= NULL)
        {
            //si la fenerte cree alors on va cree le rendu
            renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
        }
}

void DrawRect(SDL_Renderer *renderer, int posX, int posY, int width, int height, int oui)
{
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.h = height;
    rect.w = width;
    if (oui == 1)
    {
        SDL_RenderFillRect(renderer,&rect); //fait un rectangle plein
    }
    else
    {
        SDL_RenderDrawRect(renderer,&rect); //fait un rectangle sans fond
    }
}

void DrawCircle(SDL_Renderer * renderer, int centreX, int centreY, int radius, int full)
{
   const int diameter = (radius * 2);

   int x = (radius - 1);
   int y = 0;
   int tx = 1;
   int ty = 1;
   int error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
        if (full == 1)
        {
            /* code */

            SDL_RenderDrawLine(renderer,centreX-y,centreY-x,centreX-y,centreY+x);
            SDL_RenderDrawLine(renderer,centreX+x,centreY-y,centreX+x,centreY+y);
            SDL_RenderDrawLine(renderer,centreX-x,centreY-y,centreX-x,centreY+y);
            SDL_RenderDrawLine(renderer,centreX+y,centreY-x,centreX+y,centreY+x);
        }
        else
        {
            SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
            SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
            SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
            SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
            SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
            SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
            SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
            SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);
        }


      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
   SDL_RenderPresent(renderer);
}

void afficheImage(SDL_Manager manage,SDL_Rect position)
{
    manage.pSurface = SDL_LoadBMP("spartan.bmp");
    if(!manage.pSurface)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
    }
    manage.pTexture = SDL_CreateTextureFromSurface(manage.pRenderer,manage.pSurface);
    SDL_RenderCopy(manage.pRenderer,manage.pTexture,NULL,&position);
    SDL_RenderPresent(manage.pRenderer);
}
