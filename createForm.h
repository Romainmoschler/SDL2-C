#ifndef CREATEFORM_H_INCLUDED
#define CREATEFORM_H_INCLUDED

typedef struct SDL_Manager
{
    SDL_Window *pWindow; //pointeur typedef SDL_Window possede la reference d'un window(win32)
    SDL_Renderer *pRenderer;//pointeur typedef SDL_Renderer possede la reference du rendu encapsule dans window
    SDL_Texture *pTexture;//pointeur typedef SDL_Texture possede la reference de l'objet image,materiel ou texture qui sera blite dans le rendu
    SDL_Surface *pSurface; //poiteur typedef SDL_Surface
}SDL_Manager;

void DrawCircle(SDL_Renderer * renderer, int centreX, int centreY, int radius, int full);
void DrawRect(SDL_Renderer *renderer, int posX, int posY, int width, int height, int oui);
void intitSdl(SDL_Window *window,SDL_Renderer *renderer,char nom);
void afficheImage(SDL_Manager manage,SDL_Rect position);

#endif // CREATEFORM_H_INCLUDED
