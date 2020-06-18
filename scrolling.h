#pragma once

#include<SDL/SDL.h>





typedef struct scrollImage {
	SDL_Surface *img;
	SDL_Rect position, clip;
} scrollImage;

void SCROLL_Init(scrollImage *s, char* path);
void SCROLL_Render(scrollImage *s, SDL_Surface **screen);
