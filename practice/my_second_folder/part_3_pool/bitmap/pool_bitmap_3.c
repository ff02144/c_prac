#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define pool_size 1024
#define block_size 32
#define count (pool_size/block_size)
static uint8_t pool[pool_size];
static uint32_t block=0;



void* myalloc(void){
for(int i=0;i<count;i++){
if((block&(1UL<<i))==0){
block|=(1UL<<i);
return &pool[i*block_size];
}
}
return NULL;
}


void myfree(void* ptr){
uint32_t set=((uint8_t*)ptr-pool)/block_size;
block&=~(1<<set);
}

int main(){
char *A,*B;
A=myalloc();
printf("%p\n%d\n",A,block);
B=myalloc();
printf("%p\n%d\n",B,block);
myfree(A);
printf("%d\n",block);
myfree(B);
printf("%d\n",block);
A=myalloc();
printf("%p\n%d\n",A,block);
return 0;
}
