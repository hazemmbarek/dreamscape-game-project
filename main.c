#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"

 



int main()
{
    background b;
    SDL_Surface* screen = NULL;
    b.level=1;
    b.anim=-1;
    b.player=1;
    // program refuses to accept new sdl rect in struct
    SDL_Rect pos2;
 
    b.splitscreen=1;
    
	
    int direction;
    SDL_Event event;
    int quit = 0;
    
    // Initialize SDL video
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Set up the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BPP, SDL_SWSURFACE);
    if (screen == NULL)
    {
        fprintf(stderr, "Error setting video mode: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

  
     initBackg(&b);
     if(b.splitscreen==1)
	{
	pos2.x=0;
	pos2.y=50;
	pos2.w=1550;
	pos2.h=880;
	}
     animerBack(&b);
     afficherBack(b,screen,pos2);

    // Main loop
    while (!quit)
    {
         
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
	    else if (event.type ==SDL_KEYDOWN )
            {
		if(event.key.keysym.sym==SDLK_RIGHT)
		{
                        b.player=1;
			direction=1;
               	 	scrolling(&b,direction,&pos2);
		}
		if(event.key.keysym.sym==SDLK_LEFT)
		{
			b.player=1;
			direction=2;
                	scrolling(&b,direction,&pos2);
		}
		if(event.key.keysym.sym==SDLK_UP)
		{
			b.player=1;
			direction=3;
                	scrolling(&b,direction,&pos2);
		}
		if(event.key.keysym.sym==SDLK_DOWN)
		{
			b.player=1;
			direction=4;
                	scrolling(&b,direction,&pos2);
		}
		if(event.key.keysym.sym==SDLK_d)
		{
                        b.player=2;
			direction=1;
               	 	scrolling(&b,direction,&pos2);
		}
		if(event.key.keysym.sym==SDLK_q)
		{
			b.player=2;
			direction=2;
                	scrolling(&b,direction,&pos2);
		}
		if(event.key.keysym.sym==SDLK_z)
		{
			b.player=2;
			direction=3;
                	scrolling(&b,direction,&pos2);
		}
		if(event.key.keysym.sym==SDLK_s)
		{
			b.player=2;
			direction=4;
                	scrolling(&b,direction,&pos2);
		}
            }
        }

        animerBack(&b);
        afficherBack(b,screen,pos2);

       

        SDL_Flip(screen);
    }

    // Clean up
    SDL_Quit();
    return EXIT_SUCCESS;
}

