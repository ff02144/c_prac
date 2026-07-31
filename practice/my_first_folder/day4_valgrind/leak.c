#include<stdio.h>
#include<stdlib.h>

void create_leak(){
int *p=(int*)malloc(10*sizeof(int)); 

p[0]=100;
printf("p[0]=%d\n",p[0]);
}

int main(){
create_leak();
printf("漏了40byte\n");
return 0;
}
