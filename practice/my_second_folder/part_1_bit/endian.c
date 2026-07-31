#include<stdio.h>
#include<stdint.h>

int main() {
    uint32_t num = 0x12345678;
    unsigned char *ptr = (unsigned char *)&num;

printf("num=0x%08X\n",num);
printf("byte0=0x%02X\n",ptr[0]);
printf("byte1=0x%02X\n",ptr[1]);
printf("byte2=0x%02X\n",ptr[2]);
printf("byte3=0x%02X\n",ptr[3]);
return 0;
}
