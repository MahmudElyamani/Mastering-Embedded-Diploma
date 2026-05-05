//--- ✄ --------- 2026.05.04 09:46 -------------------
//Author: Mahmood ElYamani
//numeric memory address direct
#include <stdio.h>
#include <stdint.h>

#define GPIO_ODR 0x48000404

void main()
{
   *((volatile uint32_t*) GPIO_ODR) |= 1UL<<16;
   printf("G_GPIO_ODR_Variable = 0x%X",GPIO_ODR);
}