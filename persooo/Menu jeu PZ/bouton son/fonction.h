#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h> //bibliiothèque SDL
#include <SDL/SDL_image.h>//bibliiothèque SDL_image
#include <SDL/SDL_mixer.h>//bibliiothèque SDL_mixer
#include <SDL/SDL_ttf.h>//bibliiothèque SDL_ttf
#include "defines.h"
#include "player.h"
#include "Enemie.h"
#include "level1.h"
#include "score.h"
#include "bullet.h"
#include "input.h"
#include "collision.h"

void confirm(SDL_Surface *ecran);
int sortir(int i);
void option(SDL_Surface *ecran);
extern void gamef();

#endif //FONCTIONS_H_INCLUDED