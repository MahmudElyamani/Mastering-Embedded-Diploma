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
 typedef struct
 {
	uint8_t Clock_Select;	//Specifies the clock the MCU will operate on
							//Can be chosen based on @ref RCC_CLOCK_SELECT
	 
	uint8_t AHB_PRESCALER;	//Specifies the pre-scaler value for AHB bus peripherals 
							//Can be chosen based on @ref AHB_PRE_SCALERS
	 
	uint8_t APB1_PRESCALER;	//Specifies the pre-scaler value for APB1 bus peripherals 
							//Can be chosen based on @ref APB1_PRE_SCALERS
	 
	uint8_t APB2_PRESCALER;	//Specifies the pre-scaler value for APB2 bus peripherals 
							//Can be chosen based on @ref APB2_PRE_SCALERS
 }RCC_Config_t;
 
 
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //References:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 
 //@ref RCC_CLOCK_SELECT
 #define RCC_HSI_CLK	0x0U
 #define RCC_HSE_CLK	0x1U
 #define RCC_PLL_CLK	0x2U	//Not supported Yet.
 
 
 
 //@ref AHB_PRE_SCALERS
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
#define AHB_PRESCALER_1			0x00U
#define AHB_PRESCALER_2			0x08U
#define AHB_PRESCALER_4			0x09U
#define AHB_PRESCALER_8			0x10U
#define AHB_PRESCALER_16		0x11U
#define AHB_PRESCALER_64		0x12U
#define AHB_PRESCALER_128		0x13U
#define AHB_PRESCALER_256		0x14U
#define AHB_PRESCALER_512		0x15U




//@ref APB1_PRE_SCALERS
//Set and cleared by software to control the division factor of the APB low-speed clock 
//(PCLK1).
//Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
#define APB1_PRESCALER_1		0x00U
#define APB1_PRESCALER_2		0x04U
#define APB1_PRESCALER_4		0x05U
#define APB1_PRESCALER_8		0x06U
#define APB1_PRESCALER_16		0x07U





//@ref APB2_PRE_SCALERS
//PPRE2: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB high-speed clock 
//(PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
#define APB2_PRESCALER_1		0x00U
#define APB2_PRESCALER_2		0x04U
#define APB2_PRESCALER_4		0x05U
#define APB2_PRESCALER_8		0x06U
#define APB2_PRESCALER_16		0x07U


 
//@ref RCC_Peripherals
 typedef enum 
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
 void RCC_CLK_INIT(RCC_Config_t *ConfigRegister);
 void RCC_CLK_SET(uint8_t Peripheral, uint8_t Value);
 
 #endif
 