/**================================================================
 * @file           :Stm32_F103C6_EXTI_Driver.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Sep 8th, 2026
 * @brief          :Source file for External interrupt peripheral of STM32F103C6
 *
 *=================================================================*/

#include "Stm32_F103C6_EXTI_Driver.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//:Generic Functions:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
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
	//AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF <<AFIO_EXTICR_Position);
}

/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Init
 * @brief 			-
 * @param [in] 		-*EXTI_Config
 * @retval 			-
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config);



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

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config);