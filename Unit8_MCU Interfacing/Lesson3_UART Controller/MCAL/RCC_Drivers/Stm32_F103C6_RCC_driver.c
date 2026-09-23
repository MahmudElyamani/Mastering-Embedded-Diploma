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
//	Bits 3:2 SWS: System clock switch status
//	Set and cleared by hardware to indicate which clock source is used as system clock.
//	00: HSI oscillator used as system clock
//	01: HSE oscillator used as system clock
//	10: PLL used as syste
	
	switch( (RCC->CFGR >>2)& 0b11 )
	{
		case 0:
			return HSI_RC_Clk;
		break;
		case 1:
			return HSE_Clock;
		break;
		case 2:
			return 16000000;
		break;
	}
	return 0;
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
const uint8_t	myAPBPrescTable[8U]		=	{0,0,0,0,1,2,3,4};
const uint8_t	myAHBPrescTable[16U]	=	{0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};
	
uint32_t	MCAL_RCC_GetHCLKFreq(void)	//Determines the HCLK value when called
{
	//Bits 7:4 HPRE: AHB prescaler
	return (MCAL_RCC_GetSYS_CKKFreq()  >>  myAHBPrescTable[(RCC->CFGR >> 8) & 0b111]); //???
}



uint32_t	MCAL_RCC_GetPCLK1Freq(void)	//Determines the PCLK1 value when called
{
	//PRE1 Bits 8:10
	return (MCAL_RCC_GetHCLKFreq()  >>  myAPBPrescTable[(RCC->CFGR >> 8) & 0b111]); //???
}

uint32_t	MCAL_RCC_GetPCLK2Freq(void)	//Determines the PCLK2 value when called
{
	//Bits 13:11 PPRE2 
	return (MCAL_RCC_GetHCLKFreq()  >>  myAPBPrescTable[(RCC->CFGR >> 11) & 0b111]); //???
}

		