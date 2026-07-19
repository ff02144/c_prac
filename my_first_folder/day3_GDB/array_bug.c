#include<stdio.h>

int find_max(){
int arr[5]={10,20,30,40,50};
int max=0;
int i;

for(i=0;i<5;i++){
if(arr[i]>max){
max=arr[i];
}
}
return max;
}

int main(){
int result=find_max();
printf("max是50,code:%d\n",result);
return 0;

}


