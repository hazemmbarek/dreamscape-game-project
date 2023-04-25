#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
int main()
{

  
   int i=2;
SDL_Rect camera,pospersonnage;
temps t ;
TTF_Font *police=NULL;

minimap m;
SDL_Surface *screen,*perso;
SDL_Event event;
int boucle=1;
int redimensionement ;
image imge;
    camera.x = 30;
    camera.y = 20;
    camera.w = 800;
    camera.h = 537;
perso =IMG_Load("/home/farouk/Desktop/mini_joueur.png");


  pospersonnage.x = 0;
  pospersonnage.y = 260;
if (SDL_Init (SDL_INIT_VIDEO| SDL_INIT_AUDIO|SDL_INIT_TIMER)==1)

{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}

screen=SDL_SetVideoMode(1920,1080, 32,SDL_SWSURFACE|SDL_DOUBLEBUF);
initialiser_imageBACK(&imge);
 initialiser_temps(&t) ;
initialiser_minimap(&m);

SDL_EnableKeyRepeat(100, 10);

while(boucle)

{ 


afficher_imageBACK(screen,imge);
afficher_minimap(m,screen);
afficher_temps(&t, screen);

MAJMinimap(pospersonnage, &m, camera, 20);
animerminimap(&m ,&i);
SDL_BlitSurface(perso, NULL, screen, &pospersonnage);
SDL_Flip(screen);
   while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                boucle = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    {
                        pospersonnage.x -= 5;
                    }
                    break;
                case SDLK_RIGHT:
                        pospersonnage.x += 5;
                    break;
                case SDLK_UP:
                        pospersonnage.y -= 5;
                    break;
                case SDLK_DOWN:
                        pospersonnage.y += 5;
                    break;
                }
                break;
            }
        }


}
liberer_image(imge);
liberer_temps(&t,screen);
SDL_FreeSurface(perso);

return 0;
}

