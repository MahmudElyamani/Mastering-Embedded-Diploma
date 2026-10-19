/**================================================================
 * @file           :stm32f103c8.h
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 11th, 2026
 * @brief          :Header file for stm32f103c8 peripherals 
 *
 *=================================================================*/


#ifndef STM32F103C8_H_
#define STM32F103C8_H_


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Includes
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include <stdlib.h>
#include <stdint.h>


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Base Addresseses
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define PORTA_BASE			0x40010800UL
#define PORTB_BASE			0x40010C00UL
#define PORTC_BASE			0x40011000UL
#define PORTD_BASE			0x40014000UL
#define PORTE_BASE			0x40018000UL

#define AFIO_BASE			0x40010000UL

#define RCC_BASE			0x40021000UL

#define NVIC_BASE			0xE000E100UL

#define EXTI_BASE			0x40010400UL

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t		CRL;
	volatile uint32_t		CRH;
	volatile uint32_t		IDR;
	volatile uint32_t		ODR;
	volatile uint32_t		BSRR;
	volatile uint32_t		BRR;
	volatile uint32_t		LCKR;
}GPIO_t;



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t		EVCR;
	volatile uint32_t		MAPR;
	volatile uint32_t		EXTICR1;
	volatile uint32_t		EXTICR2;
	volatile uint32_t		EXTICR3;
	volatile uint32_t		EXTICR4;
	uint32_t				Reserved;
	volatile uint32_t		MAPR2;
}AFIO_t;



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t		CR;
	volatile uint32_t		CFGR;
	volatile uint32_t		CIR;
	volatile uint32_t		APB2RSTR;
	volatile uint32_t		APB1RSTR;
	volatile uint32_t		AHBENR;
	volatile uint32_t		APB2ENR;
	volatile uint32_t		APB1ENR;
	volatile uint32_t		RCC_BDCR;
	volatile uint32_t		RCC_CSR;
}RCC_t;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: NVIC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t		ISER0;
	volatile uint32_t		ISER1;
	volatile uint32_t		ISER2;
	volatile uint32_t		ICER0;
	volatile uint32_t		ICER1;
	volatile uint32_t		ICER2;
}NVIC_t;



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: NVIC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t		IMR;
	volatile uint32_t		EMR;
	volatile uint32_t		RTSR;
	volatile uint32_t		FTSR;
	volatile uint32_t		SWIER;
	volatile uint32_t		PR;
}EXTI_t;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA		((GPIO_t*)PORTA_BASE)
#define GPIOB		((GPIO_t*)PORTB_BASE)
#define GPIOC		((GPIO_t*)PORTC_BASE)
#define GPIOD		((GPIO_t*)PORTD_BASE)
#define GPIOE		((GPIO_t*)PORTE_BASE)

#define AFIO		((AFIO_t*)AFIO_BASE)

#define RCC			((RCC_t*)RCC_BASE)

#define NVIC		((NVIC_t*)NVIC_BASE)

#define EXTI 		((EXTI_t*)EXTI_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*







#endif
