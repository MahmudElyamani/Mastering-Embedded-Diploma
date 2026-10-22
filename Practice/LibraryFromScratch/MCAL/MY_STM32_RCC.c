/**================================================================
 * @file           :MY_STM32_RCC.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 12th, 2026
 * @brief          :RCC Library source code which contains definition for all supported APIs in header file
 *
 *=================================================================*/
#include "MY_STM32_RCC.h"



/**================================================================
 * @Fn				-RCC_CLK_INIT
 * @brief 			-Initializes the clock speeds for each bus line and peripherals, only some features are supported.
 * @param [in] 		-ConfigRegister : can be set by the user to indicate the used clock and bus line pre-scalers.
 * @retval 			-None
 */
void RCC_CLK_INIT(RCC_Config_t *CnfgRegister)
{
	RCC->CFGR |= ( (CnfgRegister->Clock_Select)	<<  0 );
	RCC->CFGR |= ( (CnfgRegister->AHB_PRESCALER)  <<  4 );
	RCC->CFGR |= ( (CnfgRegister->APB1_PRESCALER) <<  8 );
	RCC->CFGR |= ( (CnfgRegister->APB2_PRESCALER) <<  11 );
	
	/*		PLL Calculation		*/
	if (CnfgRegister->Clock_Select == RCC_PLL_CLK)
		RCC->CFGR |= ( (CnfgRegister->PLL_FACTOR) << 18 ); //Bits 21:18 PLLMUL: PLL multiplication factor
	
	switch (CnfgRegister->PLL_SOURCE)
	{
		case PLL_SRC_HSI_DivBy2:
		//Bit 16 PLLSRC: PLL entry clock source
		//0: HSI oscillator clock / 2 selected as PLL input clock
		RCC->CFGR &= ~(1<<16);
		break;
		case PLL_SRC_HSE_NotDiv:
		//1: HSE oscillator clock selected as PLL input clock
		//Bit 17 PLLXTPRE: HSE divider for PLL entry
		//0: HSE clock not divided
		RCC->CFGR |=  (1<<16);
		RCC->CFGR &= ~(1<<17);
		break;
		case PLL_SRC_HSE_DivBy2:
		//1: HSE clock divided by 2
		RCC->CFGR |=  (1<<16);
		RCC->CFGR |=  (1<<17);
		break;
	}
	
	if (CnfgRegister->Clock_Select == RCC_HSI_CLK)
		RCC->CR |= 1<<0;			//Bit 0 HSION: Internal high-speed clock enable
	else if (CnfgRegister->Clock_Select == RCC_HSE_CLK)
		RCC->CR |= 1<<16;			//Bit 16 HSEON: HSE clock enable
	else if (CnfgRegister->Clock_Select == RCC_PLL_CLK) /*Not Supported Yet*/
		RCC->CR |= 1<<24;			//Bit 24 PLLON: PLL enable
}





/**================================================================
 * @Fn				-RCC_CLK_SET
 * @brief 			-Enables or disables a given clock peripheral (Peripheral) depending on a given value (Value)
 * @param [in] 		-Peripheral: Indicates the RCC peripheral to be enabled / disabled, can be chosen based on
 *								 @ref RCC_Peripherals
 * @param [in] 		-Value: Indicates the state you want the peripheral to be in,  can be 1(HIGH) or 0(LOW).
 * @retval 			-None
 */

