#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"struct.h"

	void initialiser_background(background *bckg);
	void afficher_background(background *bckg,SDL_Surface *ecran);
	void scrolling (hero *evan,background *bckg);
#endif
