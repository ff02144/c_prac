#include<stdio.h>
#include<stdint.h>

extern void* block_alloc(void);

int main(){
void* ptrs[33];
//把資料全塞進block_alloc
for(int i=0;i<33;i++){
ptrs[i]=block_alloc();
printf("Alloc%d:%p\n",i,ptrs[i]);
if(ptrs[i] == NULL){
printf("POOL EXHAUSTED!");
}
}


}
