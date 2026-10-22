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

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//	Generic Functions:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void (* GP_IRQ_Callback[16])(void);

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*		  ISR Functions	     */
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void EXTI0_IRQHandler(void)
{
   //Clear by writing 1 into bit pnding register (EXTI_PR)
	EXTI->PR = 1<<0;
	//CALL IRQ_CALL
	GP_IRQ_Callback[0]();
}

void EXTI1_IRQHandler(void)
{
	EXTI->PR = 1<<1;
	GP_IRQ_Callback[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR = 1<<2;
	GP_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR = 1<<3;
	GP_IRQ_Callback[3]();
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR = 1<<4;
	GP_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI->PR & (1<<5)) {EXTI->PR = (1<<5); GP_IRQ_Callback[5]();}
	if (EXTI->PR & (1<<6)) {EXTI->PR = (1<<6); GP_IRQ_Callback[6]();}
	if (EXTI->PR & (1<<7)) {EXTI->PR = (1<<7); GP_IRQ_Callback[7]();}
	if (EXTI->PR & (1<<8)) {EXTI->PR = (1<<8); GP_IRQ_Callback[8]();}
	if (EXTI->PR & (1<<9)) {EXTI->PR = (1<<9); GP_IRQ_Callback[9]();}
}


void EXTI15_10_IRQHandler(void)
{
	if (EXTI->PR & (1<<10)) {EXTI->PR = (1<<10); GP_IRQ_Callback[10]();}
	if (EXTI->PR & (1<<11)) {EXTI->PR = (1<<11); GP_IRQ_Callback[11]();}
	if (EXTI->PR & (1<<12)) {EXTI->PR = (1<<12); GP_IRQ_Callback[12]();}
	if (EXTI->PR & (1<<13)) {EXTI->PR = (1<<13); GP_IRQ_Callback[13]();}
	if (EXTI->PR & (1<<14)) {EXTI->PR = (1<<14); GP_IRQ_Callback[14]();}
	if (EXTI->PR & (1<<15)) {EXTI->PR = (1<<15); GP_IRQ_Callback[15]();}
}


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
		NVIC->ISER[0] |= (1<<Peripheral);
	}
	else if ( Peripheral >= 32 && Peripheral < 64 )
	{
		Peripheral -= 32;
		NVIC->ISER[1] |= (1<<Peripheral);
	}
	else if ( Peripheral >= 64 )
	{
		Peripheral -= 64;
		NVIC->ISER[2] |= (1<<Peripheral);
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
		NVIC->ICER[0] |= (1<<Peripheral);
	}
	else if ( Peripheral > 32 && Peripheral < 64 )
	{
		Peripheral -= 32;
		NVIC->ICER[1] |= (1<<Peripheral);
	}
	else if ( Peripheral > 64 )
	{
		Peripheral -= 64;
		NVIC->ICER[2] |= (1<<Peripheral);
	}
}







/**================================================================
 * @Fn				-EXTI_Init
 * @brief 			-
 * @param [in] 		-
 * @retval 			-
 */

void EXTI_Init(EXTI_Config_t *Exti_Cnfg)
{
	volatile uint8_t Pin = Exti_Cnfg->GPIO_PIN;
	volatile uint8_t NVIC_Number = NULL;
	GPIO_Config_t GPIO_Cnfg;
	
	/*		GPIO Configuration		*/
	GPIO_Cnfg.Mode = Input_floating;
	GPIO_Cnfg.PinNumber = Exti_Cnfg->GPIO_PIN;
	switch (Exti_Cnfg->GPIO_PORT)
	{
		case PORTA:
		GPIO_Init(GPIOA, &GPIO_Cnfg);
		break;
		case PORTB:
		GPIO_Init(GPIOB, &GPIO_Cnfg);
		break;
		case PORTC:
		GPIO_Init(GPIOC, &GPIO_Cnfg);
		break;
		case PORTD:
		GPIO_Init(GPIOD, &GPIO_Cnfg);
		break;
		case PORTE:
		GPIO_Init(GPIOE, &GPIO_Cnfg);
		break;
	}
	
	/*		AFIO Assignment		*/
	if (Exti_Cnfg->GPIO_PIN < PIN_4)
	{
		AFIO->EXTICR1 &= ~(0xFu << (Pin*4));
		AFIO->EXTICR1 |= (Exti_Cnfg->GPIO_PORT << (Pin*4));
	}
	else if (Exti_Cnfg->GPIO_PIN <PIN_8)
	{
		Pin -= 4;
		AFIO->EXTICR2 &= ~(0xFu << (Pin*4));
		AFIO->EXTICR2 |= (Exti_Cnfg->GPIO_PORT << (Pin*4));
	}
	else if (Exti_Cnfg->GPIO_PIN <PIN_12)
	{
		Pin -= 8;
		AFIO->EXTICR3 &= ~(0xFu << (Pin*4));
		AFIO->EXTICR3 |= (Exti_Cnfg->GPIO_PORT << (Pin*4));
	}
	else if (Exti_Cnfg->GPIO_PIN <=PIN_15)
	{
		Pin -= 12;
		AFIO->EXTICR4 &= ~(0xFu << (Pin*4));
		AFIO->EXTICR4 |= (Exti_Cnfg->GPIO_PORT << (Pin*4));
	}
	
	
	/*		Update rising edge falling edge triggers		*/
	EXTI->RTSR &= ~(1 << Exti_Cnfg->GPIO_PIN);
	EXTI->FTSR &= ~(1 << Exti_Cnfg->GPIO_PIN);
	if (Exti_Cnfg->Trigger_Case == Rising_Edge)
		EXTI->RTSR |= (1<< Exti_Cnfg->GPIO_PIN);
	else if (Exti_Cnfg->Trigger_Case == Falling_Edge)
		EXTI->FTSR |= (1<< Exti_Cnfg->GPIO_PIN);
	else
	{
		EXTI->RTSR |= (1 << Exti_Cnfg->GPIO_PIN);
		EXTI->FTSR |= (1 << Exti_Cnfg->GPIO_PIN);
	}
	
	/*		call ISR    	*/
	GP_IRQ_Callback[Exti_Cnfg->GPIO_PIN] = Exti_Cnfg->P_IRQ_CallBack;
	
	
	/*		Enable or Disable the interrupt		*/
	switch (Exti_Cnfg->GPIO_PIN)
	{
		case PIN_0:
		NVIC_Number = NVIC_EXTI0;
		break;
		case PIN_1:
		NVIC_Number = NVIC_EXTI1;
		break;
		case PIN_2:
		NVIC_Number = NVIC_EXTI2;
		break;
		case PIN_3:
		NVIC_Number = NVIC_EXTI3;
		break;
		case PIN_4:
		NVIC_Number = NVIC_EXTI4;
		break;
		case PIN_5:
		case PIN_6:
		case PIN_7:
		case PIN_8:
		case PIN_9:
		NVIC_Number = NVIC_EXTI9_5;
		break;
		case PIN_10:
		case PIN_11:
		case PIN_12:
		case PIN_13:
		case PIN_14:
		case PIN_15:
		NVIC_Number = NVIC_EXTI15_10;
		break;
	}
	if (Exti_Cnfg->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1 <<Exti_Cnfg->GPIO_PIN);
		NVIC_Enable(NVIC_Number);
		RCC_CLK_SET(RCC_AFIO, HIGH);
	}
	else
	{
		EXTI->IMR &= ~(1 <<Exti_Cnfg->GPIO_PIN);
		NVIC_Disable(NVIC_Number);
		RCC_CLK_SET(RCC_AFIO, LOW);
	}
		
}
