#include"scrolling.h"
#include<SDL/SDL_image.h>









void SCROLL_Init(scrollImage *s,char* path){
	s->img = IMG_Load(path);
	s->position.x = s->position.y = s->position.w = s->position.h= 0;
	s->clip.x = s->clip.y = 0;
	s->clip.w = 800;
	s->clip.h = 600;
}

void SCROLL_Render(scrollImage *s, SDL_Surface **screen){
	SDL_BlitSurface(s->img,&s->clip,*screen,&s->position);
}
