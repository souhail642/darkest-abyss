#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"struct.h"
void main(void)
{


	 char chemin[]="/dev/ttyACM0";
    FILE *f;
     f=fopen(chemin,"r");
	SDL_Surface *ecran =NULL,*gameover=NULL;
	hero evan,evan1,evan2 ;
	int continuer =1;
	objet chouka;
	enigme enig;
	background bckg;
	int k,a;
	int continuerenig=1;
	menu menu;
	effet fly;
	int coe;
	int c,co1,co2;
	enigme2 enig2;
	background bckgm1,bckgm2;
	pmap pmap;
	enig.enigmeresolu=0;
	//int i;
	SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    initialiser_background(&bckg);
    initialiser_evan(&evan);
   initialiser_objet(&chouka);
	initialiser_effet(&fly);
   initialiser_menu(&menu);
   int enigmeresolu2=0;
    SDL_Event event;
	gameover=IMG_Load("gameover.png");
   evan.farm=0;
   Enemy e;
   int stat;
   initialiser_pmap(&pmap);
   initialiser_backgroundm(&bckgm1,&bckgm2);
   initialiser_evanm(&evan1,&evan2);
	initialiser_enigme2(&enig2);
   e=InitEnemy(e,5500,350);
    //usleep(20000000);
	while(continuer){
		printf("%d\n",evan.mouvment);
		if (menu.action==1){
			 k=affcihier(&menu,ecran);

			 SDL_Flip(ecran);
		}
		//SDL_Flip(ecran);
		if(menu.action==10){

			afficher_background(bckg,ecran);
			afficher_evan(evan,ecran);
			evan.farm=animation_perso(evan);
			afficher_objet(&chouka,ecran,evan);
			afficher_pmap(&pmap,ecran,evan.heromoved);
		
			e=MoveEnemy(e,evan.pos_hero2,&stat,evan.heromoved);
			e=AnimateEnemy(e,stat);
			 AfficherEnemy(e,ecran);

			
			//printf("%d a\n",bckg.pos_background2.x);
			if (c==1)
				evan.hit=1;
			gestionvie(&evan,ecran);
			affichiervie(evan,ecran);
			//affichiervie(evan,ecran);
			SDL_Flip(ecran);
			if(Collision_Bounding_Box (evan,chouka )==0){
				evan.hit=1;
				chouka.pos_objet.y=1000;
				SDL_Delay(1000);
			}
			coe=collision_Parfaiteennemie(bckg.calque_background,e.position,bckg.pos_background2);
			e=diedennemie(e,coe);
			if ((e.imageActuel==e.Hit)&&(e.died==0)){
				evan.hit=1;

				e.position.x=e.position.x+100;
			}
			if (menu.sousetatcontrole==1){
				evan.mouvment= mouvment(evan,&event);
			}
			if (menu.sousetatcontrole==2){
				evan.mouvment=mouvmentarduino(evan,f);
			}
			if (evan.mouvment==0){
				continuer=0;
			}
			if (evan.mouvment==100){
				menu.action=100;
				}
				scrolling(&evan,&bckg,c);
			
			
			if ((enigmeresolu2==0)&&(bckg.pos_background2.x==50)){
				enigmeresolu2==1;
					while(continuerenig){
						afficher_enigme2(enig2,ecran);
 						resolution_enigme2(&enig2,ecran);
 						if (enig2.lost==1){
 							evan.hit=1;
 							continuerenig=0;
 						}
 						if (enig2.lost==2){

 							break;

 						}
 						SDL_Flip(ecran);

						}
			}
			
			if ((c==3)&&(enig.enigmeresolu==0)){
				resenigme(&enig,ecran);
				enig.enigmeresolu=1;	
			}
				//printf("%d\n",enig.reponseplayerstate);
				c=collision_Parfaite(bckg.calque_background,evan.afficher_hero[evan.farm],evan.pos_hero2,bckg.pos_background2);
//printf("%d  cc\n",a);
		if (evan.vie==0){
			SDL_BlitSurface(gameover,NULL,ecran,&bckg.pos_background);
			SDL_Flip(ecran);
			usleep(3000000);
			menu.action=1;
		initialiser_background(&bckg);
    	initialiser_evan(&evan);
   		initialiser_objet(&chouka);
		initialiser_effet(&fly);
	}
	if (evan.mouvment==3){
		fly.pos_effets.x=evan.pos_hero2.x+20;
		fly.pos_effets.y=evan.pos_hero2.y+240;
		afficher_effet(&fly,ecran);
		fly.pos_effets.x=evan.pos_hero2.x+50;
		fly.pos_effets.y=evan.pos_hero2.y+240;
		afficher_effet(&fly,ecran);
		SDL_Flip(ecran);
		
	}
	SDL_Delay(20);
		}
	if (menu.action==11){

			//initialiser_backgroundm(&bckgm1,&bckgm2);
			afficher_backgroundm(bckgm1,bckgm2,ecran);
			afficher_evanm(evan1,evan2,ecran);
			co1=collision_Parfaitem1(bckgm1.calque_background,evan1.afficher_hero[evan.farm],evan1.pos_hero2,bckgm1.pos_background2);
			co2=collision_Parfaitem2(bckgm2.calque_background,evan2.afficher_hero[evan.farm],evan2.pos_hero2,bckgm2.pos_background2);
			SDL_Flip(ecran);
			evan1.farm=animation_perso(evan1);
			evan2.farm=animation_perso(evan2);
			evan1.mouvment=mouvment(evan1,&event);
			scrollingm1(&evan1,&bckgm1,co1 );
			evan2.mouvment=mouvmentarduino(evan2,f);
			scrollingm2(&evan2,&bckgm2,co2 );
		
			printf("%d %d \n",co1,co2);
			//scrollingm1(&evan1,&bckgm1,co1 );
			//scrollingm2(&evan,&bckgm2,co2 );
			SDL_Flip(ecran);

	}
	if (menu.action==100){

		menu.action=affcihiersousmenuingame(&menu,ecran);
		SDL_Flip(ecran);
		//evan.mouvment=9;
		SDL_Delay(19);
	}

		if(menu.action==0)	{
			//sauvegarde ("sauvegarde.bin");
			continuer=0;
		}
	}
	fclose(f);
}
