#include<stdio.h>
#include<signal.h>
#include<unistd.h>

volatile int tick_flag=0;

void timer_isr(int signum)
{
    tick_flag=1;
}

int main(){

signal(SIGALRM,timer_isr);
alarm(2);
printf("系統啟動，等2秒後tick....\n");


while(1){
	if(tick_flag==1){
	tick_flag=0;
	printf("tick!\n");
	alarm(2);
	
	}
	usleep(100);//怕while會融化cpu

}
return 0;
}
