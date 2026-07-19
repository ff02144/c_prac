#include "foo.h"

int global_counter=100;

int add(int a, int b){
global_counter++;
	return a+b + global_counter;


}
