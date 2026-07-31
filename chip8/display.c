#include "display.h"
#include <stdio.h>
#include <stdint.h>
static SDL_Texture *texture = NULL;
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

int init_display(void){
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("SDL初始化失敗:%s\n",SDL_GetError());
return 1;
}

window=SDL_CreateWindow(
"CHIP-8 Emulator",
SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED,
960,
480,
SDL_WINDOW_SHOWN
);

if(window==NULL){
printf("SDL_CreateWindow錯誤:%s\n",SDL_GetError());
SDL_Quit();
return 1;
}

renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
if(renderer==NULL){
printf("SDL_CreateRenderer錯誤:%s\n",SDL_GetError());
SDL_DestroyWindow(window);
SDL_Quit();
return 1;
}
texture=SDL_CreateTexture(
renderer,
SDL_PIXELFORMAT_ARGB8888,
SDL_TEXTUREACCESS_STREAMING,
64,
32);

if(texture==NULL){
printf("SDL_CreateTexture錯誤:%s\n",SDL_GetError());
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();
return 1;
}
 return 0;
}




void close_display(void){
if(texture!=NULL){
SDL_DestroyTexture(texture);
texture=NULL;
}
if(renderer!=NULL){
	SDL_DestroyRenderer(renderer);
	renderer=NULL;
}
if (window!=NULL){
       SDL_DestroyWindow(window);
       window=NULL;
}
SDL_Quit();
}


void render_display(uint8_t display[32][64]){
void *pixels;
int pitch;
if(SDL_LockTexture(texture,NULL,&pixels,&pitch)!=0){
printf("SDL_LockTexture錯誤:%s\n",SDL_GetError());
return;
}
uint32_t *pixel_data=(uint32_t *)pixels;
int row_pixels=pitch/4;

for(int y=0;y<32;y++){
for(int x=0;x<64;x++){
uint32_t color=display[y][x] ? 0xFFFFFFFF:0xFF000000;
pixel_data[y*row_pixels+x]=color;
}
}

SDL_UnlockTexture(texture);

SDL_Rect destRect={0,0,960,480};
SDL_RenderCopy(renderer,texture,NULL,&destRect);
SDL_RenderPresent(renderer);
}
