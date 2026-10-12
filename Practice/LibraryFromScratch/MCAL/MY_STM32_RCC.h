/**================================================================
 * @file           :MY_STM32_RCC.h
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 12th, 2026
 * @brief          :RCC Library header file which contains all supported APIs user is allowed to use.
 *
 *=================================================================*/
 #ifndef MY_STM32_RCC_H_
 #define MY_STM32_RCC_H_
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //Includes:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 #include <stdlib.h>
 #include <stdint.h>
 #include "stm32f103c8.h"
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //Config Register:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 
 
 
 
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //References:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 enum 
 {
	 RCC_AFIO,
	 RCC_GPIOA,
	 RCC_GPIOB,
	 RCC_GPIOC,
	 RCC_GPIOD,
	 RCC_GPIOE,
	 RCC_GPIOF,
	 RCC_GPIOG,
	 RCC_ADC1,
	 RCC_ADC2,
	 RCC_TIM1,
	 RCC_SPI1,
	 RCC_TIM8,
	 RCC_USART1,
	 RCC_ADC3,
	 RCC_TIM9,
	 RCC_TIM10,
	 RCC_TIM11,
	 RCC_TIM2,
	 RCC_TIM3,
	 RCC_TIM4,
	 RCC_TIM5,
	 RCC_TIM7,
	 RCC_TIM12,
	 RCC_TIM13,
	 RCC_TIM14,
	 RCC_WWDG,
	 RCC_SPI2,
	 RCC_SPI3,
	 RCC_USART2,
	 RCC_USART3,
	 RCC_UART4,
	 RCC_UART5,
	 RCC_I2C1,
	 RCC_I2C2,
	 RCC_USB,
	 RCC_CAN,
	 RCC_BKP,
	 RCC_PWR,
	 RCC_DAC
 }RCC_Peripherals;

 
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //			APIs Supported by MY_STM32_GPIO.h:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 void RCC_CLK_SET(uint8_t Peripheral, uint8_t Value);
 
 #endif
 