#include <stdio.h>
#include <stdint.h>

int countBits(uint32_t num) {
    int count = 0;
    for(int i=0;i<32;i++){
    count+=(num>>i) & 0x1UL;
    }
    return count;
}

int main() {
printf("countBits(0x0000000F) = %d\n", countBits(0x0000000F));
printf("countBits(0xDEADBEEF) = %d\n", countBits(0xDEADBEEF));
return 0;
}
