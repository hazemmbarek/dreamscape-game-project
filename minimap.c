#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include <time.h>
void initialiser_minimap( minimap * m)
{
m->img_map=IMG_Load("/home/farouk/Desktop/minimap1.png");
m->img_joueur=IMG_Load("/home/farouk/Desktop/mini_joueur.png");
  m->engime = IMG_Load("/home/farouk/Desktop/minimap/animation 1.png");

m->pos_map.x=500;
m->pos_map.y=0;

m->pos_joueur.x=500;
m->pos_joueur.y=148;

 m->positionengime.x = 0;
 m->positionengime.y = 0;
}

void afficher_minimap(minimap m,SDL_Surface *screen)
{

SDL_BlitSurface(m.img_map,NULL,screen,&m.pos_map);
SDL_BlitSurface(m.img_joueur,NULL,screen,&m.pos_joueur);
SDL_BlitSurface(m.engime, NULL, screen, &m.positionengime);

}
void initialiser_temps(temps *t)
{
  t->texte = NULL; // espace le lwakt m,s
  t->score = NULL;
  t->s = 0;
  t->position.x = 10;
  t->position.y = 50;
  t->police=NULL;
  t->police = TTF_OpenFont("/home/farouk/Desktop/minimap/SuperMario256.ttf", 70);
 
if (t->police == NULL)
  {
    printf("error loading font \n ");
  }

  t->color.r = 5 ; 
  t->color.g = 5 ; 
  t->color.b = 5 ; 
 
  strcpy(t->entree, "");
  (t->secondspassed) = 0;
  time(&(t->t1)); // temps du debut


}
void afficher_temps(temps *t, SDL_Surface *ecran)
{ 
  SDL_Rect pos_score;
  char sscore[100];
  pos_score.x= 1000;
  pos_score.y= 50;

  time(&(t->t2)); // wakt taw

  t->secondspassed = t->t2 - t->t1;

  t->min = ((t->secondspassed / 60) % 60);
  t->sec = ((t->secondspassed) % 60);

  sprintf(t->entree, "%02d:%02d", t->min, t->sec); 

  t->texte = TTF_RenderText_Blended(t->police, t->entree, t->color);

  SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); 

  t->s = (t->sec * 10 + t->min * 600);
  sprintf(sscore, "%02d", t->s ); 

  t->score = TTF_RenderText_Blended(t->police, sscore , t->color);

  SDL_BlitSurface(t->score, NULL, ecran, &pos_score); }
void liberer_temps(temps *t, SDL_Surface *screen)
{
    SDL_FreeSurface(t->texte);
    TTF_CloseFont(t->police);
}


void initialiser_imageBACK(image *imge) 
{
    imge->url="/home/farouk/Desktop/projet/11.png";
    imge->img=IMG_Load(imge->url);

if (imge->img == NULL) {
printf ("unable to load background image %s \n",SDL_GetError());
return ;}
imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=1080;
imge->pos_img_affiche.w=1920;
}
void afficher_imageBACK(SDL_Surface *screen,image imge)
{
imge.state=0;
SDL_BlitSurface(imge.img, &(imge.pos_img_affiche), screen, &(imge.pos_img_ecran)) ;
}
void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}

void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement)
{
    SDL_Rect posJoueurABS;
    posJoueurABS.x = 0;
    posJoueurABS.y = 0;
    posJoueurABS.x = posJoueur.x + camera.x;
    posJoueurABS.y = posJoueur.y + camera.y;
    m->pos_joueur.x = (posJoueurABS.x * redimensionnement / 100) + 250;
    m->pos_joueur.y = (posJoueurABS.y * redimensionnement / 100) + 21;
}

void liberer_minimap(minimap m)
{
    SDL_FreeSurface(m.img_map);
    SDL_FreeSurface(m.img_joueur);
}


SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{

    SDL_Color color;
    Uint32 col = 0;
   
    char *pixelPosition = (char *)Background->pixels;
    pixelPosition += (Background->pitch * y);
    pixelPosition += (Background->format->BytesPerPixel * x);
    memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
    SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

    return (color);
}
int collisionPP(Personne p, SDL_Surface *Masque)
{
    SDL_Color test, couleurnoir = {0, 0, 0};

    SDL_Rect pos[8];
    pos[0].x = p.position.x;
    pos[0].y = p.position.y;
    pos[1].x = p.position.x + p.position.w / 2;
    pos[1].y = p.position.y;
    pos[2].x = p.position.x + p.position.w;
    pos[2].y = p.position.y;
    pos[3].x = p.position.x;
    pos[3].y = p.position.y + p.position.h / 2;
    pos[4].x = p.position.x;
    pos[4].y = p.position.y + p.position.h;
    pos[5].x = p.position.x + p.position.w / 2;
    pos[5].y = p.position.y + p.position.h;
    pos[6].x = p.position.x + p.position.w;
    pos[6].y = p.position.y + p.position.h;
    pos[7].x = p.position.x + p.position.w;
    pos[7].y = p.position.y + p.position.h / 2;
    int collision = 0, x, y;

    for (int i = 0; i < 8 && collision == 0; i++)
    {
        x = pos[i].x;
        y = pos[i].y;
        test = GetPixel(Masque, x, y);
        if (test.r == 0 && test.g == 0 && test.b == 0)
            collision = 1;
    }
    return collision;
}
void animerminimap(minimap * m ,int *i)
{

 char ch[100];
    sprintf(ch, "/home/farouk/Desktop/minimap/animation %d.png",*i);
    if ((*i)==2)
        (*i)=0;
    (*i)++;
    m->engime=IMG_Load(ch);
    
        m->positionengime.x = 799;
        m->positionengime.y = 0;
         
   
}

