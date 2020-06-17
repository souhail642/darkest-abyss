
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
void initialiser_effet(effet *fly){
				
			
	fly->afficher_effet=NULL;
	fly->afficher_effet=IMG_Load("fly.png");

	fly->pos_effets.x=1000;
	fly->pos_effets.y=0;
}

void afficher_effet(effet *fly,SDL_Surface *ecran){
				
		SDL_BlitSurface(fly->afficher_effet,NULL,ecran,&(fly->pos_effets));

}
