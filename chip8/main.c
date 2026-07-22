#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "font.h"
#include "rom.h"

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
 memcpy(memory,fontset,sizeof(fontset));
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

int main(int argc, char *argv[]){
init_chip8();
printf("HELLO! CHIP-8\n");
	
if(argc<2){
printf("用法:%s<rom_file.ch8>\n",argv[0]);
return 1;
}
int result=load_rom(argv[1],memory,PROGRAM_START);
if(result!=0){
printf(" ROM讀取失敗\n");
return 1;
}
printf("ROM讀取成功\n");



while(1){

uint16_t opcode=(memory[PC]<<8)|memory[PC+1];

printf("PC:0x%03X, opcode:0x%03X\n",PC,opcode);

switch(opcode&0xF000){

case 0x1000:
	PC=opcode&0x0FFF;
	break;

case 0x6000:
	V[(opcode&0xF00)>>8]=opcode&0xFF;
	PC+=2;
	break;

case 0x7000:
	V[(opcode&0xF00)>>8]+=opcode&0xFF;
	PC+=2;
	break;

default:
	PC+=2;
	break;

}
}



return 0;

}
