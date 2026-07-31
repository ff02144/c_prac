#include "display.h"

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
 return 0;
}

void close_display(void){

}

void render_display(uint8_t display[32][64]){
}
