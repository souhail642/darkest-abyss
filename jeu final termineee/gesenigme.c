#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include"struct.h"
void randomquiz(enigme *enig){

	srand(time(NULL)); 
	enig->random=1;//(rand()%3+1);  
}
int correctrep(enigme *enig,char nom_fichier[]){
	char qs[6];					
	char qs2[6]; 
		FILE* f=NULL;
		f=fopen(nom_fichier,"r");
		sprintf(qs2,"quiz%d",enig->random);
		if(f!=NULL){
			do{
				fscanf(f,"%s %d",qs,&enig->reponseplayer);
			}while(((enig->reponseplayer!= EOF)&&(strcmp(qs2,qs))!=0));
		fclose(f);
	}
	printf("%d\n",enig->reponseplayer);
	return enig->reponseplayer;
}
