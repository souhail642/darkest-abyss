#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include"struct.h"

void sauvegarde (char fich[20])
{
	int i;
	FILE *f;
	
	f=fopen(fich,"wb");
	fwrite(&evan,sizeof(hero),1,f);
	//fwrite(&chouka,sizeof(objet),1,f);
	//fwrite(&background,sizeof(bckg),1,f);
	fwrite(&pmap,sizeof(pmap),1,f);
	//fwrite(&Enemy,sizeof(e),1,f);
	fclose(f);
	
}

/*void lire (char fich[20])
{
	int i;
	FILE *f;
	
	f=fopen(fich,"rb");
	if (f==NULL)
	{
		printf("erreur, fichier ne peut pas etre ouvert\n");
		exit(0);
	}
	
	else
	{
		fread(&jeu.nbre_ennemis,sizeof(int),1,f);
		fread(&jeu.nbre_etoiles,sizeof(int),1,f);
		for (i=0;i<jeu.nbre_etoiles;i++)
		{
			fread(&etoile[i],sizeof(Etoile),1,f);
		}
		
		fread(&jonathan,sizeof(Hero),1,f);
	
		for (i=0;i<jeu.nbre_ennemis;i++)
		{
			fread(&ennemi[i],sizeof(Hero),1,f);
		}
	}
	
	fclose(f);
}*/