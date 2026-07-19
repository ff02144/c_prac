#include <stdio.h>
#include "foo.h"

int main(){
printf("Initial global_counter: %d \n",global_counter);

int result=add(3,5);
printf("result of add(3,5):%d \n", result);

printf("Final global_counter:%d\n",global_counter);

return 0;
}
