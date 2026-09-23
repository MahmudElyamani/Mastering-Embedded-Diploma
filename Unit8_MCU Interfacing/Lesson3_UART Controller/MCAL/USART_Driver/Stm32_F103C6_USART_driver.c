/**================================================================
 * @file           :Stm32_F103C6_USART_driver.c
 * @author         :Mahmoud Elyamani
 * @Date		   		 :Sep 23rd, 2026
 * @brief          :USART Driver source files
 *
 *=================================================================*/

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "Stm32_F103C6_USART_driver.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Generic Variables:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

UART_Config* Global_UART_Config = NULL;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Generic Functions:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*




//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//					APIs
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*


/**================================================================
 * @Fn							-MCAL_UART_Init
 * @brief 					-Initializes UART protocol
 * @param [in] 			-USARTx: where x can be (1..3 depending on device used)
 * @param [in] 			-UART_Config: decepts the configured UART modes
 * @retval 					-None
 */

void MCAL_UART_Init(USART_Typedef* USARTx, UART_Config* UART_Config)
{
	uint32_t	pclk, BRR;				//Variables for baud rate register settings
	Global_UART_Config = UART_Config;
	
	//enable the clock for the fiven USART peripheral
	if (USARTx == USART1)
		RCC_USART1_CLK_EN();
	else if (USARTx == USART2)
		RCC_USART2_CLK_EN();
	else if (USARTx == USART3)
		RCC_USART3_CLK_EN();
	
	//Enable USART module
	//Bit 13 UE: USART enable
	USARTx->CR1 |= 1<<13;
	
	//Enable USART Tx and RX engines according to the USART_Mode configuration item
	USARTx->CR1 |= UART_Config->USART_Mode;
	
	//Payload Width
	USARTx->CR1 |= UART_Config->Payload_Length;
	
	//Configure Parity control bit fields
	USARTx->CR1 |= UART_Config->Pairity;
	
	//configure the number of stop bits
	USARTx->CR2 |= UART_Config->StopBits;
	
	//USART hardware flow control
	USARTx->CR3	|= UART_Config->HwFlowCtl;
	
	//Configuration for Baud Rate BRR
	//PCLK1 for USART2 , USART3
	//PCLK2 for USART1
	if (USARTx == USART1)
	{
		pclk = MCAL_RCC_GetPCLK2Freq();
	}
	else
	{
		pclk = MCAL_RCC_GetPCLK1Freq();
	}
	BRR = UART_BRR_Register(pclk, UART_Config->BaudRate);
	USARTx->BRR = BRR;
	
	//Enable / Disable Interrupt
	//USART_CR1
	if(UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
	{
		USARTx-> CR1 |= (UART_Config->IRQ_Enable) ;
		
		//Enable NVIC for USARTx IRQ
		if (USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;
		else if (USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;
		else if (USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}

}



/**================================================================
 * @Fn							-MCAL_UART_DeInit
 * @brief 					-De-initializes the given UART configuration
 * @param [in] 			-USARTx
 * @retval 					-None
 */
void MCAL_UART_DeInit(USART_Typedef* USARTx)
{
	if (USARTx == USART1)
	{
		RCC_USART1_CLK_Reset();
		NVIC_IRQ37_USART1_Disable;
	}
	else if (USARTx == USART2)
	{
		RCC_USART2_CLK_Reset();
		NVIC_IRQ38_USART2_Disable;
	}
	else if (USARTx == USART3)
	{
		RCC_USART3_CLK_Reset();
		NVIC_IRQ39_USART3_Disable;
	}
}



/**================================================================
 * @Fn							-MCAL_UART_SendData
 * @brief 					-Function responsible for sending data buffer through UART 
 * @param [in] 			-USARTx
 * @param [in] 			-*pTxBuffer
 * @param [in] 			-PollingEn
 * @retval 					-None
 * @Note:						-Should Initialize UART First
 */
void MCAL_UART_SendData	(USART_Typedef* USARTx, uint16_t* pTxBuffer, enum Polling_mechanism PollingEn)
{
	//wait til TXE flag is set in the SR
	if (PollingEn == enable)
		while(! (USARTx->SR & 1<<7) );
	
	//Check the USART_WordLength item for 9BIT or 8BIT in frame
	if(Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
	{
		USARTx->DR = (*pTxBuffer & (uint16_t)0x01FF);
	}
	else
	{
		USARTx->DR = (*pTxBuffer & (uint8_t)0xFF);
	}
}



/**================================================================
 * @Fn							-MCAL_UART_WAIT_TC
 * @brief 					-Waits for transmission to complete
 * @param [in] 			-*USARTx
 * @retval 					-None
 */

void MCAL_UART_WAIT_TC (USART_Typedef *USARTx)
{
	//wait til TC flag is set in the SR
	while( !(USARTx->SR & 1<<6) );
}




/**================================================================
 * @Fn							-MCAL_UART_ReceiveData
 * @brief 					-Receives data from UART
 * @param [in] 			-*USARTx
 * @param [in] 			-*pTxBuffer
 * @param [in] 			-PollingEn
 * @retval 					-None
 */
void MCAL_UART_ReceiveData	(USART_Typedef* USARTx, uint16_t* pRxBuffer, enum Polling_mechanism PollingEn)
{
	//wait until RXNE bit is set, or data has been received
	if(PollingEn == enable)
	{
		while ( ! (USARTx->SR & 1<<5 ));
	}
	//check the USART_WordLength item for 9BIT or 8BIT in a frame
	if (Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
	{
		if(Global_UART_Config->Pairity == UART_Pairity_NONE)
		{
			//no pairity so all 9 bits are considered data
			*((uint16_t*) pRxBuffer) = USARTx->DR;
		}
		else
		{
			//pairity is used, so 8bits will be of user data and 1 bit is pairity
			*((uint16_t*)  pRxBuffer) = (USART1->DR & (uint8_t)0xFF );
		}
	}
	else
	{
		if(Global_UART_Config->Pairity == UART_Pairity_NONE)
		{
			//no pairity so all 9 bits are considered data
			*((uint16_t*) pRxBuffer) = (USARTx->DR & (uint8_t)0xFF );
		}
		else
		{
			//pairity is used, so 8bits will be of user data and 1 bit is pairity
			*((uint16_t*)  pRxBuffer) = (USART1->DR & (uint8_t)0x7F );
		}
	}
}






/**================================================================
 * @Fn							-MCAL_UART_GPIO_Set_Pins
 * @brief 					-Initializes GPIO pins, should enable the correct ALT and GPIO in RCC clock also called after MCAL_UART_init()
 * @param [in] 			-*USARTx
 * @retval 					-None
 */

void MCAL_UART_GPIO_Set_Pins(USART_Typedef* USARTx)
{
	GPIO_PinConfig_t PinCfg;
	if (USARTx == USART1)
	{
		//Recommended AFIO Settings:
		//PA9 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);
		
		//PA10 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);
		
		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PA11 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		
		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PA12 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}
	
	
	else if (USARTx == USART2)
	{
		//Recommended AFIO Settings:
		//PA2 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_2;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);
		
		//PA3 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_3;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);
		
		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PA0 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_0;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		
		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PA1 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_1;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}
	
	
	else if (USARTx == USART3)
	{
		//Recommended AFIO Settings:
		//PB10 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &PinCfg);
		
		//PB11 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOB, &PinCfg);
		
		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PB13 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
		
		if(Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_CTS || Global_UART_Config->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			//PA14 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		
	}
}



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//						ISR
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void USART1_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack();
}


void USART2_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

void USART3_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack();
}