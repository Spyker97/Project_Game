#include<SDL/SDL.h>
#include"scrolling.h"

int main() {
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
	SDL_Event event;

	scrollImage img;
	SCROLL_Init(&img,"backx.png");

	int running = 1;
	SDL_EnableKeyRepeat(10,10);
	
	while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT ) running = 0;
			if(event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_ESCAPE) running = 0;

				if(event.key.keysym.sym == SDLK_RIGHT){


					if(img.clip.x < img.img->w - 800)
						img.clip.x += 10;
				}
				if(event.key.keysym.sym == SDLK_LEFT){
					if(img.clip.x > 0)
						img.clip.x -= 10;
				}
				if(event.key.keysym.sym == SDLK_UP){
					if(img.clip.y > 0)
						img.clip.y -= 10;
				}
				if(event.key.keysym.sym == SDLK_DOWN){
					if(img.clip.y < img.img->h - 610)
						img.clip.y += 10;
				}
			}
		}
		SCROLL_Render(&img,&screen);
		SDL_Delay(16);
		SDL_Flip(screen);
	}

	SDL_Quit();
	return 0;
}
