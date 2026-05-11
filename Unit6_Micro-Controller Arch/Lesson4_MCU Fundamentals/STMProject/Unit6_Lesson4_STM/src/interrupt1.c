
#include "interrupt1.h"

int main(void)
{
    RCC_APB2ENR |= (1<<2);          /*  Port A clock enabled    */
    RCC_APB2ENR |= (1<<0);          /*  Alternate function I/O clock enable */

    GPIOA_CRH   &= 0xFF0FFFFF;      /*  Setting pin 13 port A as output    */
    GPIOA_CRH   |= 0x00200000;
    GPIOA_CRL   |= (1<<2);          /*  sets pin 0 port A to floating      */

    AFIO_EXTICR1 |= 0;              /*  Enabling configuration to PORT A   (not necessary but for explanation)*/

    EXTI_RTSR   |= (1<<0);          /*  Enabling rising trigger   */
    EXTI_IMR    |= (1<<0);          /*  Enabling EXTI line 0 (Mask1)   */

    NVIC_EXTI0  |= (1<<6);          /*  Enabling NVIC register  */

    while(1)
    {
    }
}

void EXTI0_IRQHandler(void)
{
    //This code will get executed once the interrupt on port A pin 0 happens _|- rising edge
    //Functionality: toggles led on pin 13 port A
    GPIOA_ODR ^= (1<<13);

    //Clear pending request for line 0
    EXTI_PR     |= (1<<0);
}