#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define POOL_SIZE 1024

static uint8_t pool[POOL_SIZE]; //1byte=8bit;
static uint32_t next_offset=0;
void* my_malloc(size_t size){
if(size==0){
return NULL;
}
if(size+next_offset>POOL_SIZE){
return NULL;
}
void* str;
str=&pool[next_offset];
next_offset+=(uint32_t)size;
return str;
}

int main(){
int* p=(int*)my_malloc(sizeof(char));
if(p!=NULL){
*p=99;
  printf("Value: %d\n", *p);
  printf("Address: %p\n", (void*)p);
}
 char* c = (char*)my_malloc(sizeof(char));
    if (c != NULL) {
        *c = 'A';
        printf("Char: %c\n", *c);
    }	printf("Adress:%p\n",(void*)c);

    void* fail = my_malloc(2000);
    printf("Fail test: %s\n", (fail == NULL) ? "NULL (正確)" : "有東西 (錯誤)");

return 0;

}
