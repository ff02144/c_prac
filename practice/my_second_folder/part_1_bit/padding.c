#include <stdio.h>
#include <stdint.h>

struct test{
unsigned char a;
unsigned int b;
unsigned short c;

};

int main(){
struct test t;

printf("size of test:%zu\n",sizeof(t));
printf("test t:%p\n",&t);
printf("char a:%p\n",&t.a);
printf("int b:%p\n",&t.b);
printf("short c:%p\n",&t.c);

return 0;
}
