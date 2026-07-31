#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define pool_size 1024
#define block_size 32
#define block_count (pool_size/block_size)

static uint8_t pool[pool_size];
static uint32_t block_map=0;

void* block_alloc(void){
for(int i=0;i<block_count;i++){
if((block_map&(1<<i))==0){
block_map|=(1<<i);
return &pool[block_size*i];
}
}
return NULL;
}

void block_free(void* ptr){
uint32_t index=(uint32_t)(((uint8_t*)ptr-&pool[0])/block_size);
block_map&=~(1UL<<index);
}

int main(){
    void* p1=block_alloc();
    void* p2=block_alloc();
    printf("p1=%p,p2=%p\n",p1,p2);

    block_free(p1);

    void* p3=block_alloc();
    printf("p3=%p\n",p3); 

    void* p4=block_alloc();
    void* p5=block_alloc();
    printf("p4=%p,p5=%p\n",p4,p5);

    return 0;
}
