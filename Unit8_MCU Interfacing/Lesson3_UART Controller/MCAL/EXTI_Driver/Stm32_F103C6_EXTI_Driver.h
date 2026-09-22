/**================================================================
 * @file           :Stm32_F103C6_EXTI_Driver.h
 * @author         :Mahmoud Elyamani
 * @Date		   :Sep 8th, 2026
 * @brief          :Header file for External interrupt peripheral of STM32F103C6
 *
 *=================================================================*/

#ifndef STM32_F103C6_EXTI_DRIVER_H_
#define STM32_F103C6_EXTI_DRIVER_H_

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Includes
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "stm32f103x6.h"
#include "GPIO_Drivers/Stm32_F103C6_gpio_driver.h"


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Type definitions supported by MCAL EXTI GPIO Driver:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	uint16_t		ETI_InputLineNumber;
	GPIO_TypeDef 	*GPIO_Port;
	uint16_t		GPIO_PIN;
	uint8_t			IVT_IRQ_Number;
							
}EXTI_GPIO_Mapping_t;

typedef struct
{
	EXTI_GPIO_Mapping_t 		EXTI_PIN;		//Specifies the External Interrupt GPIO Mapping
											//This parameter must be set based on @ref EXTI_define
	
	uint8_t 				Trigger_Case;	//Specifies the rising or falling edge trigger
											//This parameter must be set based on @ref EXTI_TRIGGER_define
	
	uint8_t 				IRQ_EN;			//Specifies whether the interrupt is enabled or disabled
											//This parameter must be set based on @ref EXTI_TRIGGER_define
	
	void( *P_IRQ_CallBack)(void);			//Sets the C function that will be called once the interrupt happens
	
}EXTI_PinConfig_t;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define AFIO_GPIO_EXTI_Mapping(x)		((x == GPIOA)?0x0:\
										(x == GPIOB)?0x1:\
										(x == GPIOC)?0x2:\
										(x == GPIOD)?0x3:0x0)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//NVIC IRQ enable / Disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define NVIC_IRQ6_EXTI0_Enable				(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable				(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable				(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable				(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable				(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable			(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable			(NVIC_ISER1 |= 1<<8)


#define NVIC_IRQ6_EXTI0_Disable					(NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable					(NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable					(NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable					(NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable				(NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable				(NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable			(NVIC_ICER1 |= 1<<8)

//USART
#define NVIC_IRQ37_USART1_Enable			(NVIC_ISER1 |= 1<<5)
#define NVIC_IRQ38_USART2_Enable			(NVIC_ISER1 |= 1<<6)
#define NVIC_IRQ39_USART3_Enable			(NVIC_ISER1 |= 1<<7)

#define NVIC_IRQ37_USART1_Disable			(NVIC_ICER1 |= 1<<5)
#define NVIC_IRQ38_USART2_Disable			(NVIC_ICER1 |= 1<<6)
#define NVIC_IRQ39_USART3_Disable			(NVIC_ICER1 |= 1<<7)


//@ref EXTI_define
/*============================ EXTI0 =========================*/
#define EXTI0PA0                 (EXTI_GPIO_Mapping_t){EXTI0_IRQ, GPIOA, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PB0                 (EXTI_GPIO_Mapping_t){EXTI0_IRQ, GPIOB, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PC0                 (EXTI_GPIO_Mapping_t){EXTI0_IRQ, GPIOC, GPIO_PIN_0, EXTI0_IRQ}
#define EXTI0PD0                 (EXTI_GPIO_Mapping_t){EXTI0_IRQ, GPIOD, GPIO_PIN_0, EXTI0_IRQ}



/*============================ EXTI1 =========================*/
#define EXTI1PA1                 (EXTI_GPIO_Mapping_t){EXTI1_IRQ, GPIOA, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PB1                 (EXTI_GPIO_Mapping_t){EXTI1_IRQ, GPIOB, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PC1                 (EXTI_GPIO_Mapping_t){EXTI1_IRQ, GPIOC, GPIO_PIN_1, EXTI1_IRQ}
#define EXTI1PD1                 (EXTI_GPIO_Mapping_t){EXTI1_IRQ, GPIOD, GPIO_PIN_1, EXTI1_IRQ}



