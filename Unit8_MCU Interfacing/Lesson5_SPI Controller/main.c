/**================================================================
 * @file           :main.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 3rd, 2026
 * @brief          :Here is the main function which shows SPI communication for STM32F103C8
 *
 *=================================================================*/

#include "stm32f103x6.h"
#include "GPIO_Drivers/Stm32_F103C6_gpio_driver.h"
#include "EXTI_Driver/Stm32_F103C6_EXTI_Driver.h"
#include "USART_Driver/Stm32_F103C6_USART_driver.h"
#include "SPI_Drivers/Stm32_F103C6_SPI_driver.h"

//#define MCU_Act_As_Slave
#define MCU_Act_As_Master

unsigned short ch;

void Yamani_UART_IRQ_Callback(void)
{
#ifdef MCU_Act_As_Master
	
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
	
	//Reset slave select pin
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	
	MCAL_SPI_TX_RX ( SPI1, &ch, pollingEnable);
	
	//Sets the slave select pin back
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	
#endif
}

int main(void)
{
	UART_Config uartCFG;
	uartCFG.BaudRate = UART_BAUDRate_115200;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE;
	
	uartCFG.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	
	uartCFG.P_IRQ_CallBack = Yamani_UART_IRQ_Callback;
	
	uartCFG.Pairity = UART_Pairity_NONE;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits_1;
	uartCFG.USART_Mode = UART_Mode_TX_RX;
	
	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);
	
	
	//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
    //			SPI Init:
    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
	
	//Common SPI(1) Configuration for master and slave.
	SPI_Config SPI1CFG;
	SPI1CFG.CLKPhase = SPI_CLOCK_PHASE_2ND_EDGE;
	SPI1CFG.CLKPolarity = SPI_CLOCK_POLARITY_IDLE1;
	SPI1CFG.DataSize = SPI_DataSize_8BIT;
	SPI1CFG.Frame_Format = SPI_FRAME_FORMATE_MSB_FIRST;
	SPI1CFG.BaudratePrescaler = SPI_BAUDRATE_PRESCALER_8;
	SPI1CFG.Communication_Mode = SPI_DIRECTION_2LINES;
	
#ifdef MCU_Act_As_Master
	SPI1CFG.Device_Mode = SPI_MODE_MASTER;
	SPI1CFG.IRQ_Enable = SPI_IRQ_ENABLE_NONE;
	SPI1CFG.NSS = SPI_NSS_Software_Set;
	SPI1CFG.IRQ_CallBack = NULL;
#endif

	MCAL_SPI_Init(SPI1, &SPI1CFG);
	MCAL_SPI_Set_Pins(SPI1);
	
	//Configure SS on PA.4 by GPIO
	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &PinCfg);
	
	//Force slave select (High) Idle mode
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	
	/*	Loop Forever  */
	while(1)
	{
	}
}
