/**================================================================
 * @file           :main.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 11th, 2026
 * @brief          :Library implementation for stm32 from scratch without using video guides
 *
 *=================================================================*/
#include "stm32f103c8.h"
#include "MY_STM32_GPIO.h"
#include "MY_STM32_RCC.h"
#include "MY_STM32_EXTI.h"

void IRQ_Test_LED()
{
	GPIO_Toggle(GPIOA, PIN_5);
}

void Mydelay (uint32_t MS_Time)
{
	volatile uint32_t i = MS_Time;
	volatile uint32_t j = 0;
	for (i = MS_Time; i>0; i--)
	for (j = 500; j>0; j--);

}

int main()
{
	EXTI_Config_t Exti_cnfg;
	Exti_cnfg.GPIO_PIN = PIN_15;
	Exti_cnfg.GPIO_PORT = PORTC;
	Exti_cnfg.Trigger_Case = Falling_Edge;
	Exti_cnfg.P_IRQ_CallBack = IRQ_Test_LED;
	Exti_cnfg.IRQ_EN = EXTI_IRQ_Enable;
	EXTI_Init(&Exti_cnfg);
	
	//Clock Config, PLL clock (PLL), AHB frequency = 72MHZ, APB1 frequency = 36MHZ, APB2 frequency = 72MHZ
	RCC_Config_t RCC_Cnfg;
	
	RCC_Cnfg.Clock_Select = RCC_PLL_CLK;
	RCC_Cnfg.PLL_SOURCE = PLL_SRC_HSE_DivBy2;
	RCC_Cnfg.PLL_FACTOR = PLL_CLK_FACTOR_9;
	RCC_Cnfg.AHB_PRESCALER = AHB_PRESCALER_1;
	RCC_Cnfg.APB1_PRESCALER = APB1_PRESCALER_2;
	RCC_Cnfg.APB2_PRESCALER = APB2_PRESCALER_1;
	RCC_CLK_INIT(&RCC_Cnfg);
	
	GPIO_Config_t ConfigRegister;
	
	//Port A, Pin 8, Output, Push Pull, 10MHZ
	ConfigRegister.PinNumber = PIN_8;
	ConfigRegister.Mode = Output_push_pull;
	ConfigRegister.OutputSpeed = Speed_10MHZ;
	GPIO_Init(GPIOA, &ConfigRegister);
	
	//Port A, Pin 5, Output, Open Drain, 50MHZ
	ConfigRegister.PinNumber = PIN_5;
	ConfigRegister.Mode = Output_push_pull;
	ConfigRegister.OutputSpeed = Speed_50MHZ;
	GPIO_Init(GPIOA, &ConfigRegister);
	
	
	while(1)
	{
		GPIO_Toggle(GPIOA, PIN_8);
		Mydelay(500);
		GPIO_Toggle(GPIOA, PIN_8);
		Mydelay(500);
	}
}
