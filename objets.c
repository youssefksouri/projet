#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>  /*bib lang c*/


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h> /*bib SDL*/

#define W_Screen 800  /*long backg*/
#define H_Screen 600  /*haut backg*/
#define CMode 32    /*nbr de couleurs*/

#define SPEED 5   /*vitesse */


#define SPRITE_H 60 /*long voit*/
#define SPRITE_W 150 /*haut voit*/
#define MAX_FRAMES 4 /*nbr de pas*/



                     #define W_BackgImg 259
                     #define H_BackgImg 194  /*ref backg*/

typedef struct entite   
{
	SDL_Surface* spriteleft;  /*init vers gauche*/
	SDL_Surface* spriteright; /*init vers droite*/

	SDL_Rect frame; /*pos des pixels*/
	SDL_Rect dst;   /* distance */
        


}Entite;
















int main(int argc, char** argv)
{
    SDL_Surface* screen = NULL;  /*init fenetre*/
int repit = 1, i=0;    
	SDL_Init(SDL_INIT_VIDEO); /* init image et vid*/
	screen = SDL_SetVideoMode(W_Screen, H_Screen, CMode, SDL_HWSURFACE/*reserver une place dans disque dur*/);

	Entite entite;
    
    SDL_Surface* backg = NULL; /*init backg*/
    backg = IMG_Load("index.jpeg"); /*appel d'une photo*/
    SDL_Flip(screen); /*affichage image*/
  
	entite.spriteleft = IMG_Load("rouge1.png"); /*appel du voit*/
	 
	entite.dst.x = 0;  /*pos sur x*/
	entite.dst.y = 300;  /*pos sur y*/

	//Hide Cursor
	/*SDL_ShowCursor(SDL_DISABLE);*/ /*curseur */

	
	while(repit == 1) /*boucle de repitition de l'annim*/
	{

           entite.dst.x+100; /*deplacement*/
           SDL_BlitSurface(entite.spriteright, &entite.frame,screen, &entite.dst); /*coller voiture sur bakg*/
                SDL_Flip(screen); 
		SDL_Event event; /* mouvement*/
		SDL_PollEvent(&event); /*mouvement avec bouton*/

		

		for(i = 0; i<MAX_FRAMES; i++)
		{
			entite.frame.x = i*SPRITE_W; /*2*long voit*/
			entite.frame.y = 0;
			entite.frame.w = SPRITE_W;
			entite.frame.h = SPRITE_H;
	
			SDL_BlitSurface(entite.spriteright, &entite.frame, screen, &entite.dst);
			SDL_Flip(screen);
			SDL_Delay(100);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			entite.frame.x = i*SPRITE_W;
			entite.frame.y = 0;
			entite.frame.w = SPRITE_W;
			entite.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(entite.spriteleft, &entite.frame, screen, &entite.dst);
			SDL_Flip(screen);
			SDL_Delay(100);
		}


SDL_PollEvent(&event); 
       
switch(event.key.keysym.sym)
{
case SDLK_RIGHT:
break;

case SDLK_ESCAPE:
            repit  =0;
break;
       }
}







	SDL_Quit();
return 0;}