/*============================ EXTI2 =========================*/
#define EXTI2PA2                 (EXTI_GPIO_Mapping_t){EXTI2_IRQ, GPIOA, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PB2                 (EXTI_GPIO_Mapping_t){EXTI2_IRQ, GPIOB, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PC2                 (EXTI_GPIO_Mapping_t){EXTI2_IRQ, GPIOC, GPIO_PIN_2, EXTI2_IRQ}
#define EXTI2PD2                 (EXTI_GPIO_Mapping_t){EXTI2_IRQ, GPIOD, GPIO_PIN_2, EXTI2_IRQ}



/*============================ EXTI3 =========================*/
#define EXTI3PA3                 (EXTI_GPIO_Mapping_t){EXTI3_IRQ, GPIOA, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PB3                 (EXTI_GPIO_Mapping_t){EXTI3_IRQ, GPIOB, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PC3                 (EXTI_GPIO_Mapping_t){EXTI3_IRQ, GPIOC, GPIO_PIN_3, EXTI3_IRQ}
#define EXTI3PD3                 (EXTI_GPIO_Mapping_t){EXTI3_IRQ, GPIOD, GPIO_PIN_3, EXTI3_IRQ}



/*============================ EXTI4 =========================*/
#define EXTI4PA4                 (EXTI_GPIO_Mapping_t){EXTI4_IRQ, GPIOA, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PB4                 (EXTI_GPIO_Mapping_t){EXTI4_IRQ, GPIOB, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PC4                 (EXTI_GPIO_Mapping_t){EXTI4_IRQ, GPIOC, GPIO_PIN_4, EXTI4_IRQ}
#define EXTI4PD4                 (EXTI_GPIO_Mapping_t){EXTI4_IRQ, GPIOD, GPIO_PIN_4, EXTI4_IRQ}



/*============================ EXTI5 =========================*/
#define EXTI5PA5                 (EXTI_GPIO_Mapping_t){EXTI5_IRQ, GPIOA, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PB5                 (EXTI_GPIO_Mapping_t){EXTI5_IRQ, GPIOB, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PC5                 (EXTI_GPIO_Mapping_t){EXTI5_IRQ, GPIOC, GPIO_PIN_5, EXTI5_IRQ}
#define EXTI5PD5                 (EXTI_GPIO_Mapping_t){EXTI5_IRQ, GPIOD, GPIO_PIN_5, EXTI5_IRQ}



/*============================ EXTI6 =========================*/
#define EXTI6PA6                 (EXTI_GPIO_Mapping_t){EXTI6_IRQ, GPIOA, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PB6                 (EXTI_GPIO_Mapping_t){EXTI6_IRQ, GPIOB, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PC6                 (EXTI_GPIO_Mapping_t){EXTI6_IRQ, GPIOC, GPIO_PIN_6, EXTI6_IRQ}
#define EXTI6PD6                 (EXTI_GPIO_Mapping_t){EXTI6_IRQ, GPIOD, GPIO_PIN_6, EXTI6_IRQ}



/*============================ EXTI7 =========================*/
#define EXTI7PA7                 (EXTI_GPIO_Mapping_t){EXTI7_IRQ, GPIOA, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PB7                 (EXTI_GPIO_Mapping_t){EXTI7_IRQ, GPIOB, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PC7                 (EXTI_GPIO_Mapping_t){EXTI7_IRQ, GPIOC, GPIO_PIN_7, EXTI7_IRQ}
#define EXTI7PD7                 (EXTI_GPIO_Mapping_t){EXTI7_IRQ, GPIOD, GPIO_PIN_7, EXTI7_IRQ}



/*============================ EXTI8 =========================*/
#define EXTI8PA8                 (EXTI_GPIO_Mapping_t){EXTI8_IRQ, GPIOA, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PB8                 (EXTI_GPIO_Mapping_t){EXTI8_IRQ, GPIOB, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PC8                 (EXTI_GPIO_Mapping_t){EXTI8_IRQ, GPIOC, GPIO_PIN_8, EXTI8_IRQ}
#define EXTI8PD8                 (EXTI_GPIO_Mapping_t){EXTI8_IRQ, GPIOD, GPIO_PIN_8, EXTI8_IRQ}



