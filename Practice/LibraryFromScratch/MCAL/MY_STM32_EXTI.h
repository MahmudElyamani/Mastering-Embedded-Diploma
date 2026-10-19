/**================================================================
 * @file           :MY_STM32_EXTI.h
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 18th, 2026
 * @brief          :EXTI Library header file which contains all supported APIs user is allowed to use.
 *
 *=================================================================*/
 #ifndef MY_STM32_EXTI_H_
 #define MY_STM32_EXTI_H_
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //Includes:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 #include <stdlib.h>
 #include <stdint.h>
 #include "MY_STM32_GPIO.h"
 #include "stm32f103c8.h"
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //Config Register:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 
 typedef struct
 {
	 uint8_t 				GPIO_PORT;		//Specifies the rising or falling edge trigger
											//This parameter must be set based on @ref GPIO_PORTS_Define
	 
	 uint8_t 				GPIO_PIN;		//Specifies the rising or falling edge trigger
											//This parameter must be set based on @ref GPIO_PINS
	 
	 uint8_t 				Trigger_Case;	//Specifies the rising or falling edge trigger
											//This parameter must be set based on @ref EXTI_TRIGGER_define
	
	 uint8_t 				IRQ_EN;			//Specifies whether the interrupt is enabled or disabled
											//This parameter must be set based on @ref EXTI_TRIGGER_define
	
	void( *P_IRQ_CallBack)(void);			//Sets the C function that will be called once the interrupt happens
	 
 }EXTI_Config_t;
 

 
 
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //References:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*

 
 //@ref GPIO_PORTS_Define
 #define PORTA					0
 #define PORTB					1
 #define PORTC					2
 #define PORTD					3
 #define PORTE					4
 
 
 
 //@ref EXTI_TRIGGER_define
 #define Rising_Edge			0
 #define Falling_Edge			1
 #define RisingAndFalling		2
	
 //@ref EXTI_IRQ_define
 #define EXTI_IRQ_Enable		1
 #define EXTI_IRQ_Disable		0
 
 //@ref NVIC_PERIPHERALS
 typedef enum 
 {
	 NVIC_WWDG,
	 NVIC_PVD,
	 NVIC_TAMPER,
	 NVIC_RTC,
	 NVIC_FLASH,
	 NVIC_RCC,
	 NVIC_EXTI0,
	 NVIC_EXTI1,
	 NVIC_EXTI2,
	 NVIC_EXTI3,
	 NVIC_EXTI4,
	 NVIC_DMA1_CH1,
	 NVIC_DMA1_CH2,
	 NVIC_DMA1_CH3,
	 NVIC_DMA1_CH4,
	 NVIC_DMA1_CH5,
	 NVIC_DMA1_CH6,
	 NVIC_DMA1_CH7,
	 NVIC_ADC1_2,
	 NVIC_USB_HP_CAN_TX,
	 NVIC_USB_LP_CAN_RX0,
	 NVIC_CAN_RX1,
	 NVIC_CAN_SCE,
	 NVIC_EXTI9_5,
	 NVIC_TIM1_BRK,
	 NVIC_TIM1_UP,
	 NVIC_TIM1_TRG_COM,
	 NVIC_TIM1_CC,
	 NVIC_TIM2,
	 NVIC_TIM3,
	 NVIC_TIM4,
	 NVIC_I2C1_EV,
	 NVIC_I2C1_ER,
	 NVIC_I2C2_EV,
	 NVIC_I2C2_ER,
	 NVIC_SPI1,
	 NVIC_SPI2,
	 NVIC_USART1,
	 NVIC_USART2,
	 NVIC_USART3,
	 NVIC_EXTI15_10,
	 NVIC_RTCAlarm,
	 NVIC_USBWakeup,
	 NVIC_TIM8_BRK,
	 NVIC_TIM8_UP,
	 NVIC_TIM8_TRG_COM,
	 NVIC_TIM8_CC,
	 NVIC_ADC3,
	 NVIC_FSMC,
	 NVIC_SDIO,
	 NVIC_TIM5,
	 NVIC_SPI3,
	 NVIC_UART4,
	 NVIC_UART5,
	 NVIC_TIM6,
	 NVIC_TIM7,
	 NVIC_DMA2_CH1,
	 NVIC_DMA2_CH2,
	 NVIC_DMA2_CH3,
	 NVIC_DMA2_CH4_5
 }NVIC_Peripherals;
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //			APIs Supported by MY_STM32_EXTI.h:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 void NVIC_Enable(NVIC_Peripherals Peripheral);
 void NVIC_Disable(NVIC_Peripherals Peripheral);
 void EXTI_Init(EXTI_Config_t *Exti_Cnfg);
 
 #endif
 