
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "es.h"
int main()
{
SDL_Surface *screen;
SDL_Event event;
int boucle=1;
enemie e;
image imge;
SDL_Rect rect2 = { 300, 300,400, 400 };


  int result = collisionbb(e.pos, rect2);


  if (result == 1) {
    printf("Collision détectée !\n");
  } else {
    printf("Pas de collision.\n");
  }

if (SDL_Init (SDL_INIT_VIDEO| SDL_INIT_AUDIO|SDL_INIT_TIMER)==1)

{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}

screen=SDL_SetVideoMode(1920,1080, 32,SDL_SWSURFACE|SDL_DOUBLEBUF);
initialiser_imageBACK (&imge);
initennemi(&e);
while(boucle)
{      
	
	afficher_imageBACK(screen,imge);
	afficherennemi(&e,screen);
	
	
	animerennemi(&e);
	SDL_Delay(100);
	deplacer(&e);
	result = collisionbb(e.pos, rect2);


  	if (result == 1) {
    	printf("Collision détectée !\n");
 	} else {
    	printf("Pas de collision.\n");
  	}
	while(SDL_PollEvent(&event))
       {
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
	}
       
      }SDL_Flip(screen);
}
liberer_image(imge);
//liberer_enemy (e);
return 0;
}
