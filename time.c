#include <stdio.h>
#include"time.h"
void initializerTemps(Time *time){
	time->font = TTF_OpenFont("font.ttf", 32);
	time->time = 0;
	sprintf(time->timeString,"\n00:00");
	SDL_Color color = {255,255,255};
	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
}

void afficherTemps(Time *time, SDL_Surface **screen){
	SDL_Color color = {255,255,255};
	time->time++;
	if(time->time % 60 == 0){
		sprintf(time->timeString,"\n%02d:%02d\n",time->time/60/60,(time->time/60)%60);
		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
	}

	SDL_BlitSurface(time->msg,NULL,*screen,NULL);
}
