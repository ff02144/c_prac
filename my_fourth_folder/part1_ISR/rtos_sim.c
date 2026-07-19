#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* high_task(void* arg){
while(1){
printf("high riority task....\n");
sleep(3);
}
return NULL;
}


void* middle_task(void* arg){
while(1){
printf("middle_priority_task....\n");
sleep(4);
}
return NULL;
}


void* low_task(void* arg){
while(1){
printf("low_priority_task.....\n");
sleep(5);



}
return NULL; 
}

int main(){
pthread_t middle_thread,high_thread, low_thread;

int a,b,c;
struct sched_param param;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_attr_setschedpolicy(&attr,SCHED_RR);



param.sched_priority=99;
pthread_attr_setschedparam(&attr,&param);
a=pthread_create(&high_thread,&attr,high_task,NULL);

param.sched_priority=1;
pthread_attr_setschedparam(&attr,&param);
b=pthread_create(&low_thread,&attr,low_task,NULL);

param.sched_priority=50;
pthread_attr_setschedparam(&attr,&param);
c=pthread_create(&middle_thread,&attr,middle_task,NULL);
printf("%d  %d  %d\n",a,c,b);
pthread_join(high_thread,NULL);
pthread_join(low_thread,NULL);
pthread_join(middle_thread,NULL);

return 0;
}
