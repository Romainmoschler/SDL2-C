#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "createForm.h"

int main(int argc, char *argv[])
{
    SDL_Manager manage;
    SDL_Rect position;

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;


        //Initialisation de SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)>= 0)
    {
        initsdl(manage.pWindow,manage.pRenderer);
        SDL_Delay(1000);

        SDL_SetRenderDrawColor(manage.pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderPresent(manage.pRenderer);
        //syncronisation et raffraichissement des frame d'affichage à l'écran
        SDL_Delay(1000);

        SDL_SetRenderDrawColor(manage.pRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        //EFFACEMENT ANCIEN REDU
        SDL_RenderClear(manage.pRenderer);
        //AFFICHAGE NOUVEAU RENDU
        SDL_RenderPresent(manage.pRenderer);
        SDL_Delay(1000);

        SDL_SetRenderDrawColor(manage.pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);


        DrawRect(manage.pRenderer,0,0,150,150,0);
        DrawRect(manage.pRenderer,512,0,150,150,1);
        SDL_RenderPresent(manage.pRenderer);
        SDL_Delay(1000);

        DrawCircle(manage.pRenderer,150,780/2,150,0);
        DrawCircle(manage.pRenderer,662,780/2,150,1);
        SDL_Delay(1000);

        manage.pSurface = SDL_CreateRGBSurface(0,1024,780,32,rmask,gmask,bmask,amask); //initialisation du pointeur de surface

        manage.pTexture = SDL_CreateTexture(manage.pRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,500,500); //Fonction pour initialiser le pointeur Texture

        SDL_SetRenderDrawColor(manage.pRenderer,255,192,203,255);
        SDL_SetRenderTarget(manage.pRenderer,manage.pTexture); // dessiner dans la texture cree en amont
        DrawRect(manage.pRenderer,150,150,0,0,1);
        SDL_SetRenderTarget(manage.pRenderer,NULL); //on dessine a pr"sent sur le render
        SDL_RenderClear(manage.pRenderer);

        position.x = 150;
        position.y = 150;
        SDL_SetRenderDrawColor(manage.pRenderer,255,192,203,255);
        SDL_QueryTexture(manage.pTexture, NULL, NULL, &position.w, &position.h);
        SDL_RenderCopy(manage.pRenderer,manage.pTexture,NULL,&position);
        SDL_RenderPresent(manage.pRenderer);
        SDL_Delay(1000);

        SDL_RenderClear(manage.pRenderer);

        afficheImage(manage,position);
        SDL_RenderPresent(manage.pRenderer);
        SDL_Delay(1000);






        //suppresion/netoyage
        SDL_FreeSurface(manage.pSurface);
        SDL_DestroyTexture(manage.pTexture);
        SDL_DestroyRenderer(manage.pRenderer);
        SDL_DestroyWindow(manage.pWindow);
        SDL_QUIT;
    }

    return 0;
}
