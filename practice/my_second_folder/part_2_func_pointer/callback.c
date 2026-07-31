#include<stdio.h>

void add(int a, int b){printf("%d\n",a+b);}

void sub(int a, int b){printf("%d\n",a-b);}
int main(){
void (*callback)(int a, int b);

callback=add;
callback(100,10);
callback=sub;
callback(100,10);

return 0;

}
