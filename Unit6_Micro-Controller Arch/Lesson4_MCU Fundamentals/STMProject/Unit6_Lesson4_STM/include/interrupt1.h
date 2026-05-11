//--- ✄ --------- 2026.05.09 10:30 -------------------
/*
    By: Eng. Mahmood El Yamani
    Unit:6 Lesson:3
    writing full registers for RCC in STM32F103C6 microchip
*/

#ifndef INTERRUPT1_H_
#define INTERRUPT1_H_

#include <stdint.h>
typedef volatile uint32_t vuint32_t;
//Base definitions:

/*      RCC         */
#define RCC_BASE        0x40021000
#define RCC_CR          *(vuint32_t*)(RCC_BASE  + 0x0)      /* Clock control register*/
#define RCC_CFGR        *(vuint32_t*)(RCC_BASE  + 0x04)     /* Clock configuration register */
#define RCC_CIR         *(vuint32_t*)(RCC_BASE  + 0x08)     /* Clock interrupt register */
#define RCC_APB2RSTR    *(vuint32_t*)(RCC_BASE  + 0x0C)     /* APB2 Pirephral reset register */
#define RCC_APB1RSTR    *(vuint32_t*)(RCC_BASE  + 0x10)     /* APB1 Pirephral reset register */
#define RCC_AHBENR      *(vuint32_t*)(RCC_BASE  + 0x14)     /* AHB Pirephral clock enable register*/
#define RCC_APB2ENR     *(vuint32_t*)(RCC_BASE  + 0x18)     /* APB2 Pirephral clock enable register */ 
#define RCC_APB1ENR     *(vuint32_t*)(RCC_BASE  + 0x1C)     /* APB1 Pirephral clock enable register*/
#define RCC_BDCR        *(vuint32_t*)(RCC_BASE  + 0x20)     /* Backup domain control register */
#define RCC_CSR         *(vuint32_t*)(RCC_BASE  + 0x24)     /* Control/Status register */


/*      GPIO A      */
#define GPIOA_BASE      0x40010800
#define GPIOA_CRL       *(vuint32_t*)(GPIOA_BASE+ 0x00)
#define GPIOA_CRH       *(vuint32_t*)(GPIOA_BASE+ 0x04)
#define GPIOA_ODR       *(vuint32_t*)(GPIOA_BASE+ 0x0C)


/*      EXTI        */
#define EXTI_BASE       0x40010400
#define EXTI_IMR        *(vuint32_t*)(EXTI_BASE+ 0x00)
#define EXTI_RTSR       *(vuint32_t*)(EXTI_BASE+ 0x08)
#define EXTI_PR         *(vuint32_t*)(EXTI_BASE+ 0x14)


/*      AFIO        */
#define AFIO_BASE       0x40010000
#define AFIO_EXTICR1    *(vuint32_t*)(AFIO_BASE+ 0x08)


/*      Arm Cortex M3 pirephrals    */
#define NVIC_EXTI0      *(vuint32_t*)(0xE000E100)

typedef union
{
    vuint32_t   all_fields;
    struct
    {
        vuint32_t       reserved:13;
        vuint32_t       P_13:1;
    }Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

void DelaySeconds(unsigned long i)
{
   i = i*100000;
   for (i =0; i<100000; i++);
}


#endif