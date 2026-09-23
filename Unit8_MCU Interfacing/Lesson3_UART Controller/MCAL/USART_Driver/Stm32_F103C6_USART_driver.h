/**================================================================
 * @file           :Stm32_F103C6_USART_driver.h
 * @author         :Mahmoud Elyamani
 * @Date		   		 :Sep 23rd, 2026
 * @brief          :USART Driver source files
 *
 *=================================================================*/
#ifndef STM32_F103C6_USART_DRIVER_H_
#define STM32_F103C6_USART_DRIVER_H_

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "stm32f103x6.h"
#include "GPIO_Drivers/Stm32_F103C6_gpio_driver.h"
#include "RCC_Drivers/Stm32_F103C6_RCC_driver.h"
#include "EXTI_Driver/Stm32_F103C6_EXTI_Driver.h"


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Configuration Structure:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	uint8_t						USART_Mode;					//Specifies TX/RX Enable/Disable
																				//This parameter must be set based on @ref UART_Mode_define
	
	uint32_t					BaudRate;						//Specifies Baud rate of communication
																				//This parameter must be set based on @ref USART_BaudRate_define
	
	uint8_t						Payload_Length;			//Specifies Baud payload length of the frame
																				//This parameter must be set based on @ref USART_PayLoad_Length_define
	
	uint8_t						Pairity;						//Specifies Pairity bits of the frame
																				//This parameter must be set based on @ref USART_Pairity_define
	
	uint8_t						StopBits;						//Specifies Stop bits of the frame
																				//This parameter must be set based on @ref USART_StopBits_define
	
	uint8_t						HwFlowCtl;					//Specifies Whether the CTS and RTS bits are enabled or not
																				//This parameter must be set based on @ref USART_HwFlowCtl_define
	
	uint8_t						IRQ_Enable;					//Enables or disables IRQ TX/RX
																				//This parameter must be set based on @ref USART_IRQ_Enable_define
	
	void (*P_IRQ_CallBack)(void);					//Set the C Functionwhich willbe called once the IRQ Happens.
}UART_Config;











//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Reference Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//@ref UART_Mode_define
#define		UART_Mode_RX				(uint32_t)(1<<2)						//RE enabled bit2
#define		UART_Mode_TX				(uint32_t)(1<<3)						//TE enabled bit3
#define		UART_Mode_TX_RX			((uint32_t)(1<<3 | 1<<2))		//TE,RE enabled bit3



//@ref UART_BaudRate_define
#define UART_BAUDRate_2400				2400
#define UART_BAUDRate_9600				9600
#define UART_BAUDRate_19200				19200
#define UART_BAUDRate_57600				57600
#define UART_BAUDRate_115200			115200
#define UART_BAUDRate_230400			230400
#define UART_BAUDRate_460800			460800
#define UART_BAUDRate_921600			921600
#define UART_BAUDRate_2250000			2250000
#define UART_BAUDRate_4500000			4500000




//@ref UART_PayLoad_Length_define
#define UART_Payload_Length_8B				(uint32_t)(0)
#define UART_Payload_Length_9B				(uint32_t)(1<<12)




//@ref UART_Pairity_define
#define UART_Pairity_NONE			(uint32_t)(0)
#define UART_Pairity_EVEN			(uint32_t)(1<<10)
#define UART_Pairity_ODD			((uint32_t)(1<<10 | 1<<9))





//@ref UART_StopBits_define
#define	UART_StopBits_half						(uint32_t)(1<<12)
#define	UART_StopBits_1								(uint32_t)(1<<0)
#define	UART_StopBits_1_half					(uint32_t)(3<<12)
#define	UART_StopBits_2								(uint32_t)(2<<12)




//@ref UART_HwFlowCtl_define
#define UART_HwFlowCtl_NONE							(uint32_t)(0)
#define UART_HwFlowCtl_RTS							(uint32_t)(1<<8)
#define UART_HwFlowCtl_CTS							(uint32_t)(1<<9)
#define UART_HwFlowCtl_RTS_CTS					((uint32_t)(1<<8 | 1<<9))




//@ref UART_IRQ_Enable_define
#define UART_IRQ_Enable_NONE							(uint32_t)(0)
#define UART_IRQ_Enable_TXE								(uint32_t)(1<<7)
#define UART_IRQ_Enable_TC								(uint32_t)(1<<6)
#define UART_IRQ_Enable_RXNEIE						(uint32_t)(1<<5)
#define UART_IRQ_Enable_PE								(uint32_t)(1<<8)




//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Baud Rate Calculation Equations:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define USARTDIV(_PCLK_, _BAUD_)												(uint32_t)(_PCLK_/(16*_BAUD_))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)									(uint32_t)( (25 * _PCLK_) / (4 * _BAUD_) ) 
#define Mantissa_MUL100(_PCLK_, _BAUD_)									(uint32_t)(USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)												(uint32_t)(USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)										(uint32_t)(((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_,_BAUD_) ) * 16) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)								(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )

enum Polling_mechanism{
	enable,
	disable
};
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//APIs Supported by "MCAL USART DRIVER":
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void MCAL_UART_Init(USART_Typedef* USARTx, UART_Config* UART_Config);
void MCAL_UART_DeInit(USART_Typedef* USARTx);
void MCAL_UART_GPIO_Set_Pins(USART_Typedef* USARTx);
void MCAL_UART_SendData	(USART_Typedef* USARTx, uint16_t* pTxBuffer, enum Polling_mechanism PollingEn);
void MCAL_UART_ReceiveData	(USART_Typedef* USARTx, uint16_t* pRxBuffer, enum Polling_mechanism PollingEn);
void MCAL_UART_WAIT_TC (USART_Typedef *USARTx);

#endif
