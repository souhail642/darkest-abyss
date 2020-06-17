#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
#include <time.h>
void writeqs(SDL_Surface *ecran){

	char qus[70]="To get the key u have to put the right answer in the blank";
	SDL_Color color;
		color.r = 255 ;
        color.g = 255 ;
        color.b = 255 ;
	TTF_Font *font = NULL;
	TTF_Init();
	SDL_Rect posqus;	
	posqus.x=200;
	posqus.y=460; 
	SDL_Surface *message;
	font=TTF_OpenFont("Comic_Sans_MS_Bold.ttf",17);
	message= TTF_RenderText_Solid(font,qus,color);
	SDL_BlitSurface	(message,NULL,ecran,&posqus);
	TTF_Quit();
}
int verifenig(enigme *enig){

	if (enig->reponseplayer==1){
		if ((enig->posrep1.x>=385)&&(enig->posrep1.x<=535)&&(enig->posrep1.y>=180)&&(enig->posrep1.y<=330))
			return 1;
		else 
			return 0;
	}
	else{
		if ((enig->posrep2.x>=385)&&(enig->posrep2.x<=535)&&(enig->posrep2.y>=180)&&(enig->posrep2.y<=330))
			return 1;
		else 
			return 0;
	}

}
void affichier_enigme(enigme *enig,SDL_Surface *ecran){

	int con=1;
	int x,y;
	char nom_fichier[]="quiz.txt";
	enig->handclose=0;
	int k=0;
	enig->rep=2;
	SDL_Event event;
	char qs[50],rep1[50],rep2[50],un[50],deux[50],answer1[50];
	randomquiz(enig);
	sprintf(qs,"quiz/quiz%d/qs.png",enig->random);
	sprintf(rep1,"quiz/quiz%d/rp1.png",enig->random);
	sprintf(rep2,"quiz/quiz%d/rp2.png",enig->random);
	sprintf(un,"quiz/quiz%d/1.png",enig->random);
	sprintf(deux,"quiz/quiz%d/2.png",enig->random);
	sprintf(answer1,"quiz/quiz%d/answer.png",enig->random);
	

	enig->background =IMG_Load(qs);
	enig->hand1 =IMG_Load("hand1.png");
	enig->hand2 =IMG_Load("hand2.png");
	
	enig->un =IMG_Load(un);
	enig->deux =IMG_Load(deux);
	enig->answer=IMG_Load(answer1);
	

	enig->rep1=IMG_Load(rep1);
	enig->rep2=IMG_Load(rep2);
	

	enig->poshand1.x=450;
	enig->poshand1.y=450;
	
	enig->poshand2.x=0;
	enig->poshand2.y=0;

	
	enig->posquiz.x=0;
	enig->posquiz.y=0;

	enig->posrep1.x=181;
	enig->posrep1.y=245;

	enig->posrep2.x=603;
	enig->posrep2.y=243;

	enig->posun.x=377;
	enig->posun.y=367;

	enig->posdeux.x=508;
	enig->posdeux.y=368;

	enig->posanswer.x=445;
	enig->posanswer.y=110;

	
	while(con){
		SDL_WaitEvent(&event);
		switch (event.type)
        	{
        		case SDL_QUIT:
            			con=0;
            		break;
        	
        		case SDL_MOUSEBUTTONUP:
				if (enig->handclose==1){	
					enig->handclose=0;
					enig->rep=1;
					
				}
				else{
					enig->handclose=1;
					enig->rep=0;
				}
			break;
		}

		//printf("%d,%d\n",x,y);

		SDL_BlitSurface(enig->background,NULL,ecran,&(enig->posquiz));
		SDL_BlitSurface(enig->rep1,NULL,ecran,&(enig->posrep1));
		SDL_BlitSurface(enig->rep2,NULL,ecran,&(enig->posrep2));
		SDL_BlitSurface(enig->answer,NULL,ecran,&(enig->posanswer));
		SDL_BlitSurface(enig->un,NULL,ecran,&(enig->posun));
		SDL_BlitSurface(enig->deux,NULL,ecran,&(enig->posdeux));
		
		
		writeqs(ecran);
		if (enig->handclose==1){
			SDL_BlitSurface(enig->hand2,NULL,ecran,&(enig->poshand2));
			k=1;
		}
	
		else {
			SDL_BlitSurface(enig->hand1,NULL,ecran,&(enig->poshand1));
			k=0;
		}

		if ((k==1)&&(enig->posrep1.x<=x)&&(x<=enig->posrep1.x+125)&&(y<=enig->posrep1.y+125)&&(enig->posrep1.y<=y))
			enig->posrep1=enig->poshand2;
		if ((k==1)&&(enig->posrep2.x<=x)&&(x<=enig->posrep2.x+125)&&(y<=enig->posrep2.y+125)&&(enig->posrep2.y<=y))
			enig->posrep2=enig->poshand2;
		
		if (enig->rep==1){
				correctrep(enig,nom_fichier);
				enig->reponseplayerstate=verifenig(enig);
				con=0;
				printf("%d\n", enig->reponseplayerstate);
		}

			
				
		SDL_GetMouseState(&x,&y);
		 SDL_Flip(ecran);
		enig->poshand2.x=x-30;
		enig->poshand2.y=y-20;
		
		enig->poshand1.x=x-30;
		enig->poshand1.y=y-20;
		
		
	}	
}
void resenigme(enigme *enig,SDL_Surface *ecran){
	
	
		affichier_enigme(enig,ecran);
		SDL_Rect xp;
		SDL_Surface *image;
		image=IMG_Load("gameover.png");
		xp.x=0;
		xp.y=0;
		
		if  (enig->reponseplayerstate==1){
			enig->scoreenigme=1;	
		}	
		else { 
			enig->scoreenigme=0;
			SDL_BlitSurface(image,NULL,ecran,&xp);
			SDL_Flip(ecran);
			usleep(3000000);
			
		}
}
