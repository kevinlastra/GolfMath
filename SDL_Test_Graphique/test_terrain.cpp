#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "case.h"

int main(int argc, char const *argv[])
{
	SDL_Surface *ecran = NULL, *herbe = NULL, *pherbe = NULL;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE);

	herbe = SDL_LoadBMP("Projet/green/basic/green.bmp");
	pherbe = SDL_LoadBMP("Projet/green/basic/green_pressed.bmp");

	SDL_Rect ph1, ph2, ph3, ph4;

	ph1.x = ecran->w/2;
	ph1.y = ecran->h/2;

	ph2.x = ecran->w/2;
	ph2.y = ecran->h/2 - herbe->h;

	ph3.x = ecran->w/2 - herbe->w;
	ph3.y = ecran->h/2;

	ph4.x = ecran->w/2 - herbe->w;
	ph4.y = ecran->h/2 - herbe->h;

	SDL_BlitSurface(herbe, NULL, ecran, &ph1);
	SDL_BlitSurface(herbe, NULL, ecran, &ph2);
	SDL_BlitSurface(herbe, NULL, ecran, &ph3);
	SDL_BlitSurface(herbe, NULL, ecran, &ph4);

	SDL_Flip(ecran);
	int q = 1;

	while (q)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				q = 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.y > ph1.y
					&& event.button.y < (ph1.y + herbe->h)
					&& event.button.x > ph1.x
					&& event.button.x < (ph1.x + herbe->w))
				{
						SDL_BlitSurface(pherbe, NULL, ecran, &ph1);
						SDL_BlitSurface(herbe, NULL, ecran, &ph2);
						SDL_BlitSurface(herbe, NULL, ecran, &ph3);
						SDL_BlitSurface(herbe, NULL, ecran, &ph4);
				}
				else if (event.button.y > ph2.y
					&& event.button.y < (ph2.y + herbe->h)
					&& event.button.x > ph2.x
					&& event.button.x < (ph2.x + herbe->w))
				{
					SDL_BlitSurface(pherbe, NULL, ecran, &ph2);
					SDL_BlitSurface(herbe, NULL, ecran, &ph1);
					SDL_BlitSurface(herbe, NULL, ecran, &ph3);
					SDL_BlitSurface(herbe, NULL, ecran, &ph4);
				}
				else if (event.button.y > ph3.y
					&& event.button.y < (ph3.y + herbe->h)
					&& event.button.x > ph3.x
					&& event.button.x < (ph3.x + herbe->w))
				{
					SDL_BlitSurface(pherbe, NULL, ecran, &ph3);
					SDL_BlitSurface(herbe, NULL, ecran, &ph1);
					SDL_BlitSurface(herbe, NULL, ecran, &ph2);
					SDL_BlitSurface(herbe, NULL, ecran, &ph4);
				}
				else if (event.button.y > ph4.y
					&& event.button.y < (ph4.y + herbe->h)
					&& event.button.x > ph4.x
					&& event.button.x < (ph4.x + herbe->w))
				{
					SDL_BlitSurface(pherbe, NULL, ecran, &ph4);
					SDL_BlitSurface(herbe, NULL, ecran, &ph1);
					SDL_BlitSurface(herbe, NULL, ecran, &ph2);
					SDL_BlitSurface(herbe, NULL, ecran, &ph3);
				}
				else 
				{
					SDL_BlitSurface(herbe, NULL, ecran, &ph1);
					SDL_BlitSurface(herbe, NULL, ecran, &ph2);
					SDL_BlitSurface(herbe, NULL, ecran, &ph3);
					SDL_BlitSurface(herbe, NULL, ecran, &ph4);
				}
				break;
		}

		SDL_Flip(ecran);
	}

	SDL_FreeSurface(herbe);

	SDL_Quit();

	return EXIT_SUCCESS;
}