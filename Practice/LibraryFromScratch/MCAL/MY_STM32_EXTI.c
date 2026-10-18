/**================================================================
 * @file           :MY_STM32_EXTI.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 18th, 2026
 * @brief          :EXTI Library header file which contains all supported APIs user is allowed to use.
 *
 *=================================================================*/
#include "MY_STM32_GPIO.h"
#include "MY_STM32_RCC.h"
#include "MY_STM32_EXTI.h"


/**================================================================
 * @Fn				-NVIC_Enable
 * @brief 			-Enables the given NVIC Peripheral
 * @param [in] 		-Peripheral : picked according to @ref NVIC_PERIPHERALS
 * @retval 			-none
 */

void NVIC_Enable(NVIC_Peripherals Peripheral)
{
	//Determines the NVIC register : ISER0, ISER1, ISER2
	//volatile uint32_t *SCRegister = (uint32_t*)(Peripheral < 32 ? NVIC->ISER0 : Peripheral < 64 ? NVIC->ISER1 : NVIC->ISER2);
	if ( Peripheral < 32 )
	{
		NVIC->ISER0 |= (1<<Peripheral);
	}
	else if ( Peripheral > 32 && Peripheral < 64 )
	{
		Peripheral -= 32;
		NVIC->ISER1 |= (1<<Peripheral);
	}
	else if ( Peripheral > 64 )
	{
		Peripheral -= 64;
		NVIC->ISER2 |= (1<<Peripheral);
	}
}






/**================================================================
 * @Fn				-NVIC_Disable
 * @brief 			-Disables the given NVIC Peripheral
 * @param [in] 		-Peripheral : picked according to @ref NVIC_PERIPHERALS
 * @retval 			-none
 */

void NVIC_Disable(NVIC_Peripherals Peripheral)
{
	if ( Peripheral < 32 )
	{
		NVIC->ICER0 |= (1<<Peripheral);
	}
	else if ( Peripheral > 32 && Peripheral < 64 )
	{
		Peripheral -= 32;
		NVIC->ICER1 |= (1<<Peripheral);
	}
	else if ( Peripheral > 64 )
	{
		Peripheral -= 64;
		NVIC->ICER2 |= (1<<Peripheral);
	}
}







/**================================================================
 * @Fn				-EXTI_Init
 * @brief 			-
 * @param [in] 		-
 * @retval 			-
 */

void EXTI_Init(EXTI_Config_t *Exti_Cnfg, GPIO_Config_t *Gpio_Cnfg)
{
}
