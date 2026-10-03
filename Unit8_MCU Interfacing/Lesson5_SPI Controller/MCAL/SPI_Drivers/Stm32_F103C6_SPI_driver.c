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
	tempCR2 |= SPI_Config->NSS ;
		
	//SPI BaudratePrescaler
	tempCR1 |= SPI_Config->BaudratePrescaler ;
		
	//SPI IRQ_Enable
	tempCR1 |= SPI_Config->IRQ_Enable ;
	
	

	
}




/**================================================================
 * @Fn				-MCAL_SPI_Deinit
 * @brief 			-DeInitializes a given SPI register
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @retval 			-None
 */
void MCAL_SPI_Deinit(SPI_Typedef *SPIx)
{
}




/**================================================================
 * @Fn				-MCAL_SPI_Set_Pins
 * @brief 			-Sets the pins for the given SPI peripheral according to the recommended GPIO settings
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @retval 			-None
 */
void MCAL_SPI_Set_Pins(SPI_Typedef *SPIx)
{
}




/**================================================================
 * @Fn				-MCAL_SPI_SendData
 * @brief 			-Sends data through the chosen SPI peripheral given the data buffer it needs to send
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @param [in] 		-pTxBuffer : This contains the information the user wants to be sent
 * @param [in] 		-PollingEn : can be picked based on @ref SPI_Polling_Mechanism, determines if polling will occur
 * @retval 			-None
 */
void MCAL_SPI_SendData(SPI_Typedef *SPIx, uint16_t *pTxBuffer, enum PollingMechanism PollingEn)
{
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
}




/**================================================================
 * @Fn				-MCAL_SPI_TX_RX
 * @brief 			-Sends or receives data by over-writing on the same text buffer given by the user
 * @param [in] 		-SPIx : where x can be 1 or 2 depending on the choice of peripheral
 * @param [in] 		-pTxRxBuffer : This contains the information the user is going to receive or send
 * @param [in] 		-PollingEn : can be picked based on @ref SPI_Polling_Mechanism, determines if polling will occur
 * @retval 			-None
 */
void MCAL_SPI_TX_RX(SPI_Typedef *SPIx, uint16_t *pTxRxBuffer, enum PollingMechanism PollingEnable)
{
}


