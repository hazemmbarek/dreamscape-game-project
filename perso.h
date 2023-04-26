#ifndef FONCTION_H
#define FONCTION_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1080
#define SCREEN_W 1920

 
typedef struct
{

SDL_Rect pos_img_affiche; 
SDL_Rect pos_img_ecran;
SDL_Surface *img;
SDL_Surface *score;
SDL_Surface *vie;
int scores;
int vies;

int direction,up,left,right,gravite;
double vitesse, acceleration,saut_y,v_saut;
}personne;
typedef struct
{
SDL_Rect pos_img_affiche[3]; 
SDL_Rect pos_img_ecran[3];
SDL_Surface *img;
int state;
}image;

//void init (personne * p, int numperso)		
void initperso(personne *p);
void initperso2(personne *p);
void afficher_perso(SDL_Surface *screen,personne p);	
void movePerso (personne *p,Uint32 dt);		
void animerPerso (personne* p);		
void saut(personne *p,int dt);	
void liberer_perso (personne p); 
void initialiser_imageBACK(image *back) ;
void afficher_imageBACK(SDL_Surface *screen,image back);
void liberer_image(image back);
void initialiser_score (personne *p);
void afficher_score (SDL_Surface *screen,personne p);
void liberer_score (personne p);
void initialiser_vie (personne *p);
void afficher_vie (SDL_Surface *screen,personne p);
void liberer_vie (personne p);

#endif
