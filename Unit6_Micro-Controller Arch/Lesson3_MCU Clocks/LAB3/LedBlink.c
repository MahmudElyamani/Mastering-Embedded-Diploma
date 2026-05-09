#include "LedBlink.h"

int main(void)
{
    RCC_APB2ENR |= (1<<2);          /*  Port A clock enabled    */
    RCC_CFGR    |= (0b10);          /*  Enabling PLL clock      */
    RCC_CFGR    |= (0b0110<<18);    /*  Multiplying the HSI clock (4Mhz) by 8 (32MHz)*/
    RCC_CFGR    |= (0b100<<8);      /*  Dividing the 32Mhz from AHB bus by 2 for APB1 Bus (4Mhz)   */
    RCC_CFGR    |= (0b101<<11);     /*  Dividing the 32Mhz from AHB bus by 4 for APB2 bus (8Mhz)   */
    
    GPIOA_CRH   &= 0xFF0FFFFF;
    GPIOA_CRH   |= 0x00200000;
    while(1)
    {
        R_ODR->Pin.P_13 = 1;
        DelaySeconds(1);
        R_ODR->Pin.P_13 = 0;
        DelaySeconds(1);
    }
}