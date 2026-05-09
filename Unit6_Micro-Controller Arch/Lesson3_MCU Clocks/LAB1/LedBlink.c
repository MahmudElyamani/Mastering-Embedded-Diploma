#include "LedBlink.h"

int main(void)
{
    RCC_APB2ENR |= (1<<2);      /*  Port A clock enabled    */
    RCC_CFGR    |= (0b0101<<24);    /*  HSI clock selected as MCO   */
    RCC_CFGR    |= (0b100<<8);      /*  HCLK divided by 2   */
    
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