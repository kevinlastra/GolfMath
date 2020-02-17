#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <time.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *herbe = NULL;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WarpMouse(ecran->w/2, ecran->h/2);

    SDL_WM_SetCaption("Golf Mathématique !", NULL);

    herbe = SDL_LoadBMP("Projet/green/basic/green.bmp");

    SDL_Rect positionHerbe;

    positionHerbe.x = ecran->w / 2 - herbe->w / 2;
    positionHerbe.y = ecran->h / 2 - herbe->h / 2;
    
    SDL_BlitSurface(herbe, NULL, ecran, &positionHerbe);

    int continuer = 1;
    SDL_EnableKeyRepeat(10, 10);

	while (continuer)
	{
		SDL_WaitEvent(&event);
	    switch(event.type)
	    {
	        case SDL_QUIT:
	            continuer = 0;
	            break;
	        case SDL_MOUSEBUTTONDOWN:
	        	if (event.button.button == SDL_BUTTON_LEFT)
	        	{
	        		herbe = SDL_LoadBMP("Projet/green/basic/green_pressed.bmp");
	        	}
	        	else if (event.button.button == SDL_BUTTON_RIGHT)
	        	{
	        		continuer = 0;
	        	}
	        	break;
	        case SDL_MOUSEMOTION:
	        	positionHerbe.x = event.motion.x - herbe->w/2;
	        	positionHerbe.y = event.motion.y - herbe->h/2;
	        	break;
	       	case SDL_KEYDOWN:
	       		switch (event.key.keysym.sym)
	       		{
	       			case SDLK_ESCAPE:
	       				continuer = 0;
	       				break;
	       			case SDLK_F11:
	       				ecran = SDL_SetVideoMode(1280, 720, 32, SDL_FULLSCREEN | SDL_DOUBLEBUF);
	       				break;
	       			case SDLK_RIGHT:
	       				positionHerbe.x += 2;
	       				break;
	       			case SDLK_LEFT:
	       				positionHerbe.x -= 2;
	       				break;
	       			case SDLK_DOWN:
	       				positionHerbe.y += 2;
	       				break;
	       			case SDLK_UP:
	       				positionHerbe.y -= 2;
	       				break;
	       		}
	       		break;
	    }
	    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	    SDL_BlitSurface(herbe, NULL, ecran, &positionHerbe);
	    
	    SDL_Flip(ecran);
	}
    
    SDL_FreeSurface(herbe);

    SDL_Quit();

    return EXIT_SUCCESS;
}
