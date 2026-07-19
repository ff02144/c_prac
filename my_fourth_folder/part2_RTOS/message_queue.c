#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int write_index=0;//下個資料位置
int read_index=0;
int item_count=0;//資料筆數

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
//鎖的型態            //鎖的初始值(解鎖狀態)
//等同pthread_mutex_init(&mutex, NULL);





void* producer_task(void* arg)
{
int num=0;
while(1){
        pthread_mutex_lock(&mutex);
        //看&mutex現在鎖的狀態，若=0則改成1然後讓程式繼續
                             //若=1則暫停不給過

if(item_count<BUFFER_SIZE){
buffer[write_index]=num;
write_index=(write_index+1)%BUFFER_SIZE;//控制在0~size-1，4填寫後回去0
item_count++;
num++;
printf("[生產者] 放入 %d (佇列現有 %d 筆)\n", num, item_count);
}

        pthread_mutex_unlock(&mutex);//解鎖
        sleep(1);
}
return NULL;
}






void* consumer_task(void* arg){
while(1){
pthread_mutex_lock(&mutex);
if(item_count>0){
int data=buffer[read_index];
printf("data=%d\n",data);
read_index=(read_index+1)%BUFFER_SIZE;
item_count-=1;
}
pthread_mutex_unlock(&mutex);
sleep(2);
}
return NULL;
}





int main(){
pthread_t task1,task2;

pthread_create(&task1,NULL,producer_task,NULL);
pthread_create(&task2,NULL,consumer_task,NULL);

pthread_join(task1,NULL);
pthread_join(task2,NULL);
return 0;

}
