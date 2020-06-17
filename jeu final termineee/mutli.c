#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
 
void initialiser_backgroundm(background *bckgm1 , background *bckgm2){


	bckgm1->calque_background=NULL;
	bckgm1->calque_background=IMG_Load("calquebackground.png");

	bckgm1->afficher_background=NULL;
	bckgm1->afficher_background=IMG_Load("background.jpg");
	bckgm1->pos_background.x=0;
	bckgm1->pos_background.y=0;
	bckgm1->pos_background2.x=0;
	bckgm1->pos_background2.y=0;
	bckgm1->pos_background2.h=600;
	bckgm1->pos_background2.w=600;


	bckgm2->calque_background=NULL;
	bckgm2->calque_background=IMG_Load("calquebackground.png");

	bckgm2->afficher_background=NULL;
	bckgm2->afficher_background=IMG_Load("background.jpg");
	bckgm2->pos_background.x=601;
	bckgm2->pos_background.y=0;
	bckgm2->pos_background2.x=0;
	bckgm2->pos_background2.y=0;
	bckgm2->pos_background2.h=600;
	bckgm2->pos_background2.w=600;
	
	
}
void afficher_backgroundm(background bckgm1,background bckgm2 ,SDL_Surface *ecran){
	
	SDL_BlitSurface(bckgm1.afficher_background,&(bckgm1.pos_background2),ecran,&(bckgm1.pos_background));
	SDL_BlitSurface(bckgm2.afficher_background,&(bckgm2.pos_background2),ecran,&(bckgm2.pos_background));




}
void initialiser_evanm(hero *evan1,hero *evan2){
		
		evan1->afficher_hero[0]=NULL;
		evan1->afficher_hero[1]=NULL;
		evan1->afficher_hero[2]=NULL;
		evan1->afficher_hero[3]=NULL;
		evan1->afficher_hero[4]=NULL;
		evan1->afficher_hero[5]=NULL;
		evan1->afficher_hero[6]=NULL;
		evan1->afficher_hero[7]=NULL;
		evan1->afficher_hero[8]=NULL;

		evan1->afficher_herod[0]=NULL;
		evan1->afficher_herod[1]=NULL;
		evan1->afficher_herod[2]=NULL;
		evan1->afficher_herod[3]=NULL;
		evan1->afficher_herod[4]=NULL;
		evan1->afficher_herod[5]=NULL;
		evan1->afficher_herod[6]=NULL;
		evan1->afficher_herod[7]=NULL;
		evan1->afficher_herod[8]=NULL;


		evan1->afficher_hero[0]=IMG_Load("1.png");
		evan1->afficher_hero[1]=IMG_Load("2.png");
		evan1->afficher_hero[2]=IMG_Load("3.png");
		evan1->afficher_hero[3]=IMG_Load("4.png");
		evan1->afficher_hero[4]=IMG_Load("5.png");
		evan1->afficher_hero[5]=IMG_Load("6.png");
		evan1->afficher_hero[6]=IMG_Load("7.png");
		evan1->afficher_hero[7]=IMG_Load("8.png");
		evan1->afficher_hero[8]=IMG_Load("9.png");

		evan1->afficher_herod[0]=IMG_Load("affiched/d1.png");
		evan1->afficher_herod[1]=IMG_Load("affiched/d2.png");
		evan1->afficher_herod[2]=IMG_Load("affiched/d3.png");
		evan1->afficher_herod[3]=IMG_Load("affiched/d4.png");
		evan1->afficher_herod[4]=IMG_Load("affiched/d5.png");
		evan1->afficher_herod[5]=IMG_Load("affiched/d6.png");
		evan1->afficher_herod[6]=IMG_Load("affiched/d7.png");
		evan1->afficher_herod[7]=IMG_Load("affiched/d8.png");
		evan1->afficher_herod[8]=IMG_Load("affiched/d9.png");
			
		evan1->afficher_vie[0]=IMG_Load("vie0.png");
		evan1->afficher_vie[1]=IMG_Load("vie1.png");
		evan1->afficher_vie[2]=IMG_Load("vie2.png");
		evan1->afficher_vie[3]=IMG_Load("vie3.png");
	
		evan1->vie=3;

		evan1->farm=0;
		evan1->hit=0;
	
		evan1->pos_hero2.x=0;
		evan1->pos_hero2.y=0;
		evan1->pos_vie.y=0;
		evan1->pos_vie.x=0;
		evan1->heromoved=0;

	evan1->vx =evan1->vy = 0.0f;



			evan2->afficher_hero[0]=NULL;
		evan2->afficher_hero[1]=NULL;
		evan2->afficher_hero[2]=NULL;
		evan2->afficher_hero[3]=NULL;
		evan2->afficher_hero[4]=NULL;
		evan2->afficher_hero[5]=NULL;
		evan2->afficher_hero[6]=NULL;
		evan2->afficher_hero[7]=NULL;
		evan2->afficher_hero[8]=NULL;

		evan2->afficher_herod[0]=NULL;
		evan2->afficher_herod[1]=NULL;
		evan2->afficher_herod[2]=NULL;
		evan2->afficher_herod[3]=NULL;
		evan2->afficher_herod[4]=NULL;
		evan2->afficher_herod[5]=NULL;
		evan2->afficher_herod[6]=NULL;
		evan2->afficher_herod[7]=NULL;
		evan2->afficher_herod[8]=NULL;


		evan2->afficher_hero[0]=IMG_Load("1.png");
		evan2->afficher_hero[1]=IMG_Load("2.png");
		evan2->afficher_hero[2]=IMG_Load("3.png");
		evan2->afficher_hero[3]=IMG_Load("4.png");
		evan2->afficher_hero[4]=IMG_Load("5.png");
		evan2->afficher_hero[5]=IMG_Load("6.png");
		evan2->afficher_hero[6]=IMG_Load("7.png");
		evan2->afficher_hero[7]=IMG_Load("8.png");
		evan2->afficher_hero[8]=IMG_Load("9.png");

		evan2->afficher_herod[0]=IMG_Load("affiched/d1.png");
		evan2->afficher_herod[1]=IMG_Load("affiched/d2.png");
		evan2->afficher_herod[2]=IMG_Load("affiched/d3.png");
		evan2->afficher_herod[3]=IMG_Load("affiched/d4.png");
		evan2->afficher_herod[4]=IMG_Load("affiched/d5.png");
		evan2->afficher_herod[5]=IMG_Load("affiched/d6.png");
		evan2->afficher_herod[6]=IMG_Load("affiched/d7.png");
		evan2->afficher_herod[7]=IMG_Load("affiched/d8.png");
		evan2->afficher_herod[8]=IMG_Load("affiched/d9.png");
			
		evan2->afficher_vie[0]=IMG_Load("vie0.png");
		evan2->afficher_vie[1]=IMG_Load("vie1.png");
		evan2->afficher_vie[2]=IMG_Load("vie2.png");
		evan2->afficher_vie[3]=IMG_Load("vie3.png");
	
		evan2->vie=3;

		evan2->farm=0;
		evan2->hit=0;
	
		evan2->pos_hero2.x=600;
		evan2->pos_hero2.y=0;
		evan2->pos_vie.y=0;
		evan2->pos_vie.x=0;
		evan2->heromoved=0;

		evan2->vx =evan2->vy = 0.0f;



}
void afficher_evanm(hero evan1,hero evan2,SDL_Surface *ecran){
	if ((evan1.mouvment==1)||(evan1.mouvment==9))
		SDL_BlitSurface(evan1.afficher_hero[evan1.farm],NULL,ecran,&(evan1.pos_hero2));
	if (evan1.mouvment==2)
		SDL_BlitSurface(evan1.afficher_herod[evan1.farm],NULL,ecran,&(evan1.pos_hero2));
	if (evan1.mouvment==3)
		SDL_BlitSurface(evan1.afficher_hero[0],NULL,ecran,&(evan1.pos_hero2));


	if ((evan2.mouvment==1)||(evan2.mouvment==9))
		SDL_BlitSurface(evan2.afficher_hero[evan2.farm],NULL,ecran,&(evan2.pos_hero2));
	if (evan2.mouvment==2)
		SDL_BlitSurface(evan2.afficher_herod[evan2.farm],NULL,ecran,&(evan2.pos_hero2));
	if (evan2.mouvment==3)
		SDL_BlitSurface(evan2.afficher_hero[0],NULL,ecran,&(evan2.pos_hero2));
}
void scrollingm1(hero *evan,background *bckg,int co)
{
	 evan->heromoved=0;
	switch(evan->mouvment)
	{

		case 1: 
			if (co!=2){
			if ((bckg->pos_background2.x<6800)&&(evan->pos_hero2.x>=150))
                		bckg->pos_background2.x=bckg->pos_background2.x+5;
			if (((evan->pos_hero2.x<150)||((bckg->pos_background2.x>=6800))&&(evan->pos_hero2.x<550)))
				evan->pos_hero2.x=evan->pos_hero2.x+5;
			evan->heromoved=1;
		}
	
		break;
		case 2:
		if (co!=2){
			if (bckg->pos_background2.x>0)
                		bckg->pos_background2.x=bckg->pos_background2.x-5;
	    		if (((bckg->pos_background2.x!=0)&&(evan->pos_hero2.x>=150))||((bckg->pos_background2.x==0)&&(evan->pos_hero2.x=50)))
				evan->pos_hero2.x=evan->pos_hero2.x-5;
			    evan->heromoved=2;
			}	
		break;
		case 3:

		if (evan->pos_hero2.y>50){
			if (bckg->pos_background2.x<6800){
				evan->pos_hero2.y=evan->pos_hero2.y-20;

			}
		}
		break;
	}
	if ((evan->mouvment!=3)&&(co!=10)&&(co!=2)){
		evan->pos_hero2.y=evan->pos_hero2.y+5;
	}
}
void scrollingm2(hero *evan,background *bckg,int co )
{
	 evan->heromoved=0;
	switch(evan->mouvment)
	{

		case 1: 
			if (co!=2){
			if ((bckg->pos_background2.x<6800)&&(evan->pos_hero2.x>=700))
                		bckg->pos_background2.x=bckg->pos_background2.x+5;
			if (((evan->pos_hero2.x<700)||((bckg->pos_background2.x>=6800))&&(evan->pos_hero2.x<1100)))
				evan->pos_hero2.x=evan->pos_hero2.x+5;
			evan->heromoved=1;
		}
	
		break;
		case 2:
		if (co!=2){
			if (bckg->pos_background2.x>0)
                		bckg->pos_background2.x=bckg->pos_background2.x-5;
	    		if (((bckg->pos_background2.x!=0)&&(evan->pos_hero2.x>=750))||((bckg->pos_background2.x==0)&&(evan->pos_hero2.x=650)))
				evan->pos_hero2.x=evan->pos_hero2.x-5;
			    evan->heromoved=2;
			}	
		break;
		case 3:

		if (evan->pos_hero2.y>50){
			if (bckg->pos_background2.x<6800){
				evan->pos_hero2.y=evan->pos_hero2.y-20;

			}
		}
		break;
	}
	if ((evan->mouvment!=3)&&(co!=10)&&(co!=2)){
		evan->pos_hero2.y=evan->pos_hero2.y+5;
	}
}
int collision_Parfaitem2(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col,col2,col22,col1;
  //if(d==0)//imin
  //{
	col=GetPixel(calque,posperso.x+100+posmap.x-600,posperso.y+220);
	col2=GetPixel(calque,posperso.x+50+posmap.x-600,posperso.y+230);
	col22=GetPixel(calque,posperso.x+100+posmap.x-600,posperso.y+180);
	col1=GetPixel(calque,posperso.x+100+posmap.x-600,posperso.y+220);

  //}
//else  if(d==1)
  //{
   // col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  //}
//else  if(d==2)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2)+ posmap ,posperso.y);
  //}
//else  if(d==3)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h );
 // }
   printf("%d    %d   /////////// \n",posperso.x+100+posmap.x+601,posperso.y+220 );
  printf("%d    %d   %d\n",col.r,col.b,col.g );
  //SDL_Delay(250);
if ((col.r==0)&&(col.b==0)&&(col.g==255))
  return 1;//7ofra
else if ((col22.r==0)&&(col22.b==0)&&(col22.g==0))
  return 2;//obstacle
else if ((col1.r==0)&&(col1.b==255)&&(col1.g==0))
  return 1;//choukakbira
else if ((col22.r==255)&&(col22.b==0)&&(col22.g==0))
  return 3;//door enigme
else if ((col2.r==0)&&(col2.b==0)&&(col2.g==0))
 return 10;//9a3
else
{
	return 0;
}
}
int collision_Parfaitem1(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col,col2,col22,col1;
  //if(d==0)//imin
  //{
	col=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+220);
	col2=GetPixel(calque,posperso.x+50+posmap.x,posperso.y+230);
	col22=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+180);
	col1=GetPixel(calque,posperso.x+100+posmap.x,posperso.y+220);

  //}
//else  if(d==1)
  //{
   // col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  //}
//else  if(d==2)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2)+ posmap ,posperso.y);
  //}
//else  if(d==3)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h );
 // }
   printf("%d    %d   /////////// \n",posperso.x+100+posmap.x+601,posperso.y+220 );
  printf("%d    %d   %d\n",col.r,col.b,col.g );
  //SDL_Delay(250);
if ((col.r==0)&&(col.b==0)&&(col.g==255))
  return 1;//7ofra
else if ((col22.r==0)&&(col22.b==0)&&(col22.g==0))
  return 2;//obstacle
else if ((col1.r==0)&&(col1.b==255)&&(col1.g==0))
  return 1;//choukakbira
else if ((col22.r==255)&&(col22.b==0)&&(col22.g==0))
  return 3;//door enigme
else if ((col2.r==0)&&(col2.b==0)&&(col2.g==0))
 return 10;//9a3
else
{
	return 0;
}
}