#ifndef STLIB_H_
#define STLIB_H_

#include <stdint.h>
typedef volatile uint32_t vuint32_t;
//Base definitions:

/*      RCC         */
#define RCC_BASE        0x40021000
#define RCC_CR          *(vuint32_t*)(RCC_BASE  + 0x0)      /* Clock control register*/
#define RCC_CFGR        *(vuint32_t*)(RCC_BASE  + 0x04)     /* Clock configuration register */
#define RCC_CIR         *(vuint32_t*)(RCC_BASE  + 0x08)     /* Clock interrupt register */
#define RCC_APB2RSTR    *(vuint32_t*)(RCC_BASE  + 0x0C)     /* APB2 Peripheral reset register */
#define RCC_APB1RSTR    *(vuint32_t*)(RCC_BASE  + 0x10)     /* APB1 Peripheral reset register */
#define RCC_AHBENR      *(vuint32_t*)(RCC_BASE  + 0x14)     /* AHB Peripheral clock enable register*/
#define RCC_APB2ENR     *(vuint32_t*)(RCC_BASE  + 0x18)     /* APB2 Peripheral clock enable register */
#define RCC_APB1ENR     *(vuint32_t*)(RCC_BASE  + 0x1C)     /* APB1 Peripheral clock enable register*/
#define RCC_BDCR        *(vuint32_t*)(RCC_BASE  + 0x20)     /* Backup domain control register */
#define RCC_CSR         *(vuint32_t*)(RCC_BASE  + 0x24)     /* Control/Status register */

/*      GPIO A      */
#define GPIOA_BASE      0x40010800
#define GPIOA_CRL       *(vuint32_t*)(GPIOA_BASE+ 0x00)
#define GPIOA_CRH       *(vuint32_t*)(GPIOA_BASE+ 0x04)
#define GPIOA_IDR       *(vuint32_t*)(GPIOA_BASE+ 0x08)
#define GPIOA_ODR       *(vuint32_t*)(GPIOA_BASE+ 0x0C)


/*		GPIO B		*/
#define GPIOB_BASE		0x40010C00
#define GPIOB_CRL       *(vuint32_t*)(GPIOB_BASE+ 0x00)
#define GPIOB_CRH       *(vuint32_t*)(GPIOB_BASE+ 0x04)
#define GPIOB_IDR       *(vuint32_t*)(GPIOB_BASE+ 0x08)
#define GPIOB_ODR       *(vuint32_t*)(GPIOB_BASE+ 0x0C)

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

void clockinit()
{
	RCC_APB2ENR |= (1<<2);	/* Enable GPIOA clock */
	RCC_APB2ENR |= (1<<3);	/* Enable GPIOB clock */
}

void GPIO_init()
{
	GPIOA_CRL &= 0x0;		/* override the reset state for demonstration purpose */
	GPIOA_CRH &= 0x0;		/* override the reset state for demonstration purpose */

	GPIOA_CRL |= (1<<6);	/* Port A pin 1 high-z input (Already 1 on reset) */
	GPIOA_CRH |= (1<<22);	/* Port A pin 13 high-z input (Already 1 on reset) */

	GPIOB_CRL |= (1<<4);	/* Port B pin 1 push-pull output */
	GPIOB_CRH |= (1<<20);	/* Port B pin 13 push-pull output */
}

void Delayms(volatile unsigned long i)
{
	i *= 1000;
	for (; i>0; i--);
}

#endif /* STLIB_H_ */