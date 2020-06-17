#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include"struct.h"

/*int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
     //fprintf(f,"%d",x);
    fclose(f);
printf("\n looool %d",x);
    return(0);
}*/

int arduinoReadData(int *x,FILE *f)
{



    char c;
    do {
   
  
    /*if(f == NULL)
        return(-1);*/
    
        fscanf(f,"%d",x);
        printf("\n looool %d",*x);
    
    
}while (*x==-1);
    return(0);
}

int mouvmentarduino(hero evan,FILE *f){

    int mouvment; 
    int x ;
    int k;
    k=arduinoReadData(&x,f);
    switch (x){
            case 1:
                mouvment=2;
                break;
            case 2:
                mouvment=1;
                break;
            case 3:
                mouvment=3;
                break; 
            case 0:
                mouvment=9;
            
                        break;
             default:   mouvment=9;
             }
            printf("%d arduino\n", x);
             //printf("%d arduino arduino arduino arduino\n", k);
 return mouvment;
}



