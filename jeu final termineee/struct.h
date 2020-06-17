
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <unistd.h>


typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int frame;
  int direction;
  int died;

}Enemy;

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
typedef struct objet{

	SDL_Surface *afficher_objet;
	SDL_Rect pos_objet;
}objet;

typedef struct effet{

	SDL_Surface *afficher_effet;
	SDL_Rect pos_effets;
}effet;
typedef struct background{

	SDL_Surface *afficher_background;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
}background;

typedef struct enigme
{
	SDL_Rect posenigme; 
	SDL_Surface *background;
	SDL_Surface *hand2;
	SDL_Surface *hand1;
	SDL_Surface *un;
	SDL_Surface *deux;
	SDL_Surface *answer;
	SDL_Surface *rep1;
	SDL_Surface *rep2;
	SDL_Rect poshand1; 
	SDL_Rect poshand2; 
	SDL_Rect posrep1;
	SDL_Rect posrep2; 
	SDL_Rect posun;
	SDL_Rect posdeux;
	SDL_Rect posanswer; 
	SDL_Rect posquiz;
	SDL_Rect reponse;
	int handclose;
	int reponseplayer;
	int scoreenigme;
	int random;
	int rep;
	int reponseplayerstate;
	int enigmeresolu;
} enigme; 
typedef struct menu{
	SDL_Surface *background;
	SDL_Surface *bplay;
	SDL_Surface *beplay;
	SDL_Surface *droit;	
	SDL_Surface *droite;
	SDL_Surface *gauche;
	SDL_Surface *gauchee;
	SDL_Surface *msetting;	
	SDL_Surface *besetting;
	SDL_Surface *bsetting;
	SDL_Surface *bquit;
	SDL_Surface *bequit;
	SDL_Rect positionecran;
	SDL_Rect positionbplay;
	SDL_Rect positiondroit;
	SDL_Rect positiongauche;
	SDL_Surface *sousmenuquit;
	SDL_Rect positionsousmenuquit;

	SDL_Surface *sousmenukey1;
	SDL_Surface *sousmenukey2;
	SDL_Surface *sousmenuoff1;
	SDL_Surface *sousmenuoff2;
	SDL_Surface *sousmenuon1;
	SDL_Surface *sousmenuon2;
	SDL_Surface *sousmenucont1;
	SDL_Surface *sousmenucont2;
	SDL_Rect positionsouskey;
	SDL_Rect positionsousoff;
	SDL_Rect positionsouson;
	SDL_Rect positionsouscont;
	int sousetatsound;
	int sousetatcontrole;

	int action;
	int boutoneffet;
	int po;
	Mix_Music *son;	
	
} menu;
typedef struct pmap{
	int nbmoved;
	SDL_Surface *afficher_pmap;
	SDL_Rect pos_pmap;
	SDL_Surface *afficher_pperso;
	SDL_Rect pos_pperso;
}pmap;

typedef struct enigme2{

	SDL_Surface *afficher_enigme2;
	SDL_Rect pos_enigme2;
	SDL_Surface *calque_enigme2;
	SDL_Surface *imggameover;
	int x;
	int y;
	int color;
	int start;
	int lost ;
}enigme2;


	void initialiser_enigme2(enigme2 *enig2);
	void afficher_enigme2(enigme2 enig2, SDL_Surface *ecran);
	void resolution_enigme2(enigme2 *enig2,SDL_Surface *ecran);

	int affcihiersousmenuingame(menu *menu,SDL_Surface *ecran);
	void afficher_sousmenuingame(menu *menu,SDL_Surface *ecran,int x,int y);

	void initialiser_pmap(pmap *pmap);
	void afficher_pmap(pmap *pmap,SDL_Surface *ecran,int mouvment);

	void affichiervie(hero evan, SDL_Surface *ecran);
	int gestionvie(hero *evan,SDL_Surface *ecran);

	int controle_menu ();
	void initialiser_menu(menu *menu);
	int affcihier(menu *menu,SDL_Surface *ecran);
	void affichier_quit(menu *menu,SDL_Surface *ecran,int x,int y);
	void afficher_setting(menu *menu,SDL_Surface *ecran,int x,int y);

	void initialiser_background(background *bckg);
 	void afficher_background(background bckg,SDL_Surface *ecran);
	void initialiser_evan(hero *evan);
	void afficher_evan(hero evan,SDL_Surface *ecran);
	
	void scrolling (hero *evan,background *bckg, int co);
	int animation_perso(hero evan);
	int mouvment(hero evan,SDL_Event *event);
	void initialiser_objet(objet *chouka);
	void afficher_objet(objet *chouka,SDL_Surface *ecran, hero evan);

	void affichier_enigme(enigme *enig,SDL_Surface *ecran);
	void writeqs(SDL_Surface *ecran);
	void resenigme(enigme *enig,SDL_Surface *ecran);
	void randomquiz(enigme *enig);
	int correctrep(enigme *enig,char nom_fichier[]);
	int verifenig(enigme *enig);
	int Collision_Bounding_Box (hero evan ,objet chouka );

	Enemy InitEnemy(Enemy Ennemie,int x, int y);
	void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
	Enemy AnimateEnemy(Enemy Ennemie,int stat);
	Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment);

	int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);

	void initialiser_effet(effet *fly);
	void afficher_effet(effet *fly,SDL_Surface *ecran);

	int mouvmentarduino(hero evan,FILE *f);

	Enemy diedennemie(Enemy Ennemie,int coe);

	int collision_Parfaiteennemie(SDL_Surface *calque,SDL_Rect posennemie,SDL_Rect posmap);


	void sauvegarde (char fich[]);


	void initialiser_backgroundm(background *bckgm1 , background *bckgm2);
	void afficher_backgroundm(background bckgm1,background bckgm2 ,SDL_Surface *ecran);
	void initialiser_evanm(hero *evan1,hero *evan2);
	void afficher_evanm(hero evan1,hero evan2,SDL_Surface *ecran);
	//void scrollingm(hero *evan,background *bckg,int co );
	void scrollingm1(hero *evan,background *bckg,int co );
	void scrollingm2(hero *evan,background *bckg,int co );
	int collision_Parfaitem1(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
	int collision_Parfaitem2(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
	SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
	extern hero evan;
	extern Enemy Ennemie;
	extern background bckg;
	/*extern pmap pmap;*/

#endif
