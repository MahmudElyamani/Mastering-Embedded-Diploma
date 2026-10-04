/**================================================================
 * @file           :Stm32_F103C6_SPI_driver.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 3rd, 2026
 * @brief          :Source file for the SPI driver for STM32
 *
 *=================================================================*/
#include "Stm32_F103C6_SPI_driver.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Generic Variables:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

SPI_Config* Global_SPI_Config[2]  =  {NULL, NULL};

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define			SPI1_INDEX			0
#define			SPI2_INDEX			1

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//			APIS:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*



/**================================================================
 * @Fn				-MCAL_SPI_Init
 * @brief 			-Initializes a given SPI register using the set configurations chosen by the user
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @param [in] 		-SPI_Config : contains the configurations set by the user
 * @retval 			-None
 */
void MCAL_SPI_Init (SPI_Typedef *SPIx, SPI_Config *SPI_Config)
{
	//Temporary variable to avoid bugs, we will be writing its value onto the actual register at the end.
	uint16_t  tempCR1 = NULL;
	uint16_t  tempCR2 = NULL;
	if (SPIx == SPI1)
	{
		Global_SPI_Config[SPI1_INDEX] = SPI_Config;
		RCC_SPI1_CLK_EN();
	}
	else if (SPIx == SPI2)
	{
		Global_SPI_Config[SPI2_INDEX] = SPI_Config;
		RCC_SPI2_CLK_EN();
	}
	//Enable SPI CR1:Bit 6 SPI enable
	tempCR1 = (0x1U<<6);
	
	//Master or slave
	tempCR1 |= SPI_Config->Device_Mode ;
	
	//SPI Frame Format
	tempCR1 |= SPI_Config->Frame_Format ;
		
	//SPI DataSize
	tempCR1 |= SPI_Config->DataSize ;
		
	//SPI CLKPolarity
	tempCR1 |= SPI_Config->CLKPolarity ;
		
	//SPI CLKPhase
	tempCR1 |= SPI_Config->CLKPhase ;
		
	//SPI NSS
	if (SPI_Config->NSS == SPI_NSS_Hard_Master_Enable)
	{
		tempCR2 |= SPI_Config->NSS;
	}
	else if (SPI_Config->NSS == SPI_NSS_Hard_Master_Disable)
	{
		tempCR2 &= SPI_Config->NSS;
	}
	else
	{
		tempCR1 |= SPI_Config->NSS;
	}
	
	//SPI BaudratePrescaler
	tempCR1 |= SPI_Config->BaudratePrescaler ;
		
	//SPI IRQ_Enable
	if (SPI_Config->IRQ_Enable != SPI_IRQ_ENABLE_NONE)
	{
		tempCR2 |= SPI_Config->IRQ_Enable;
		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}
		else if (SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}
	
	SPIx->CR1 = tempCR1;
	SPIx->CR2 = tempCR2;

}




/**================================================================
 * @Fn				-MCAL_SPI_Deinit
 * @brief 			-DeInitializes a given SPI register
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @retval 			-None
 */
void MCAL_SPI_Deinit(SPI_Typedef *SPIx)
{
	if (SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_CLK_Reset();
	}
	else if (SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_CLK_Reset();
	}
}




/**================================================================
 * @Fn				-MCAL_SPI_Set_Pins
 * @brief 			-Sets the pins for the given SPI peripheral according to the recommended GPIO settings
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @retval 			-None
 */
