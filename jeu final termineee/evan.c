#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
#include <time.h>
void initialiser_evan(hero *evan){
		
		evan->afficher_hero[0]=NULL;
		evan->afficher_hero[1]=NULL;
		evan->afficher_hero[2]=NULL;
		evan->afficher_hero[3]=NULL;
		evan->afficher_hero[4]=NULL;
		evan->afficher_hero[5]=NULL;
		evan->afficher_hero[6]=NULL;
		evan->afficher_hero[7]=NULL;
		evan->afficher_hero[8]=NULL;

		evan->afficher_herod[0]=NULL;
		evan->afficher_herod[1]=NULL;
		evan->afficher_herod[2]=NULL;
		evan->afficher_herod[3]=NULL;
		evan->afficher_herod[4]=NULL;
		evan->afficher_herod[5]=NULL;
		evan->afficher_herod[6]=NULL;
		evan->afficher_herod[7]=NULL;
		evan->afficher_herod[8]=NULL;


		evan->afficher_hero[0]=IMG_Load("1.png");
		evan->afficher_hero[1]=IMG_Load("2.png");
		evan->afficher_hero[2]=IMG_Load("3.png");
		evan->afficher_hero[3]=IMG_Load("4.png");
		evan->afficher_hero[4]=IMG_Load("5.png");
		evan->afficher_hero[5]=IMG_Load("6.png");
		evan->afficher_hero[6]=IMG_Load("7.png");
		evan->afficher_hero[7]=IMG_Load("8.png");
		evan->afficher_hero[8]=IMG_Load("9.png");

		evan->afficher_herod[0]=IMG_Load("affiched/d1.png");
		evan->afficher_herod[1]=IMG_Load("affiched/d2.png");
		evan->afficher_herod[2]=IMG_Load("affiched/d3.png");
		evan->afficher_herod[3]=IMG_Load("affiched/d4.png");
		evan->afficher_herod[4]=IMG_Load("affiched/d5.png");
		evan->afficher_herod[5]=IMG_Load("affiched/d6.png");
		evan->afficher_herod[6]=IMG_Load("affiched/d7.png");
		evan->afficher_herod[7]=IMG_Load("affiched/d8.png");
		evan->afficher_herod[8]=IMG_Load("affiched/d9.png");
			
		evan->afficher_vie[0]=IMG_Load("vie0.png");
		evan->afficher_vie[1]=IMG_Load("vie1.png");
		evan->afficher_vie[2]=IMG_Load("vie2.png");
		evan->afficher_vie[3]=IMG_Load("vie3.png");
	
	evan->vie=3;

	evan->farm=0;
	evan->hit=0;
	
	evan->pos_hero2.x=0;
	evan->pos_hero2.y=0;
	evan->pos_vie.y=0;
	evan->pos_vie.x=0;
	evan->heromoved=0;

	evan->vx =evan->vy = 0.0f;
}
void afficher_evan(hero evan,SDL_Surface *ecran){
	if ((evan.mouvment==1)||(evan.mouvment==9))
		SDL_BlitSurface(evan.afficher_hero[evan.farm],NULL,ecran,&(evan.pos_hero2));
	if (evan.mouvment==2)
		SDL_BlitSurface(evan.afficher_herod[evan.farm],NULL,ecran,&(evan.pos_hero2));
	if (evan.mouvment==3)//saut
		SDL_BlitSurface(evan.afficher_hero[0],NULL,ecran,&(evan.pos_hero2));
}
