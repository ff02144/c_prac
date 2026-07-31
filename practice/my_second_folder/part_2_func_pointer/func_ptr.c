#include <stdio.h>
int add(int a, int b){return a+b;}
int sub(int a, int b){return a-b;}

int main(){
int(*calc)(int a, int b);

calc=add;
printf("10+5=%d\n",calc(10,5));
calc=sub;
printf("10-5=%d\n",calc(10,5));
return 0;
}
