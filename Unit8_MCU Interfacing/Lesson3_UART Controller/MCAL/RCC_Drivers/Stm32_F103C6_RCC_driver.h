/**================================================================
 * @file           :Stm32_F103C6_RCC_driver.h
 * @author         :Mahmoud Elyamani
 * @Date		   		 :Sep 22nd, 2026
 * @brief          :header file for RCC define
 *
 *=================================================================*/
#ifndef STM32_F103C6_RCC_DRIVER_H_
#define STM32_F103C6_RCC_DRIVER_H_

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "stm32f103x6.h"
#include "GPIO_Drivers/Stm32_F103C6_gpio_driver.h"


uint32_t	MCAL_RCC_GetSYS_CKKFreq(void);	//Determines the System clock frequency value when called
uint32_t	MCAL_RCC_GetHCLKFreq(void);	//Determines the HCLK value when called
uint32_t	MCAL_RCC_GetPCLK1Freq(void);	//Determines the PCLK1 value when called
uint32_t	MCAL_RCC_GetPCLK2Freq(void);	//Determines the PCLK2 value when called

#endif
