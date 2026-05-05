#include <stdio.h>
#include <stdint.h>

uint32_t Temp_Data = 0;
uint32_t *Address = 0;
Address = &Temp_Data;
#define GPIO_ODR Address

int main()
{
    *((volatile uint32_t*)GPIO_ODR) |= 1UL<<16;
    printf("0x%X",Temp_Data);
    return 0;
}