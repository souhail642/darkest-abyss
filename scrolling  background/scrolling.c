#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>



#define SCREEN_WIDTH 800 
#define SCREEN_HEIGHT 600



int main(int argc , char *argv[])
{

SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *ecran=NULL , *background=NULL ;

SDL_Event event ;

int continue1=1 ;
int x,y;
x = 0;
y = 0;
Uint32 start ;
const int FPS=30;

int b[2] = {0,0}; 
const int speed = 5;
SDL_Rect camera , position;
camera.x = 0;
camera.y = 0;
camera.w = SCREEN_WIDTH  ;
camera.h = SCREEN_HEIGHT;


position.x=0;
position.y=0;


ecran=SDL_SetVideoMode(SCREEN_WIDTH ,SCREEN_HEIGHT , 32 , SDL_HWSURFACE);
background=IMG_Load("background.jpg");


continue1=1;
while(continue1)
{

start=SDL_GetTicks();

SDL_BlitSurface(background , NULL , ecran, &position);

while(SDL_PollEvent(&event))
{

switch(event.type) 
{

case SDL_QUIT:
continue1=0 ;
break;


case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{


case SDLK_RIGHT:
b[0] = 1;
break;


case SDLK_LEFT:
b[1] = 1;
break;


case SDLK_ESCAPE:
continue1=0;
break;
}
break;


case SDL_KEYUP:
switch(event.key.keysym.sym)
{


case SDLK_RIGHT:
b[0] = 0;
break;


case SDLK_LEFT:
b[1] = 0;
break;


}
break;
}




}
 


switch(b[0])
{


case 0 :
SDL_BlitSurface(background, &camera, ecran, &position);
SDL_Flip(ecran);
break ;

case 1 :
x += speed;
camera.x += speed;


SDL_BlitSurface(background, &camera, ecran, &position);
SDL_Flip(ecran);
break ;




}





switch(b[1])
{

case 0 :
SDL_BlitSurface(background, &camera, ecran, &position);
SDL_Flip(ecran);
break ;


case 1 :
x -= speed;
camera.x -= speed;


SDL_BlitSurface(background, &camera, ecran, &position);

SDL_Flip(ecran);

break ;




}









if (1000/FPS > SDL_GetTicks()-start)
SDL_Delay(1000/FPS - (SDL_GetTicks()-start));



}







SDL_FreeSurface(  background );
SDL_Quit();
return 0 ;
}
