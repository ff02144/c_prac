#include <stdio.h>

void cause_segfault() {
    int *p = NULL;
    *p = 42;    
}

int main() {
    printf("程式開始...\n");
    cause_segfault();
    printf("程式結束\n");
    return 0;
}
