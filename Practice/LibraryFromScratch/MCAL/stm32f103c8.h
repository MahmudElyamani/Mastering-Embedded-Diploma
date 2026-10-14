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

#define RCC_BASE			0x40021000UL

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
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA		((GPIO_t*)PORTA_BASE)
#define GPIOB		((GPIO_t*)PORTB_BASE)
#define GPIOC		((GPIO_t*)PORTC_BASE)
#define GPIOD		((GPIO_t*)PORTD_BASE)
#define GPIOE		((GPIO_t*)PORTE_BASE)

#define RCC			((RCC_t*)RCC_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*







#endif