void MCAL_SPI_Set_Pins(SPI_Typedef *SPIx)
{
	if ( SPIx == SPI1)
	{
		if (Global_SPI_Config[SPI1_INDEX]->Device_Mode == SPI_MODE_MASTER)
		{
			//NSS:
			switch (Global_SPI_Config[SPI1_INDEX]->NSS)
			{
				case SPI_NSS_Hard_Master_Disable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
				case SPI_NSS_Hard_Master_Enable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
			}
			//PA5: SPI1_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
			
			//PA6: SPI1_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
			
			//PA7: SPI1_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
		else
		{
			//NSS
			if (Global_SPI_Config[SPI1_INDEX]->NSS == SPI_NSS_Hard_Slave)
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
			}
			// PA5 : SPI1_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
			
			// PA6 : SPI1_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
			
			// PA6 : SPI1_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}
	else if ( SPIx == SPI2)
	{
		if (Global_SPI_Config[SPI2_INDEX]->Device_Mode == SPI_MODE_MASTER)
		{
			//NSS:
			switch (Global_SPI_Config[SPI2_INDEX]->NSS)
			{
				case SPI_NSS_Hard_Master_Disable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
				case SPI_NSS_Hard_Master_Enable:
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
			}
			//PA5: SPI2_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
			
			//PA6: SPI2_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
			
			//PA7: SPI2_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
		else
		{
			//NSS
			if (Global_SPI_Config[SPI2_INDEX]->NSS == SPI_NSS_Hard_Slave)
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
			}
			// PA5 : SPI2_SCK
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
			
			// PA6 : SPI2_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
			
			// PA6 : SPI2_MOSI
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
	}
}




/**================================================================
 * @Fn				-MCAL_SPI_SendData
 * @brief 			-Sends data through the chosen SPI peripheral given the data buffer it needs to send
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @param [in] 		-pTxBuffer : This contains the information the user wants to be sent
 * @param [in] 		-PollingEn : can be picked based on @ref SPI_Polling_Mechanism, determines if polling will occur
 * @retval 			-None
 */
#define SPI_SR_TXE					((uint8_t)0x02)			//Transmit buffer empty
#define SPI_SR_RXNE					((uint8_t)0x01)			//Receive buffer not empty
void MCAL_SPI_SendData(SPI_Typedef *SPIx, uint16_t *pTxBuffer, enum PollingMechanism PollingEn)
{
	if (PollingEn == pollingEnable)
		while(!((SPIx)->SR & SPI_SR_TXE));
	
	SPIx->DR = *pTxBuffer;
}




/**================================================================
 * @Fn				-MCAL_SPI_ReceiveData
 * @brief 			-Receives data from the chosen SPI peripheral given the data buffer it will receive on
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @param [in] 		-pRxBuffer : This contains the information the user is going to receive
 * @param [in] 		-PollingEn : can be picked based on @ref SPI_Polling_Mechanism, determines if polling will occur
 * @retval 			-None
 */
void MCAL_SPI_ReceiveData(SPI_Typedef *SPIx, uint16_t *pRxBuffer, enum PollingMechanism PollingEn)
{
	if (PollingEn == pollingEnable)
		while(!((SPIx)->SR & SPI_SR_RXNE));
	
	*pRxBuffer = SPIx->DR;
}




/**================================================================
 * @Fn				-MCAL_SPI_TX_RX
 * @brief 			-Sends or receives data by over-writing on the same text buffer given by the user
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @param [in] 		-pTxRxBuffer : This contains the information the user is going to receive or send
 * @param [in] 		-PollingEn : can be picked based on @ref SPI_Polling_Mechanism, determines if polling will occur
 * @retval 			-None
 */
void MCAL_SPI_TX_RX(SPI_Typedef *SPIx, uint16_t *pTxRxBuffer, enum PollingMechanism PollingEn)
{
	if (PollingEn == pollingEnable)
		while(!((SPIx)->SR & SPI_SR_TXE));
	SPIx->DR = *pTxRxBuffer;
	
	if (PollingEn == pollingEnable)
		while(!((SPIx)->SR & SPI_SR_RXNE));
	*pTxRxBuffer = SPIx->DR;
}



//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//			IRQ:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void SPI1_IRQHandler (void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE = ( (SPI1->SR & (1<<1)) >> 1);
	irq_src.RXNE = ( (SPI1->SR & (1<<0)) >> 0);
	irq_src.ERRI = ( (SPI1->SR & (1<<4)) >> 4);
	
	Global_SPI_Config [SPI1_INDEX]->IRQ_CallBack(irq_src);
}

void SPI2_IRQHandler (void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE = ( (SPI2->SR & (1<<1)) >> 1);
	irq_src.RXNE = ( (SPI2->SR & (1<<0)) >> 0);
	irq_src.ERRI = ( (SPI2->SR & (1<<4)) >> 4);
	
	Global_SPI_Config [SPI2_INDEX]->IRQ_CallBack(irq_src);
}


