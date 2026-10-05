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
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
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
	
	while(1)
	{
	}
}
