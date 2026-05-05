//--- ✄ --------- 2026.05.04 10:32 -------------------
//Author: Mahmood Elyamani
//use a structure, union and pointer for one register

#include <stdio.h>
#include <stdint.h>

uint32_t GPIO_ODR_Variable = 0;
#define GPIO_ODR_ADD &GPIO_ODR_Variable
#define GPIO_ODR (*((volatile uint32_t*)GPIO_ODR_ADD))

#pragma pack(1)
typedef struct {
    //for the sake of simplicity we'll disregard all unimpotant pins individually
    uint32_t pin0to15:16;
    uint32_t pin16: 1;
    uint32_t pin17to32:15;
}SGPIO_ODR_t;

typedef union{
    SGPIO_ODR_t S_ODR;
    uint32_t ODR;
}U_odr;

volatile U_odr *GPIO_ODR_R = (volatile U_odr*) GPIO_ODR_ADD;

void main()
{
    GPIO_ODR_R->S_ODR.pin16 = 1;
    printf("GPIO_ODR_Variable = 0x%X",GPIO_ODR_Variable);
}