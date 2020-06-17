#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
SDL_Color GetPixel2(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;
	char* pPosition = ( char* ) surface->pixels ;
	pPosition += ( surface->pitch * y ) ;
	pPosition += ( surface->format->BytesPerPixel * x ) ;
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}

void writeqs1(SDL_Surface *ecran,char qus[]){

  //char qus[70]="To get the key u have to put the right answer in the blank";
  SDL_Color color;
    color.r = 70 ;
        color.g = 0 ;
        color.b = 0 ;
  TTF_Font *font = NULL;
  TTF_Init();
  SDL_Rect posqus;  
  posqus.x=20;
  posqus.y=20; 
  SDL_Surface *message;
  font=TTF_OpenFont("Comic_Sans_MS_Bold.ttf",17);
  message= TTF_RenderText_Solid(font,qus,color);
  SDL_BlitSurface (message,NULL,ecran,&posqus);
  TTF_Quit();
}

void writeqs2(SDL_Surface *ecran,char qus[]){

  //char qus[70]="To get the key u have to put the right answer in the blank";
  SDL_Color color;
    color.r = 70 ;
        color.g = 0 ;
        color.b = 0 ;
  TTF_Font *font = NULL;
  TTF_Init();
  SDL_Rect posqus;  
  posqus.x=20;
  posqus.y=40; 
  SDL_Surface *message;
  font=TTF_OpenFont("Comic_Sans_MS_Bold.ttf",17);
  message= TTF_RenderText_Solid(font,qus,color);
  SDL_BlitSurface (message,NULL,ecran,&posqus);
  TTF_Quit();
}
void writeqs5(SDL_Surface *ecran,char qus[],int x, int y){

  //char qus[70]="To get the key u have to put the right answer in the blank";
  SDL_Color color;
    color.r = 70 ;
    color.g = 0 ;
    color.b = 0 ;
  TTF_Font *font = NULL;
  TTF_Init();
  SDL_Rect posqus;  
  posqus.x=x;
  posqus.y=y; 
  SDL_Surface *message;
  font=TTF_OpenFont("Comic_Sans_MS_Bold.ttf",17);
  message= TTF_RenderText_Solid(font,qus,color);
  SDL_BlitSurface (message,NULL,ecran,&posqus);
  TTF_Quit();
}
int collision_Parfaiteenigme(SDL_Surface *calque,int x,int y){

  SDL_Color col;
  col=GetPixel2(calque,x,y);
  printf("%d    %d   %d\n",col.r,col.b,col.g);
  if ((col.r==0)&&(col.b==0)&&(col.g==0))
    return 1;
  else if ((col.r==0)&&(col.b==1)&&(col.g==255))
    return 2;
  else if ((col.r==254)&&(col.b==0)&&(col.g==0))
    return 3;
  else 
    return 0;
}

void initialiser_enigme2(enigme2 *enig2){

    enig2->afficher_enigme2=IMG_Load("map.jpg");

    enig2->calque_enigme2=IMG_Load("calque.jpg");
    enig2->imggameover=IMG_Load("gameover.png");

     enig2->pos_enigme2.x=0;
     enig2->pos_enigme2.y=0;
     enig2->start=0;
     enig2->x=0;
     enig2->y=0;
     enig2->lost=0;
}
void afficher_enigme2(enigme2 enig2, SDL_Surface *ecran){
  //char qus[100];
  SDL_BlitSurface(enig2.afficher_enigme2,NULL,ecran,&(enig2.pos_enigme2));
}
void resolution_enigme2(enigme2 *enig2,SDL_Surface *ecran){
int co;
  SDL_Event e;
  SDL_PollEvent(&e);
  char qus[100];
  SDL_GetMouseState(&enig2->x,&enig2->y);
  printf("%d %d\n",enig2->x,enig2->y);
  co=collision_Parfaiteenigme(enig2->calque_enigme2,enig2->x,enig2->y);
    printf("%d\n",co);
    if (co==2){
      enig2->start=1;
    }
    if (enig2->start==0){
        sprintf(qus," click on asma and show ");
        writeqs1(ecran,qus);
        sprintf(qus," him the path to the key ");
        writeqs2(ecran,qus);
    }
    else {
          if (co==1){
            SDL_BlitSurface(enig2->imggameover,NULL,ecran,&enig2->pos_enigme2);
            SDL_Flip(ecran);
            SDL_Delay(2000);
            enig2->lost=1;
          }
          else if (co==3){
            printf("you won\n");
            sprintf(qus,"you won");
            writeqs1(ecran,qus);
            enig2->lost=2;
          }
    }
}