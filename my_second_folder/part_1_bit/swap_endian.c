#include<stdio.h>
#include<stdint.h>

uint32_t swap_endian(uint32_t num){
unsigned char* ptr=(unsigned char*)&num;
for(int i=0;i<2;i++){
ptr[i]^=ptr[3-i];
ptr[3-i]^=ptr[i];
ptr[i]^=ptr[3-i];
}
return num;
}

uint32_t swap_endian_2(uint32_t num){
uint32_t byte0=(num>>0)&0xFF;
uint32_t byte1=(num>>8)&0xFF;
uint32_t byte2=(num>>16)&0xFF;
uint32_t byte3=(num>>24)&0xFF;
return (byte0<<24)|(byte1<<16)|(byte2<<8)|(byte3<<0);
}

int main() {
    uint32_t num = 0x12345678;
    uint32_t swapped = swap_endian(num);
    printf("Original: 0x%08X\n", num);
    printf("Swapped:  0x%08X\n", swapped);
    uint32_t swapped_2 = swap_endian_2(num);
    printf("Original: 0x%08X\n", num);
    printf("Swapped:  0x%08X\n", swapped_2);
    return 0;
}

