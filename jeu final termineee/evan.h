#ifndef EVAN_H_INCLUDED
#define EVAN_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <time.h>
#include<SDL/SDL_ttf.h>
#include <unistd.h>


typedef struct hero
{
	int mouvment;
	SDL_Rect pos_hero[9];
	SDL_Surface *afficher_hero[9];
	SDL_Surface *afficher_herod[9];
	SDL_Rect pos_hero2;
	int farm;
	int vie;
	SDL_Surface *afficher_vie[3];
	int score;
	SDL_Surface *afficher_score;
	SDL_Rect pos_vie;
	int hit;
	int heromoved;

	float vx;
	float vy;
	float x;
	float y;
	
}hero;
	 void initialiser_evan(hero *evan);
	 void afficher_evan(hero *evan,SDL_Surface *ecran);
#endif