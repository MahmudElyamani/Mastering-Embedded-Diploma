/**================================================================
 * @file           :main.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 11th, 2026
 * @brief          :Library implementation for stm32 from scratch without using video guides
 *
 *=================================================================*/
#include "stm32f103c8.h"
#include "MY_STM32_GPIO.h"

void Mydelay (uint32_t MS_Time)
{
	volatile uint32_t i = MS_Time;
	volatile uint32_t j = 0;
	for (i = MS_Time; i>0; i--)
	for (j = 1000; j>0; j--);

}

int main()
{
	GPIO_Config_t ConfigRegister;
	ConfigRegister.PinNumber = PIN_8;
	ConfigRegister.Mode = Output_push_pull;
	ConfigRegister.OutputSpeed = Speed_10MHZ;
	GPIO_Setup(GPIOA, &ConfigRegister);
	
	while(1)
	{
		GPIO_Set(GPIOA, PIN_8, HIGH);
		Mydelay(1000);
		GPIO_Set(GPIOA, PIN_8, LOW);
		Mydelay(1000);
	}
}
