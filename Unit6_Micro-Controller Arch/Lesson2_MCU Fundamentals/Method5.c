//--- ✄ --------- 2026.05.04 10:52 -------------------
//Author Mahmood Elyamani
//Method 5

#include <stdio.h>
#include <stdint.h>

uint32_t GPIO_Variable[4] = {0};
#define GPIO_B_Add &GPIO_Variable[0]

#pragma pack(1)

typedef struct{
    volatile uint32_t MODER;
    volatile uint32_t ODR;
    volatile uint32_t ASCR;
    volatile uint32_t IDR;
}SGPIO_t;

#define GPIOB ((SGPIO_t*)GPIO_B_Add)
void main()
{
    GPIOB->ODR = (1UL<<16);
    printf("G_GPIO_ODR_Variable = 0x%X",GPIO_Variable[1]);
}