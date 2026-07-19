#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
extern void* block_alloc();
typedef struct{
void (*task_func)(void);
uint32_t period; //週期
uint32_t last_run;
uint8_t state; //0=暫停1=就緒
}TaskCB;

void task_blink(void){
    printf("LED is blinking...\n");
}

void task_read_sensor(void){
    printf("Sensor value:42\n");
}

int main(){

printf("Mini Scheduler Started!\n");

TaskCB* task1=(TaskCB*)block_alloc();
task1->task_func=task_blink;
task1->period=1;//task1週期為1


TaskCB* task2=(TaskCB*)block_alloc();
task2->task_func=task_read_sensor;
int task_count=2;
task2->period=2;//task2週期為2

TaskCB* arr[5]={task1,task2};

for(int i=0; i<task_count;i++){
arr[i]->state=1;//state設就緒
arr[i]->last_run=(uint32_t)time(NULL)-arr[i]->period;
}//和時間扣除周期讓每個task第一次執行時間歸零

while(1){
for(int i=0; i<task_count;i++){

	if(arr[i]->state==1){
		if((uint32_t)time(NULL)>=arr[i]->last_run+arr[i]->period){
//當前時間>=紀錄時間+周期才做
		arr[i]->task_func();
		arr[i]->last_run=(uint32_t)time(NULL);
}
}
}
}
return 0;
}
