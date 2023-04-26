#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"

void initperso (personne * p)
{
p->img=IMG_Load("/home/farah/Desktop/perso/sprite.png") ;
if(p->img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
p->pos_img_affiche.x=444-(444/6);
p->pos_img_affiche.y=0;
p->pos_img_affiche.w=444/6;
p->pos_img_affiche.h=562/4;
p->vitesse = 5;
p->acceleration=0;
p->pos_img_ecran.x=10;
p->pos_img_ecran.y=640;
p->pos_img_ecran.w=444/6;
p->pos_img_ecran.h=562/4;

}
void initperso2 (personne * p)
{
p->img=IMG_Load("/home/farah/Desktop/perso/sprite.png") ;
if(p->img == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
p->pos_img_affiche.x=444-(444/6);
p->pos_img_affiche.y=0;
p->pos_img_affiche.w=444/6;
p->pos_img_affiche.h=562/4;
p->vitesse = 5;
p->acceleration=0;
p->pos_img_ecran.x=960+10;
p->pos_img_ecran.y=640;
p->pos_img_ecran.w=444/6;
p->pos_img_ecran.h=562/4;

}
void afficher_perso (SDL_Surface *screen,personne p)
{
	SDL_BlitSurface(p.img,(&p.pos_img_affiche),screen,(&p.pos_img_ecran));
}
void liberer_perso (personne p)
{
	SDL_FreeSurface(p.img);
}
void initialiser_imageBACK(image *back) 
{	back->img=IMG_Load("/home/farah/Desktop/perso/backg.png");

if (back->img == NULL) 
{
printf ("unable to load background image %s \n",SDL_GetError());
return ;
}
back->pos_img_ecran[0].x=0;
back->pos_img_ecran[0].y=0;
back->pos_img_ecran[0].h=1080;
back->pos_img_ecran[0].w=1920;
back->pos_img_affiche[0].x=0;
back->pos_img_affiche[0].y=0;
back->pos_img_affiche[0].h=1080;
back->pos_img_affiche[0].w=1920;
}
void afficher_imageBACK(SDL_Surface *screen,image back)
{
back.state=0;
SDL_BlitSurface(back.img, &(back.pos_img_affiche[0]), screen, &(back.pos_img_ecran[0])) ;
}
void liberer_image(image back)
{
SDL_FreeSurface(back.img);
}
void initialiser_score (personne *s)
{
s->score=IMG_Load("/home/farah/Desktop/perso/scoreeeee1 copie.png") ;
if(s->score== NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}

s->pos_img_affiche.x=1;
s->pos_img_affiche.y=50;
s->pos_img_affiche.w=347;
s->pos_img_affiche.h=536/7;
s->pos_img_ecran.x=1380;
s->pos_img_ecran.y=40;
s->pos_img_ecran.w=347;
s->pos_img_ecran.h=(536/7);

}
void afficher_score (SDL_Surface *screen,personne s)
{
	SDL_BlitSurface(s.score,(&s.pos_img_affiche),screen,(&s.pos_img_ecran));
}
void liberer_score (personne s)
{
	SDL_FreeSurface(s.score);
}
void initialiser_vie (personne *v)
{
v->vie=IMG_Load("/home/farah/Desktop/perso/45-removebg-preview (1).png") ;
if(v->vie == NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;}
v->pos_img_affiche.x=1;
v->pos_img_affiche.y=1;
v->pos_img_affiche.w=225;
v->pos_img_affiche.h=66;
v->pos_img_ecran.x=80;
v->pos_img_ecran.y=43;
v->pos_img_ecran.w=225;
v->pos_img_ecran.h=66;

}
void afficher_vie (SDL_Surface *screen,personne v)
{
	SDL_BlitSurface(v.vie,(&v.pos_img_affiche),screen,(&v.pos_img_ecran));
}
void liberer_vie (personne v)
{
	SDL_FreeSurface(v.vie);
}

void movePerso(personne *p,Uint32 dt)
{
double dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
    if (p->right==1)
    {
       if (p->pos_img_ecran.x < 970) {p->pos_img_ecran.x += dx ;} 
             
    }else if (p->left==1)
    {
        if (p->pos_img_ecran.x >0 ) {p->pos_img_ecran.x -= dx;}
    }          
}
void movePerso2(personne *p,Uint32 dt)
{
double dx = 0.5 * p->acceleration * dt * dt + p->vitesse * dt ;
    if (p->right==1)
    {
       if (p->pos_img_ecran.x < SCREEN_W) {p->pos_img_ecran.x += dx ;} 
             
    }else if (p->left==1)
    {
        if (p->pos_img_ecran.x >970) {p->pos_img_ecran.x -= dx;}
    }          
}
void animerPerso(personne *p)
{
if((p->left==1)||(p->right==1)||(p->up==1))
         {p->pos_img_affiche.x += p->pos_img_affiche.w;
        if ( p->pos_img_affiche.x >=444) {
             p->pos_img_affiche.x = 0;
        }
         p->pos_img_affiche.y =  p->pos_img_affiche.h * p->direction;
    }
 else
{if(p->right==0)
{p->pos_img_affiche.x = 444-(444/6);
        p->pos_img_affiche.y = 0;}

}}
 void saut(personne *p,int dt)
{
if (p->up==1) {if (p->pos_img_ecran.y == 640)
    {
       p->saut_y=-50;
      }}
if(p->pos_img_ecran.y<300){
p->pos_img_ecran.y += p->saut_y ;
p->saut_y = p->saut_y - 10 ;}

p->pos_img_ecran.y += p->saut_y ;
p->saut_y = p->saut_y + 10 ;
if (p->pos_img_ecran.y>=640)
{   
    p->pos_img_ecran.y=640;
    p->saut_y=0;
    p->up=0;
}

}
    

