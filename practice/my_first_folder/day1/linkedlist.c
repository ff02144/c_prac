#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node* next;
}node;
//node struct
node* create_node(int val){
node* current=(node*)malloc(sizeof(node));
if(current==NULL){
return NULL;
}
current->data=val;
current->next=NULL;
return current;
}//createnode

node* head=NULL;
//headnode create

node* addtohead(int val){
node* current=create_node(val);
if(current==NULL){
return NULL;
}
current->next=head;
head=current;
return current;
}//addtohead

void freenode(){
node* current=head;
while(current!=NULL){
	head=head->next;
	free(current);
	current=head;
}
}//freenode

void deletenode(int val){
node* current=head;
node* tofree;
if(head==NULL){
return;
}//node=NULL
while(head!=NULL&&head->data==val){
head=head->next;
free(current);
current=head;
}//val->val->...
while(current!=NULL){
if(current->next!=NULL&&(current->next)->data==val){
tofree=current->next;
current->next=(current->next)->next;
free(tofree);
}
else{
current=current->next;
}
}
}

int main() {
    addtohead(10);
    addtohead(20);
    addtohead(30);

    printf("串列建立完成。準備釋放記憶體...\n");

    freenode();

    printf("記憶體已釋放。程式結束。\n");
    return 0;
}
