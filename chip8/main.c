#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MEMORY_SIZE 4096
#define PROGRAM_START 0X200

uint8_t memory[MEMORY_SIZE];

uint8_t V[16];
uint16_t I;
uint16_t PC;
uint16_t stack[16];
uint8_t SP;

uint8_t display[32][64];
uint8_t keypad[16];

uint8_t delay_timer;
uint8_t sound_timer;

void init_chip8(void){
 memset(memory,0,MEMORY_SIZE);
 memset(display,0,sizeof(display));
 memset(V,0,sizeof(V));
 PC=PROGRAM_START;
 I=0;
 memset(stack,0,sizeof(stack));
 SP=0;
 memset(keypad,0,sizeof(keypad));
 delay_timer=0;
 sound_timer=0;

}

int main(void){
init_chip8();
printf("HELLO! CHIP-8\n");
return 0;

}
