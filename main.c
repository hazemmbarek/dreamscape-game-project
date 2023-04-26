#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

int main()
{
SDL_Surface *screen;
SDL_Event event;
int boucle=1;
personne p,s,v;
Uint32 dt, t_prev;
image back;
int acceleration,deceleration;
if (SDL_Init (SDL_INIT_VIDEO| SDL_INIT_AUDIO|SDL_INIT_TIMER)==1)

{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}

screen=SDL_SetVideoMode(1800, 1080, 32,SDL_SWSURFACE|SDL_DOUBLEBUF);
initialiser_imageBACK(&back) ;
initperso(&p);
initperso2(&p);
initialiser_score (&s);
initialiser_vie (&v);

while(boucle)
{       afficher_imageBACK(screen,back);
	afficher_perso(screen,p);
        afficher_score(screen,s);
        afficher_vie (screen,v);
t_prev = SDL_GetTicks();
movePerso(&p,dt);
animerPerso (&p);
	while(SDL_PollEvent(&event))
       {
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
	
             case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
             case SDLK_LEFT:
       
           p.left=1;
          p.direction=3;
             break;
            case SDLK_RIGHT:
               p.right=1;
         p.direction=0;
		
               break;
            
             case SDLK_UP:
             p.up=1;
             p.direction=2;
saut(&p,dt);
              break;
            case SDLK_a:
             p.acceleration += 0.005 ;
             break;
             case SDLK_d:
            p.acceleration -= 0.1 ;
            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                          p.left=0;p.direction=3;
				
                            break;
                        case SDLK_RIGHT:
                   p.right=0;p.direction=0;
			
                            break;
                 case SDLK_UP:
                     p.up=0; p.direction=2;
			
                    
                            break;
                    
                   case SDLK_a:
       
p.acceleration -=0.001;if (p.acceleration<0) {p.acceleration =0;}
             break;
             case SDLK_d:
         
p.acceleration -=0.001;if (p.acceleration<0) {p.acceleration =0;}
            break;
                    }
                    break;
        }



SDL_Delay(3);
 
dt=SDL_GetTicks()-t_prev;
     }
SDL_Flip(screen);
      

}
liberer_image(back);
liberer_perso (p);
liberer_score (s);
liberer_vie (v);
return 0;
}
