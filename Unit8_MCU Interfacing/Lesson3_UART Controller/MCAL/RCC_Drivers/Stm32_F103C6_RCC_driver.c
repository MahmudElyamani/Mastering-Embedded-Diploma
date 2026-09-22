/**================================================================
 * @file           :Stm32_F103C6_RCC_driver.c
 * @author         :Mahmoud Elyamani
 * @Date		   		 :Sep 22nd, 2026
 * @brief          :Source file for RCC define
 *
 *=================================================================*/
#include "Stm32_F103C6_RCC_driver.h"

uint32_t	MCAL_RCC_GetSYS_CKKFreq(void)	//Determines the System clock frequency value when called
{
}



//Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
//Set and cleared by software to control the division factor of the APB low-speed clock
//(PCLK1).
//Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
const uint8_t	APBPrescTable[8U]	=	{0,0,0,0,1,2,3,4};
	
uint32_t	MCAL_RCC_GetHCLKFreq(void)	//Determines the HCLK value when called
{
	
}



uint32_t	MCAL_RCC_GetPCLK1Freq(void)	//Determines the PCLK1 value when called
{
	return (MCAL_RCC_GetHCLKFreq()  >>  APBPrescTable[(RCC->CFGR >> 8) & 0b111]); //???
}

uint32_t	MCAL_RCC_GetPCLK2Freq(void)	//Determines the PCLK2 value when called
{
	//Bits 13:11 PPRE2
	return (MCAL_RCC_GetHCLKFreq()  >>  APBPrescTable[(RCC->CFGR >> 11) & 0b111]); //???
}

		