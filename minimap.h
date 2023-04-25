#ifndef FONCTION_H_
#define FONCTION_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
typedef struct minimap{
	SDL_Surface *img_map;
	SDL_Rect pos_map;
	SDL_Surface *img_joueur;
	SDL_Rect pos_joueur;
        SDL_Surface *engime;
        SDL_Rect positionengime;
}minimap;

typedef struct
{
    SDL_Surface *sprite_sheet;
    int largeur;
    int x_max;
    int num_sprite;
    int nombre_image;
} animation;


typedef struct
{
    int nombre_vie;
    float score;
    int player_number;
    SDL_Rect position;
    int direction;
    int action;
    int action_precedente;
    SDL_Surface *image_actuel;
    SDL_Rect position_sprite;
    int vitesse;
    int acceleration;

    animation ANIMATION[10];
} Personne;


typedef struct temps
{
   SDL_Surface *texte; 
   SDL_Surface * score;
   int s;
   SDL_Rect position;  

   TTF_Font *police;

   char entree[100];         
   int secondspassed;     
   SDL_Color color; 
   time_t t1, t2;            
   int min, sec;             
} temps;

 
typedef struct
{
char *url;
SDL_Rect pos_img_affiche; 
SDL_Rect pos_img_ecran;
SDL_Surface *img;
int state;
}image;

void initialiser_minimap(minimap *m);
void afficher_minimap(minimap m,SDL_Surface *screen);
void afficher_temps(temps *t, SDL_Surface *ecran);
void initialiser_imageBACK(image *imge);
void afficher_imageBACK(SDL_Surface *screen,image imge);
void liberer_image(image imge);

void initialiser_temps(temps *t);
void liberer_temps(temps *t, SDL_Surface *screen);
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP(Personne p, SDL_Surface *Masque);
void animerminimap(minimap * m ,int *i);
void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement);



#endif

