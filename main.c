#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>





#define speedplayer 3
#define speed 800


SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y) 
{

SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);

memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


return (color) ;

}


void update_points_de_collision(float *x1, float *y1 , float *x2 ,float *y2 , float *x3 ,float *y3 , float *x4 ,float *y4 , float *x5 ,float *y5 , SDL_Rect *rect)
{

*x1=rect->x + rect->w ;
*y1=rect->y ;

*x2=  rect->x + rect->w;
*y2= rect->y + 100  ;


*x3=rect->x + rect->w ;
*y3= rect->y + rect->h  ;


*x4=rect->x + rect->w ;
*y4= rect->y + 50  ;


*x5=rect->x + rect->w ;
*y5= rect->y + 150  ;

}


int verification_collision_player_map(SDL_Surface *map1 , float *x1, float *y1 , float *x2 ,float *y2 , float *x3 ,float *y3 , float *x4 ,float *y4 , float *x5 ,float *y5)
{

SDL_Color color1 , color2 , color3 , color4 , color5 ;


color1=GetPixel (map1 , *x1 , *y1) ;
color2=GetPixel (map1 , *x2 , *y2) ;
color3=GetPixel (map1 , *x3 , *y3) ;
color4=GetPixel (map1 , *x4 , *y4) ;
color5=GetPixel (map1 , *x5 , *y5) ;
  
if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255)) || ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ) || ((color4.r==255)  &&  (color4.g==255)  &&  (color4.b==255) ) || ((color5.r==255)  &&  (color5.g==255)  &&  (color5.b==255) ))
{
return 1 ;
}

else 
{
return 0 ;	
}


}









int main (int argc , char *argv[])
{


// ce qu'on ecrit ici ne changent pas avec les events q'on fait !!!!

SDL_Init(SDL_INIT_VIDEO);


SDL_Surface *ecran=NULL  , *map1=NULL , *player=NULL , *map2=NULL ;


ecran=SDL_SetVideoMode(800 , 600 , 32 , SDL_HWSURFACE);

int tab[4]={0,0,0,0};



SDL_Rect rect , camera  ;
rect.x= 0 ;
rect.y= 150 ; 

rect.w= 100 ;
rect.h= 200 ;


camera.x= 0 ;
camera.y= 0 ;
camera.w=800  ;
camera.h= 600 ;


player=IMG_Load("player.bmp");


float x1, y1 ,x2 ,y2 , x3 ,y3 , x4 ,y4 , x5 ,y5 ;

map1=SDL_LoadBMP("map1.bmp");
if (map1==NULL)
{printf("Unable to load map1: %s\n",SDL_GetError());
return 1;
}
/*
map2=SDL_LoadBMP("map.bmp");
if (map2==NULL)
{printf("Unable to load map2: %s\n",SDL_GetError());
return 1;
}*/

SDL_Color color1 , color2 , color3 , color4 , color5 ;

int resultat_de_collision ;


update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);

Uint32 start ;
const int FPS=30; 


int continuee=1 ;




while (continuee)
{

start=SDL_GetTicks();

SDL_BlitSurface(map1 , &camera , ecran , NULL); /// on peut blitter ou non le background de collision !!!! kima n7ebou !!





SDL_Event event ;

while(SDL_PollEvent(&event))
{

switch(event.type)
{

case SDL_QUIT :
continuee=0 ;
break ;

case SDL_KEYDOWN :

switch (event.key.keysym.sym)
{
case SDLK_UP :

tab[0]=1;
break;


case SDLK_DOWN :
tab[1]=1;
break ;


case SDLK_LEFT :
tab[2]=1;
break ;

case SDLK_RIGHT :
tab[3]=1;
break ;

}

break ;





case SDL_KEYUP :

switch (event.key.keysym.sym)
{

case SDLK_UP :
tab[0]=0;
break ;

case SDLK_DOWN :
tab[1]=0;
break ;


case SDLK_LEFT :
tab[2]=0;
break ;

case SDLK_RIGHT :
tab[3]=0;
break ;

}
break ;

}

}







if (tab[0])
{
rect.y-=speedplayer ;


update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);

resultat_de_collision=verification_collision_player_map(map1 , &x1, &y1 , &x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5) ;

if (tab[0] && resultat_de_collision==1 )
{
rect.y+=speedplayer ;

update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);
}


}











if (tab[1])
{
rect.y+=speedplayer ;


update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);

resultat_de_collision=verification_collision_player_map(map1 , &x1, &y1 , &x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5) ;

if (tab[1] && resultat_de_collision==1 )
{
rect.y-=speedplayer ;

update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);
}


}





if (tab[2])
{
rect.x-=speedplayer ;


update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);

resultat_de_collision=verification_collision_player_map(map1 , &x1, &y1 , &x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5) ;

if (tab[2] && resultat_de_collision==1 )
{
rect.x+=speedplayer ;

update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);
}


}






if (tab[3])
{
rect.x+=speedplayer ;


update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);

resultat_de_collision=verification_collision_player_map(map1 , &x1, &y1 , &x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5) ;

if (tab[3] && resultat_de_collision==1 )
{
rect.x-=speedplayer ;

update_points_de_collision(&x1, &y1 ,&x2 ,&y2 , &x3 ,&y3 , &x4 ,&y4 , &x5 ,&y5 , &rect);
}


}


player=SDL_LoadBMP("player.bmp");

SDL_SetColorKey(player, SDL_RLEACCEL|SDL_SRCCOLORKEY, SDL_MapRGB(player->format,255,255,255));

SDL_BlitSurface(player , NULL , ecran , &rect);
SDL_Flip(ecran);



if (1000/FPS > SDL_GetTicks()-start)
SDL_Delay(1000/FPS - (SDL_GetTicks()-start));


}


SDL_FreeSurface(map1);
SDL_FreeSurface(map2);
SDL_FreeSurface(player);
SDL_Quit();
}

















