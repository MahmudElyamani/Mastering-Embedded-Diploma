/**================================================================
 * @file           :MY_STM32_RCC.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 12th, 2026
 * @brief          :RCC Library source code which contains definition for all supported APIs in header file
 *
 *=================================================================*/
#include "MY_STM32_RCC.h"


void RCC_CLK_SET(uint8_t Peripheral, uint8_t Value)
{
	uint32_t *ConfigReg = NULL;
	//Determine whether the register is APB1 or APB2
	if ( Peripheral < RCC_TIM2 ) //APB2
	{
		ConfigReg = (uint32_t*)(Value == 1 ? RCC->APB2ENR : RCC-> APB2RSTR);
		switch (Peripheral)
		{
			case RCC_AFIO:
				*ConfigReg |= (1<<0);
			break;
			case RCC_GPIOA:
				*ConfigReg |= (1<<2);
			break;
			case RCC_GPIOB:
				*ConfigReg |= (1<<3);
			break;
			case RCC_GPIOC:
				*ConfigReg |= (1<<4);
			break;
			case RCC_GPIOD:
				*ConfigReg |= (1<<5);
			break;
			case RCC_GPIOE:
				*ConfigReg |= (1<<6);
			break;
			case RCC_GPIOF:
				*ConfigReg |= (1<<7);
			break;
			case RCC_GPIOG:
				*ConfigReg |= (1<<8);
			break;
			case RCC_ADC1:
				*ConfigReg |= (1<<9);
			break;
			case RCC_ADC2:
				*ConfigReg |= (1<<10);
			break;
			case RCC_TIM1:
				*ConfigReg |= (1<<11);
			break;
			case RCC_SPI1:
				*ConfigReg |= (1<<12);
			break;
			case RCC_TIM8:
				*ConfigReg |= (1<<13);
			break;
			case RCC_USART1:
				*ConfigReg |= (1<<14);
			break;
			case RCC_ADC3:
				*ConfigReg |= (1<<15);
			break;
			case RCC_TIM9:
				*ConfigReg |= (1<<19);
			break;
			case RCC_TIM10:
				*ConfigReg |= (1<<20);
			break;
			case RCC_TIM11:
				*ConfigReg |= (1<<21);
			break;
		}
		RCC->APB2ENR |= *ConfigReg;
	}
	else	//APB1
	{
		ConfigReg = (uint32_t*)(Value == 1 ? RCC->APB1ENR : RCC-> APB1RSTR);
		switch (Peripheral)
		{
			case RCC_SPI2:
				*ConfigReg |= (1<<14);
			break;
			case RCC_SPI3:
				*ConfigReg |= (1<<15);
			break;
			case RCC_I2C1:
				*ConfigReg |= (1<<21);
			break;
			case RCC_I2C2:
				*ConfigReg |= (1<<22);
			break;
		}
	}
	
	
}