void RCC_CLK_SET(uint8_t Peripheral, uint8_t Value)
{
	volatile uint32_t Configuration;
	//Determine whether the register is APB1 or APB2
	if ( Peripheral < RCC_TIM2 ) //APB2
	{
		switch (Peripheral)
		{
			case RCC_AFIO:
				Configuration = (1<<0);
			break;
			case RCC_GPIOA:
				Configuration = (1<<2);
			break;
			case RCC_GPIOB:
				Configuration = (1<<3);
			break;
			case RCC_GPIOC:
				Configuration = (1<<4);
			break;
			case RCC_GPIOD:
				Configuration = (1<<5);
			break;
			case RCC_GPIOE:
				Configuration = (1<<6);
			break;
			case RCC_GPIOF:
				Configuration = (1<<7);
			break;
			case RCC_GPIOG:
				Configuration = (1<<8);
			break;
			case RCC_ADC1:
				Configuration = (1<<9);
			break;
			case RCC_ADC2:
				Configuration = (1<<10);
			break;
			case RCC_TIM1:
				Configuration = (1<<11);
			break;
			case RCC_SPI1:
				Configuration = (1<<12);
			break;
			case RCC_TIM8:
				Configuration = (1<<13);
			break;
			case RCC_USART1:
				Configuration = (1<<14);
			break;
			case RCC_ADC3:
				Configuration = (1<<15);
			break;
			case RCC_TIM9:
				Configuration = (1<<19);
			break;
			case RCC_TIM10:
				Configuration = (1<<20);
			break;
			case RCC_TIM11:
				Configuration = (1<<21);
			break;
		}
		if (Value == 1)
			RCC->APB2ENR |= Configuration;
		else
			RCC->APB2ENR &= ~(Configuration);
	}
	else	//APB1
	{
		switch (Peripheral)
		{
			case RCC_SPI2:
				Configuration = (1<<14);
			break;
			case RCC_SPI3:
				Configuration = (1<<15);
			break;
			case RCC_I2C1:
				Configuration = (1<<21);
			break;
			case RCC_I2C2:
				Configuration = (1<<22);
			break;
		}
		if (Value == 1)
			RCC->APB1ENR |= Configuration;
		else
			RCC->APB1ENR &= ~(Configuration);
	}
	
}






/**================================================================
 * @Fn				-RCC_CLK_RESET
 * @brief 			-Enables or disables the reset on a given clock peripheral (Peripheral) depending on a given value (Value)
 * @param [in] 		-Peripheral: Indicates the RCC peripheral to enable / disable its reset, can be chosen based on
 *								 @ref RCC_Peripherals
 * @param [in] 		-Value: Indicates the state you want the peripheral to be in,  can be 1(HIGH) or 0(LOW).
 * @retval 			-None
 */
 void RCC_CLK_RESET(uint8_t Peripheral, uint8_t Value)
 {
	volatile uint32_t Configuration;
	//Determine whether the register is APB1 or APB2
	if ( Peripheral < RCC_TIM2 ) //APB2
	{
		switch (Peripheral)
		{
			case RCC_AFIO:
				Configuration = (1<<0);
			break;
			case RCC_GPIOA:
				Configuration = (1<<2);
			break;
			case RCC_GPIOB:
				Configuration = (1<<3);
			break;
			case RCC_GPIOC:
				Configuration = (1<<4);
			break;
			case RCC_GPIOD:
				Configuration = (1<<5);
			break;
			case RCC_GPIOE:
				Configuration = (1<<6);
			break;
			case RCC_GPIOF:
				Configuration = (1<<7);
			break;
			case RCC_GPIOG:
				Configuration = (1<<8);
			break;
			case RCC_ADC1:
				Configuration = (1<<9);
			break;
			case RCC_ADC2:
				Configuration = (1<<10);
			break;
			case RCC_TIM1:
				Configuration = (1<<11);
			break;
			case RCC_SPI1:
				Configuration = (1<<12);
			break;
			case RCC_TIM8:
				Configuration = (1<<13);
			break;
			case RCC_USART1:
				Configuration = (1<<14);
			break;
			case RCC_ADC3:
				Configuration = (1<<15);
			break;
			case RCC_TIM9:
				Configuration = (1<<19);
			break;
			case RCC_TIM10:
				Configuration = (1<<20);
			break;
			case RCC_TIM11:
				Configuration = (1<<21);
			break;
		}
		if (Value == 1)
			RCC->APB2RSTR |= Configuration;
		else
			RCC->APB2RSTR &= ~(Configuration);
	}
	else	//APB1
	{
		switch (Peripheral)
		{
			case RCC_SPI2:
				Configuration = (1<<14);
			break;
			case RCC_SPI3:
				Configuration = (1<<15);
			break;
			case RCC_I2C1:
				Configuration = (1<<21);
			break;
			case RCC_I2C2:
				Configuration = (1<<22);
			break;
		}
		if (Value == 1)
			RCC->APB1RSTR |= Configuration;
		else
			RCC->APB1RSTR &= ~(Configuration);
	}
	
}

