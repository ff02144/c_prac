#define B_size 16

#include<stdio.h>
#include<stdbool.h>

typedef struct ringbuffer{
int head,tail;
int count;
int buffer[B_size];
}ringbuffer;

void ring_init(ringbuffer* rb){
rb->head=0;
rb->tail=0;
rb->count=0;
}

void ring_push(ringbuffer* rb,int num){
if(rb->count<B_size){
rb->count++;
rb->buffer[rb->tail]=num;
rb->tail=(rb->tail+1)%B_size;
}
}

int ring_pop(ringbuffer* rb){
if(rb->count>0){
int num=rb->buffer[rb->head];
rb->head=(rb->head+1)%B_size;
rb->count--;
return num;
}
return -1;
}


int main(){
 ringbuffer rb;
 ring_init(&rb);
 
 for(int i=0;i<18;i++){
 ring_push(&rb,i);
 printf("Push %d 後: head=%d, tail=%d, count=%d\n",i,rb.head,rb.tail,rb.count);
 }
int num;
  for(int i=0;i<18;i++){
 num=ring_pop(&rb);
 printf(" pop得到%d 後: head=%d, tail=%d, count=%d\n",num,rb.head,rb.tail,rb.count);
 }

return 0;

}
