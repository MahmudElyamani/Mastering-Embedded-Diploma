/**================================================================
 * @file           :Stm32_F103C6_I2C_driver.h
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 3rd, 2026
 * @brief          :header file for the SPI driver for STM32
 *
 *=================================================================*/
 
 #ifndef STM32_F103C6_I2C_DRIVER_H_
 #define STM32_F103C6_I2C_DRIVER_H_
 
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#include "stm32f103x6.h"
#include "GPIO_Drivers/Stm32_F103C6_gpio_driver.h"
#include "RCC_Drivers/Stm32_F103C6_RCC_driver.h"
#include "EXTI_Driver/Stm32_F103C6_EXTI_Driver.h"
 

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Configure Register:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*


struct S_I2C_Slave_Device_Address
{
	uint16_t	Enable_Dual_ADD		;
	uint16_t	Primary_slave_address	;
	uint16_t	Secondary_slave_address	;
	uint32_t	I2C_Addressing_Slave_mode ;	//@ref I2C_Addressing_Slave
	
};

typedef enum //@ref I2C_State_
{
	I2C_EV_STOP,
	I2C_ERROOR_AF,
	I2C_EV_ADDR_Matched,
	I2C_EV_DATA_REQ,
	I2C_EV_DATA_RCV
}Slave_State;

typedef struct
{
	uint32_t				I2C_ClockSpeed;		//Specifies Clock frequency
																		//Can be set according to @ref I2C_SCLK_
	
	uint32_t				StretchMode;			//Specifies Whether clock stretching is enabled or not
																		//Can be set according to @ref I2C_StretchMode_
	
	uint32_t				I2C_Mode;					//Specifies the I2C mode.
																		//Can be set according to @ref I2C_Mode_
	
	struct S_I2C_Slave_Device_Address I2C_Slave_Address;
	
	uint32_t				I2C_Ack_Control;					//Specifies the software/hardware control type for the ACK signal
																						//Can be set according to @ref I2C_ACK_
	
	
	uint32_t				General_Call_Address_Detection;	//Specifies whether general call is enabled or disabled
																									//@ref I2C_ENGC
	
	void(* P_Slave_Event_CallBack)(Slave_State state);	//Goes to the function depending on state
																											//State can be selected accoding to vale @ref I2C_State_
	
	
}I2C_InitTypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Reference Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//@ref I2C_SCLK_
/*
[ Standard Speed (up to 100 kHz) - Fast Speed (up to 400 kHz) ] 
-To Configure the Clock:
1.I2C_CR2.FREQ[5:0} : Peripheral clock frequency
2.Configure clock control register
  *T_high = CCR * T_PCLK1
3.Configure the rise time register:
  * I2C_TRISE
4.Program I2C_CR1 register to enable the peripheral.
*/
#define I2C_SCLK_SM_50K								(0x50000U)
#define I2C_SCLK_SM_100K							(100000U)
#define I2C_SCLK_SM_200K							(200000U)
#define I2C_SCLK_SM_400K							(400000U)



//@ref I2C_StretchMode_
#define I2C_StretchMode_Enable				(0x00000000U)
#define I2C_StretchMode_Disable				I2C_CR1_NOSTRETCH



//@ref I2C_Mode_
#define I2C_Mode_I2C						0x00000000U
#define I2C_Mode_SMBus					I2C_CR1_SMBUS



//@ref I2C_Addressing_Slave
#define I2C_Addressing_Slave_mode_7Bit			0x00000000U
#define I2C_Addressing_Slave_mode_10Bit			(uint16_t)(1<<15)



//@ref I2C_ACK_
#define I2C_Ack_Enable					(I2C_CR1_ACK)
#define I2C_Ack_Disable					((uint16_t)0x0000)


//@ref I2C_ENGC
#define I2C_ENGC_Enable			I2C_CR1_ENGC
#define I2C_ENGC_Disable			0x0000


typedef enum
{
	With_Stop,
	Without_Stop
}Stop_Condition;


typedef enum
{
	Start,
	repeated_start
}Repeated_Start;


typedef enum
{
	Enable,
	Disable
}FunctionalState;



typedef enum
{
	RESET,
	SET
}FlagStatus;



typedef enum
{
	I2C_FLAG_BUSY,
	EV5,
	EV6,
	EV7,
	EV8,
	EV8_1,
	MASTER_BYTE_TRANSMITTING = ((uint32_t)0x00070080)
	
}Status;


typedef enum
{
	I2C_Direction_Transmitter,
	I2C_Direction_Receiver
	
}I2C_Direction;



#define I2C_EVENT_MASTER_BYTE_TRANSMITTING		((uint32_t)0x00070080)
/*
 *
 *===================================================================================
 *
 *                      APIs Supported by "MCAL_I2C_Driver"
 *
 *===================================================================================
 *
 */
 
 void MCAL_I2C_Init(I2C_Typedef* I2Cx, I2C_InitTypeDef *I2C_InitStruct);
 void MCAL_I2C_DeInit(I2C_Typedef* I2Cx);
 void MCAL_I2C_GPIO_Set_Pins (I2C_Typedef *I2Cx);
 void MCAL_I2C_Master_TX (I2C_Typedef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start start);
 void MCAL_I2C_Master_RX (I2C_Typedef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start start);
 void I2C_GenerateStart(I2C_Typedef* I2Cx, FunctionalState NewState, Repeated_Start start);
 FlagStatus I2C_GetFlagStatus(I2C_Typedef *I2Cx, Status flag);
 void I2C_SendAddress (I2C_Typedef I2Cx, uint16_t Address, I2C_Direction Direction);
 void I2C_GenerateSTOP(I2C_Typedef *I2Cx, FunctionalState NewState);
 
 //Slave Interrupt mechanism
 void MCAL_I2C_SlaveSendData( I2C_Typedef *I2Cx, uint8_t data );
 uint8_t MCAL_I2C_SlaveReceiveData( I2C_Typedef *I2Cx );

 #endif