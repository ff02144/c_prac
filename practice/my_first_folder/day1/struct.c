#include<stdio.h>
#include<stdlib.h>

typedef struct point{
int x;
int y;
}point;

point* getpoint(int val_x,int val_y){

	point* p=(point*)malloc(sizeof(point));
	p->x=val_x;
	p->y=val_y;
	return p;
}

int main(){
point* p=getpoint(10,20);
printf("%d,%d",p->x,p->y);
free(p);
return 0;
}
