#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    printf("SDL2 测试开始\n");
    fflush(stdout);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init 失败: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow(
        "SDL2 测试视窗",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_SHOWN
    );

    if (win == NULL) {
        printf("SDL_CreateWindow 失败: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    printf("视窗已开启，等待 2 秒后自动关闭...\n");
    fflush(stdout);
    SDL_Delay(2000);

    SDL_DestroyWindow(win);
    SDL_Quit();
    printf("测试结束。\n");
    return 0;
}
