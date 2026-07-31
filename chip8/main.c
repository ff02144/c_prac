#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "font.h"
#include "rom.h"

#define MEMORY_SIZE 4096
#define PROGRAM_START 0X200
#define INSTRUCTIONS_PER_FRAME 10
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
srand((unsigned int)time(NULL));
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

for(int for_loop=0; for_loop<INSTRUCTIONS_PER_FRAME; for_loop++){
uint16_t opcode=(memory[PC]<<8)|memory[PC+1];

printf("PC:0x%03X, opcode:0x%03X\n",PC,opcode);

switch(opcode&0xF000){
case 0x0000:
	if(opcode==0x00E0){PC+=2;
	memset(display,0,sizeof(display));       
		break;}
	else if(opcode==0x00EE){
	SP--;
	PC=stack[SP];
	break;
	}
	PC+=2;
	break;
case 0x1000:
	PC=opcode&0xFFF;
	break;

case 0x2000:
	stack[SP]=PC+2;
	PC=opcode&0xFFF;
	SP+=1;
	break;
	
case 0x3000:
	if(V[(opcode&0xF00)>>8]==(opcode&0xFF)){PC+=4;}
	else{PC+=2;}
	break;

case 0x4000:
        if(V[(opcode&0xF00)>>8]!=(opcode&0xFF)){PC+=4;}
        else{PC+=2;}
        break;

case 0x5000:{
	uint8_t x=(opcode&0x0F00)>>8;
        uint8_t y=(opcode&0x00F0)>>4;
	PC+=(V[x]==V[y])?4:2;
	break;
	    }

case 0x6000:
	V[(opcode&0xF00)>>8]=opcode&0xFF;
	PC+=2;
	break;

case 0x7000:
	V[(opcode&0xF00)>>8]+=opcode&0xFF;
	PC+=2;
	break;

case 0x8000:
		uint8_t x=(opcode&0x0F00)>>8;
    		uint8_t y=(opcode&0x00F0)>>4;
	 switch(opcode&0x000F){
		case 0x0:
		V[x]=V[y];
	  	break;
		
		case 0x1:
		V[x]|=V[y];
		break;
		
		case 0x2:
		V[x]&=V[y];
		break;
		
		case 0x3:
		V[x]^=V[y];
		break;
		
		case 0x4:
		{int num=V[x]+V[y];
                 V[15]=num>255?1:0;
		 V[x]=num&0xFF;
		}
		 break;
		
		case 0x5:
                 V[15]=V[x]>=V[y]?1:0;
			 V[x]-=V[y];
                break;

		case 0x6:
		V[15]=V[x]&0x1;
		V[x]>>=1;
		break;
		
		case 0x7:
                V[15]=V[y]>=V[x]?1:0;
		V[x]=V[y]-V[x];
                break;
		
		case 0xE:
		V[15]=(V[x]&0x80)>>7; 
		V[x]<<=1;
    		break;
	}

	PC+=2;
	break;
case 0x9000:{
        uint8_t x=(opcode&0x0F00)>>8;
        uint8_t y=(opcode&0x00F0)>>4;
        PC+=(V[x]==V[y])?2:4;
        break;
            }
case 0xA000:
	I=opcode&0xFFF;
	PC+=2;
	break;

case 0xB000:
	PC=V[0]+(opcode&0x0FFF);
	break;
case 0xC000:
	{
	uint8_t random_byte = rand()&(0xFF);
	V[(opcode&0xF00)>>8]=random_byte&(opcode&0xFF);
	PC+=2;
	break;
	}
case 0xD000:
	{	V[15]=0;
	uint8_t Vx=V[(opcode&0xF00)>>8];
	uint8_t Vy=V[(opcode&0x0F0)>>4];
	uint8_t N=(opcode&0xF);
	for(int row=0;row<N;row++){
	uint8_t byte=memory[I+row];
		for(int col=0;col<8;col++){
			if (byte & (1 << (7 - col))) {
				int x=(Vx+col)&63;
				int y=(Vy+row)&31;
 				if (display[y][x]==1){
                    			V[15]=1;}
     					display[y][x]^=1;
     						}
     					}
				}
	PC+=2;
	break;
	}

case 0xE000:{
	uint8_t key=V[(opcode&0xF00)>>8]; 
	switch(opcode&0xFF){
	case 0xA1:
		PC+=(!keypad[key])?4:2; 
	break;
	case 0x9E:
            	PC+=(keypad[key])?4:2;
	break;
	default:
	PC+=2;
	break;
	}
	break;}
case 0xF000:{
uint8_t X=(opcode&0xF00)>>8;
	switch(opcode&0xFF){
	case 0x07:
		V[X]=delay_timer;
		PC+=2;
		break;
	case 0x0A:
		{
		int check=-1;
		for(int i=0;i<16;i++){
		if(keypad[i]==1){
			check=i;
			break;
		}
		}

		if (check == -1) {
		break;
		}
		V[X]=(uint8_t)check;
		PC+=2;
		break;
		}
	case 0x15:
		delay_timer=V[X];
		 PC+=2;
		break;
	case 0x18:
		sound_timer=V[X];
		 PC+=2;
		break;
	case 0x1E:
		{
		V[15]=(V[X]+I)>0xFFF?1:0;
		I=I+V[X];
		 PC+=2;
		break;
		}
	case 0x29:
		{
		uint8_t x=(opcode&0x0F00)>>8;
		uint8_t character=V[x]&0x0F;
		I=(character*5);
		 PC+=2;
		break;
		}
	case 0x33:
		memory[I]=V[X]/100;
		memory[I+1]=(V[X]/10)%10;
		memory[I+2]=V[X]%10;
		 PC+=2;
		break;
	case 0x55:
		for(int i=0;i<=X;i++){memory[I+i]=V[i];}
		 PC+=2;
		break;
	case 0x65:
                for(int i=0;i<=X;i++){V[i]=memory[I+i];}
                 PC+=2;
		break;
	default:
		break;	
	}
	break;}
default:
	PC+=2;
	break;


}
}//switch end
if(delay_timer>0){delay_timer--;}
if(sound_timer>0){sound_timer--;}
}

return 0;

}
