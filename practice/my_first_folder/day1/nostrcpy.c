#include<stdio.h>
#include<stdlib.h>
int length(const char* s){
	int i=0;
	while(s[i]!='\0'){
	i++;
	}
	return i;
} 

char* strcpy(const char* src){
char* dest=(char*)malloc(length(src)+1);
if(dest==NULL){
return NULL;
}
int len=length(src)+1;
for(int i=0;i<len;i++){
dest[i]=src[i];
}
return dest;
}


int main(){
	char s[]="happy";
	char* copy=strcpy(s);
	printf("%d\n%s\n",length(s),copy);
	free(copy);
			
	return 0;
}
