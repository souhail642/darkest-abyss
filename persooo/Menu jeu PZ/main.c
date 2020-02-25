#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


void main()

{

    SDL_Surface *ecran = NULL, *image = NULL, *play = NULL,*option = NULL,*credit = NULL,*quit = NULL;
	char animation[20];
    int frame = 0;
    int x1;int y1;
  int m1=1;



    SDL_Rect positionFond,positionClic,positionoption,positioncredit,positionquit;

    positionFond.x = 0;
    positionFond.y = 0;

positionClic.x=640;
positionClic.y=150;

positionoption.x=640;
positionoption.y=220;

positioncredit.x=640;
positioncredit.y=290;

positionquit.x=640;
positionquit.y=360;

 ecran = SDL_SetVideoMode(1169, 813, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
image= IMG_Load("A.jpg");
option= IMG_Load("option 1.png");
play= IMG_Load("play 2.png");
credit=IMG_Load("credit 1.png");
quit=IMG_Load("quit 1.png");
option= IMG_Load("option 2.png");
play= IMG_Load("play 1.png");
credit=IMG_Load("credit 2.png");
quit=IMG_Load("quit 2.png");
SDL_BlitSurface(image, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);

        SDL_Flip(ecran);

    SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
    
TTF_Font *fontTest;
fontTest=TTF_OpenFont("DUSTY RANCH PERSONAL USE.ttf",90);
SDL_Color fontColor={0,155,155};
SDL_Surface *text;
text=TTF_RenderText_Solid(fontTest,"the darkest abyss",fontColor);
SDL_Rect texTPosition;
texTPosition.x=50;
texTPosition.y=40;
SDL_BlitSurface(text, NULL, ecran, &texTPosition);
SDL_Flip(ecran);

    Mix_OpenAudio (22050,MIX_DEFAULT_FORMAT,2,4096);
Mix_Music * music;
music =Mix_LoadMUS("musika.mp3");
Mix_PlayMusic(music,-1);//repetion de la musique en  boucle
   // ecran = SDL_SetVideoMode(900, 644, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) 
   {
      printf("%s", Mix_GetError());
   }
   Mix_AllocateChannels(32); 
   Mix_Chunk *son;
   son = Mix_LoadWAV("PING.wav");


    int i=1,x=1;

    int continuer = 1;
    //bool done;
    SDL_Event event;
   
    while (continuer)
    {
        x=0;
        SDL_WaitEvent(&event);
switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
 case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {

            case SDLK_UP:

                if (i==1)
                    i=4;

                else


                    i--;
                break;
		case SDLK_RETURN:
if( i ==4 ){continuer = 0;}
if (i==2)
                    { m1=0;
option= IMG_Load("bouton11.png");
                     play= IMG_Load("bouton22.png");
                     credit=IMG_Load("bouton33.png");
                     quit=IMG_Load("bouton44.png");
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);}



break;

            case SDLK_DOWN:


                if(i==4)
                    i=1;

                else



                    i++;
                break;

            
                    
                      
}
                     case SDL_MOUSEBUTTONUP:
                     switch(event.button.button)
                   { case SDL_BUTTON_LEFT: 
                     {x1=event.button.x;
                     y1=event.button.y;} 
                     break;
                                      
                  }

if ((x1>640)&&(x1<640+230)&&(y1>150)&&(y1<150+65))
{i=1;}


if ((x1>640)&&(x1<640+230)&&(y1>220)&&(y1<220+65))
{i=2;}

  
if ((x1>640)&&(x1<640+230)&&(y1>290)&&(y1<290+65))
{i=3;}

 
if ((x1>640)&&(x1<640+230)&&(y1>360)&&(y1<360+65))
{i=4;}
   image= IMG_Load("A.jpg");
     if(i==1)
        {
            play= IMG_Load("play 2.png");
option= IMG_Load("option 1.png");
quit = IMG_Load("quit 1.png");
credit = IMG_Load("credit 1.png");
Mix_PlayChannel(1,son,0);
        }

        if(i==2 && m1==1)
        {
play= IMG_Load("play 1.png");

quit = IMG_Load("quit 1.png");
credit = IMG_Load("credit 1.png");
            option= IMG_Load("option 2.png");
Mix_PlayChannel(1,son,0);
        }
        if(i==4 )
        {
play= IMG_Load("play 1.png");

Mix_PlayChannel(1,son,0);
credit = IMG_Load("credit 1.png");
            option= IMG_Load("option 1.png");
            quit = IMG_Load("quit 2.png");

        }
        if(i==3)
        {
play= IMG_Load("play 1.png");


Mix_PlayChannel(1,son,0);
            option= IMG_Load("option 1.png");
            quit = IMG_Load("quit 1.png");

            credit = IMG_Load("credit 2.png");


        }
}



        //les images des boutons
sprintf(animation,"sou/%d.jpg",frame);
SDL_FreeSurface(image);
frame++; 	
 image= IMG_Load(animation);  
if(frame==4){
frame =0;}  

        SDL_BlitSurface(image, NULL, ecran, &positionFond);
SDL_BlitSurface(play, NULL, ecran, &positionClic);
SDL_BlitSurface(option, NULL, ecran, &positionoption);
SDL_BlitSurface(credit, NULL, ecran, &positioncredit);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);
SDL_BlitSurface(text, NULL, ecran, &texTPosition);
        SDL_Flip(ecran);


        //aprés apuis des boutons

        }
        
        

    SDL_FreeSurface(image);
    SDL_FreeSurface(play);
SDL_FreeSurface(option);
  SDL_FreeSurface(credit);
 SDL_FreeSurface(quit);
    SDL_Quit();
    return;           
}