/*============================ EXTI9 =========================*/
#define EXTI9PA9                 (EXTI_GPIO_Mapping_t){EXTI9_IRQ, GPIOA, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PB9                 (EXTI_GPIO_Mapping_t){EXTI9_IRQ, GPIOB, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PC9                 (EXTI_GPIO_Mapping_t){EXTI9_IRQ, GPIOC, GPIO_PIN_9, EXTI9_IRQ}
#define EXTI9PD9                 (EXTI_GPIO_Mapping_t){EXTI9_IRQ, GPIOD, GPIO_PIN_9, EXTI9_IRQ}



/*============================ EXTI10 =========================*/
#define EXTI10PA10                 (EXTI_GPIO_Mapping_t){EXTI10_IRQ, GPIOA, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PB10                 (EXTI_GPIO_Mapping_t){EXTI10_IRQ, GPIOB, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PC10                 (EXTI_GPIO_Mapping_t){EXTI10_IRQ, GPIOC, GPIO_PIN_10, EXTI10_IRQ}
#define EXTI10PD10                 (EXTI_GPIO_Mapping_t){EXTI10_IRQ, GPIOD, GPIO_PIN_10, EXTI10_IRQ}



/*============================ EXTI11 =========================*/
#define EXTI11PA11                 (EXTI_GPIO_Mapping_t){EXTI11_IRQ, GPIOA, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PB11                 (EXTI_GPIO_Mapping_t){EXTI11_IRQ, GPIOB, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PC11                 (EXTI_GPIO_Mapping_t){EXTI11_IRQ, GPIOC, GPIO_PIN_11, EXTI11_IRQ}
#define EXTI11PD11                 (EXTI_GPIO_Mapping_t){EXTI11_IRQ, GPIOD, GPIO_PIN_11, EXTI11_IRQ}



/*============================ EXTI12 =========================*/
#define EXTI12PA12                 (EXTI_GPIO_Mapping_t){EXTI12_IRQ, GPIOA, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PB12                 (EXTI_GPIO_Mapping_t){EXTI12_IRQ, GPIOB, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PC12                 (EXTI_GPIO_Mapping_t){EXTI12_IRQ, GPIOC, GPIO_PIN_12, EXTI12_IRQ}
#define EXTI12PD12                 (EXTI_GPIO_Mapping_t){EXTI12_IRQ, GPIOD, GPIO_PIN_12, EXTI12_IRQ}



/*============================ EXTI13 =========================*/
#define EXTI13PA13                 (EXTI_GPIO_Mapping_t){EXTI13_IRQ, GPIOA, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PB13                 (EXTI_GPIO_Mapping_t){EXTI13_IRQ, GPIOB, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PC13                 (EXTI_GPIO_Mapping_t){EXTI13_IRQ, GPIOC, GPIO_PIN_13, EXTI13_IRQ}
#define EXTI13PD13                 (EXTI_GPIO_Mapping_t){EXTI13_IRQ, GPIOD, GPIO_PIN_13, EXTI13_IRQ}



/*============================ EXTI14 =========================*/
#define EXTI14PA14                 (EXTI_GPIO_Mapping_t){EXTI14_IRQ, GPIOA, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PB14                 (EXTI_GPIO_Mapping_t){EXTI14_IRQ, GPIOB, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PC14                 (EXTI_GPIO_Mapping_t){EXTI14_IRQ, GPIOC, GPIO_PIN_14, EXTI14_IRQ}
#define EXTI14PD14                 (EXTI_GPIO_Mapping_t){EXTI14_IRQ, GPIOD, GPIO_PIN_14, EXTI14_IRQ}

	
//@ref EXTI_TRIGGER_define
#define Rising_Edge				0
#define Falling_Edge			1
#define RisingAndFalling		2
	
//@ref EXTI_IRQ_define
#define EXTI_IRQ_Enable			1
#define EXTI_IRQ_Disable		0




//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//APIS Supported by "MCAL GPIO DRIVER"
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config);
void MCAL_EXTI_GPIO_DeInit(void);
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config);



#endif
