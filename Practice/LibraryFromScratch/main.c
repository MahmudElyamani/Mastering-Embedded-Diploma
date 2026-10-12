/**================================================================
 * @file           :main.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 11th, 2026
 * @brief          :Library implementation for stm32 from scratch without using video guides
 *
 *=================================================================*/
#include "stm32f103c8.h"
#include "MY_STM32_GPIO.h"

int main()
{
	GPIO_Config_t ConfigRegister;
	ConfigRegister.PinNumber = PIN_8;
	ConfigRegister.Mode = Output_push_pull;
	ConfigRegister.OutputSpeed = Speed_10MHZ;
	//GPIO_Setup(GPIOA, ConfigRegister);
	
	while(1)
	{
		//GPIO_Set(GPIOA, PinNumber);
		//delay(1000);
		//GPIO_Reset(GPIOA, PinNumber);
		//delay(1000);
	}
}
