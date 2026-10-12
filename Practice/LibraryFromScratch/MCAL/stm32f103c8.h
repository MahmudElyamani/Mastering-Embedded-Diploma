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
	uint32_t		CRL;
	uint32_t		CRH;
	uint32_t		IDR;
	uint32_t		ODR;
	uint32_t		BSRR;
	uint32_t		BRR;
	uint32_t		LCKR;
}GPIO_t;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	uint32_t		CR;
	uint32_t		CFGR;
	uint32_t		CIR;
	uint32_t		APB2RSTR;
	uint32_t		APB1RSTR;
	uint32_t		AHBENR;
	uint32_t		APB2ENR;
	uint32_t		APB1ENR;
	uint32_t		RCC_BDCR;
	uint32_t		RCC_CSR;
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
