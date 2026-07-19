#include <stdio.h>

int calculate_sum(){
int sum = 0;
int i;


for(i=0; i<5;i++){
sum=sum+i;
}
return sum;
}

int main(){
int result = calculate_sum();
printf("1+2+3+4+5 的答案為15,但程式輸出:%d",result);
return 0;
}
