#include<stdio.h>
#include<stdint.h>
#include<string.h>
#define poolsize 1024
#define blocksize 32
#define count (poolsize/blocksize)

static uint8_t pool[poolsize];
static uint32_t block=0;

void* blockalloc(void){
for(int i=0;i<count;i++){
if((block&(1UL<<i))==0){
block|=(1UL<<i);
return &pool[blocksize*i];
}
}
return NULL;
}
void blockfree(void* ptr){
uint32_t countf=((uint8_t*)ptr-pool)/blocksize;
block&=~(1UL<<countf);
}

int main(){
char* a=blockalloc();
printf("%p\n",a);
printf("%08x\n",block);
char* b=blockalloc();
printf("%p\n",b);
printf("%08x\n",block);
blockfree(a);
printf("%08x\n",block);
blockfree(b);
printf("%08x\n",block);
return 0;
}
