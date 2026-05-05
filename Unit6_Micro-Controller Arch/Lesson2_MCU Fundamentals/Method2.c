//--- ✄ --------- 2026.05.04 09:46 -------------------
//Author: Mahmood ElYamani
//Casting an address to pointer

#include <stdio.h>
#include <stdint.h>

uint32_t GPIO_ODR_Variable = 0;
#define GPIO_ODR_ADD &GPIO_ODR_Variable
#define GPIO_ODR ((volatile uint32_t *) GPIO_ODR_ADD)

void main()
{
    *GPIO_ODR |= 1UL<<16;
    printf("GPIO_ODR_Variable = 0x%X",GPIO_ODR_Variable);
}