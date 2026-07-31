#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <stdint.h>

int init_display(void);
void close_display(void);
void render_display(uint8_t display[32][64]);

#endif
