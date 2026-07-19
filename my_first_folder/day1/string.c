#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct string{
	char* data;
	int size;
}string;

string* string_create(const char* str){
string* s=(string*)malloc(sizeof(string));
s->size=strlen(str);
s->data=(char*)malloc(s->size+1);
strcpy(s->data,str);
return s;
}

void stringfree(string* s){
free(s->data);
free(s);
}

string* string_copy(const string* src){
string* s= (string*)malloc(sizeof(string));
s->size=strlen(src->data);
s->data=(char*)malloc(s->size+1);
for(int i=0;i<=s->size;i++){
        s->data[i]=src->data[i];
} 
return s;
}
void string_assign(string* dest, const string* src){
	if(dest==src){
	return;
	}
	free(dest->data);
	dest->size=strlen(src->data);
	dest->data=(char*)malloc(dest->size+1);
	for(int i=0;i<=dest->size;i++){
	dest->data[i]=src->data[i];
	}
}
	

int main(){
string* s=string_create("hello");
printf("%s,%d",s->data,s->size);
stringfree(s);
return 0;
}
