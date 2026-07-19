#include<stdio.h>
#include<stdint.h>
uint32_t setbit(uint32_t reg, int pos){
reg|=(1<<pos);
printf("0x%08x\n",reg);
return reg;
} 

uint32_t clearbit(uint32_t reg,int pos){
reg&=~(1<<pos);
printf("0x%08x\n",reg);
return reg;
}

uint32_t togglebit(uint32_t reg,int pos){
reg^=(1<<pos);
printf("0x%08x\n",reg);
return reg;
}

int getbit(uint32_t reg, int pos){
int k;
k=1&(reg>>pos);
printf("%d\n",k);
return k;
}

int ispoweroftwo(uint32_t reg){
if(reg==0){return 0;}
return (reg&(reg-1))==0;
}


int main(){
uint32_t reg=0x00000000;
setbit(reg,5);
reg=0xFFFFFFFF;
reg=clearbit(reg,3);
reg=0x0000FF00;
reg=togglebit(reg,8);
int k=getbit(reg,8);
reg=togglebit(reg,8);
k=getbit(reg,8);
for(int i=1;i<=6;i++){
printf("%d\n",ispoweroftwo(i));
}
uint32_t data=0xDEADBEEF;
uint32_t result=(data>>8)&0xFF;
printf("0x%02x\n",result);


return 0;
}
