/**================================================================
 * @file           :Stm32_F103C6_EXTI_Driver.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Sep 8th, 2026
 * @brief          :Source file for External interrupt peripheral of STM32F103C6
 *
 *=================================================================*/

#include "Stm32_F103C6_EXTI_Driver.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//:Generic Variables:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void (* GP_IRQ_Callback[15])(void);


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//:Generic Functions:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void Enable_NVIC(uint16_t IRQ)
{
	switch (IRQ)
	{
		case 0:
			NVIC_IRQ6_EXTI0_Enable;
		break;
		case 1:
			NVIC_IRQ7_EXTI1_Enable;
		break;
		case 2:
			NVIC_IRQ8_EXTI2_Enable;
		break;
		case 3:
			NVIC_IRQ9_EXTI3_Enable;
		break;
		case 4:
			NVIC_IRQ10_EXTI4_Enable;
		break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_Enable;
		break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ40_EXTI10_15_Enable;
		break;
			
	}
}

void Disable_NVIC(uint16_t IRQ)
{
	switch (IRQ)
	{
		case 0:
			NVIC_IRQ6_EXTI0_Disable;
		break;
		case 1:
			NVIC_IRQ7_EXTI1_Disable;
		break;
		case 2:
			NVIC_IRQ8_EXTI2_Disable;
		break;
		case 3:
			NVIC_IRQ9_EXTI3_Disable;
		break;
		case 4:
			NVIC_IRQ10_EXTI4_Disable;
		break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_Disable;
		break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ40_EXTI10_15_Disable;
		break;
			
	}
}

void Update_EXTI (EXTI_PinConfig_t* EXTI_Config)
{
	//1- Configure GPIO to be AF Input floating
	GPIO_PinConfig_t PinCfg;
	PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinCfg);
	
	//2- Update AFIO to route between EXTI Line with port A,B,C,D
	uint8_t AFIO_EXTICR_index = EXTI_Config->EXTI_PIN.ETI_InputLineNumber / 4;
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.ETI_InputLineNumber % 4)*4;
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) &0x0F) << AFIO_EXTICR_Position);
	
	//3- Update the rising and falling edge detection
	EXTI->RSTR &= ~(1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	
	if (EXTI_Config->Trigger_Case == Rising_Edge)
	{
		EXTI->RSTR |= (1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == Falling_Edge)
	{
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_Case == RisingAndFalling)
	{
		EXTI->RSTR |= (1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
	
	//4- Update interrupt handling CALLBACK
	GP_IRQ_Callback[EXTI_Config->EXTI_PIN.ETI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;
	
	//5- Enable/Disable IRQ
	if (EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
		Enable_NVIC(EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
	else
	{
		EXTI->IMR &= ~(1 << EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
		Disable_NVIC(EXTI_Config->EXTI_PIN.ETI_InputLineNumber);
	}
}

/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Init
 * @brief 			-
 * @param [in] 		-*EXTI_Config
 * @retval 			-
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}



/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_DeInit
 * @brief 			-Resets the corresponding EXTI register and NVIC corresponding mask
 * @param [in] 		-none
 * @retval 			-none
 */

void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR 	= 0x00000000;
	EXTI->EMR 	= 0x00000000;
	EXTI->FTSR 	= 0x00000000;
	EXTI->PR 	= 0xFFFFFFFF;			//Write 1 to clear
	EXTI->RSTR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	
	//Disable EXTI from NVIC
}



/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Update
 * @brief 			-
 * @param [in] 		-*EXTI_Config
 * @retval 			-
 */

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*		  ISR Functions	     */
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void EXTI0_IRQHandler(void)
{
   //Clear by writing 1 into bit pnding register (EXTI_PR)
	EXTI->PR |= 1<<0;
	//CALL IRQ_CALL
	GP_IRQ_Callback[0]();
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR |= 1<<1;
	GP_IRQ_Callback[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR |= 1<<2;
	GP_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR |= 1<<3;
	GP_IRQ_Callback[3]();
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR |= 1<<4;
	GP_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI->PR & (1<<5)) {EXTI->PR |= (1<<5); GP_IRQ_Callback[5]();}
	if (EXTI->PR & (1<<6)) {EXTI->PR |= (1<<6); GP_IRQ_Callback[6]();}
	if (EXTI->PR & (1<<7)) {EXTI->PR |= (1<<7); GP_IRQ_Callback[7]();}
	if (EXTI->PR & (1<<8)) {EXTI->PR |= (1<<8); GP_IRQ_Callback[8]();}
	if (EXTI->PR & (1<<9)) {EXTI->PR |= (1<<9); GP_IRQ_Callback[9]();}
}


void EXTI10_15_IRQHandler(void)
{
	if (EXTI->PR & (1<<10)) {EXTI->PR |= (1<<10); GP_IRQ_Callback[10]();}
	if (EXTI->PR & (1<<11)) {EXTI->PR |= (1<<11); GP_IRQ_Callback[11]();}
	if (EXTI->PR & (1<<12)) {EXTI->PR |= (1<<12); GP_IRQ_Callback[12]();}
	if (EXTI->PR & (1<<13)) {EXTI->PR |= (1<<13); GP_IRQ_Callback[13]();}
	if (EXTI->PR & (1<<14)) {EXTI->PR |= (1<<14); GP_IRQ_Callback[14]();}
	if (EXTI->PR & (1<<15)) {EXTI->PR |= (1<<15); GP_IRQ_Callback[15]();}
}