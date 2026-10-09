/**================================================================
 * @file           :Stm32_F103C6_I2C_driver.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 3rd, 2026
 * @brief          :Source file for the SPI driver for STM32
 *
 *=================================================================*/
#include "Stm32_F103C6_I2C_driver.h"


/*
 *
 *===================================================================================
 *
 *                      		Generic Variables
 *
 *===================================================================================
 *
 */
 
 I2C_InitTypeDef Global_I2C_Config[2] = {NULL,NULL} ;
 
 
 
 
 
 
 
 
 /*
  *
  *===================================================================================
  *
  *                   				   Generic Macros
  *
  *===================================================================================
  *
  */
	
	#define			I2C1_INDEX	0
	#define			I2C2_INDEX  1
	
	
	
	/*
   *
   *===================================================================================
   *
   *                      						APIs
   *
   *===================================================================================
   *
   */
	 
	
 /**================================================================
  * @Fn							-MCAL_I2C_Init
  * @brief 					-Initializes the I2C Register based on parameters the userset by I2C_InitStruct
  * @param [in] 			-I2Cx : where x can be 1 or 2 according to the desired I2C register
  * @param [in] 			-I2C_InitStruct : This structure should be set by the user according to the desired features.
  * @retval 					-None
  */
 void MCAL_I2C_Init(I2C_Typedef* I2Cx, I2C_InitTypeDef *I2C_InitStruct)
 {
	 uint16_t tempreg = 0, freqrange = 0;
	 uint32_t pclk1 = 8000000;
	 uint16_t result = 0;
	 
	 /*		Enable RCC Clock	*/
	 if (I2Cx == I2C1)
	 {
		 Global_I2C_Config[I2C1_INDEX] = *I2C_InitStruct ;
		 RCC_I2C1_CLK_EN();
	 }
	 else
	 {
		 Global_I2C_Config[I2C2_INDEX] = *I2C_InitStruct ;
		 RCC_I2C2_CLK_EN();
	 }
	 
	 
	 /*			SMBus Support			*/
	 if (I2C_InitStruct->I2C_Mode == I2C_Mode_I2C)
	 {
		 //SMBus supported
		 // I2C_CR2.FREQ[5:0] : Peripheral Clock Frequency
		 tempreg = I2Cx->CR2;												//Get_CRLH_Position the I2Cx CR2 Value
		 tempreg &= ~(I2C_CR2_FREQ_Msk);						//Clears the pre-set frequency value if exists
		 pclk1 = MCAL_RCC_GetPCLK1Freq();						//Get Pclk1 Frequency Value.
		 freqrange = (uint16_t)(pclk1/1000000);			//Set Frequency bits depending on pclk1 value.
		 tempreg |= freqrange;											//adds the frequenct range to tempreg value
		 I2Cx->CR2 = tempreg;												//adds the tempreg value to CR2
		 
		 /*		Configure Clock control register I2C_CCR		*/
		 I2Cx->CR1 &= ~(I2C_CR1_PE) ;
		 tempreg = 0;
		 
		 /*		Configure Speed in standard mode		*/
		 if ( (I2C_InitStruct->I2C_ClockSpeed == I2C_SCLK_SM_50K) || (I2C_InitStruct->I2C_ClockSpeed == I2C_SCLK_SM_100K) )
		 {
			 /*Standard Mode Speed Calculation
			  *	Tclk/2 = CCR * T_pclk1
			  *	CCR = Tclk/(2*T_pclk1)
			  * CCR = F_pclk1 /(2*I2C_ClockFrequency)
			  */
			 result = (uint16_t)(pclk1 / (2 *I2C_InitStruct->I2C_ClockSpeed << 1) );
			 tempreg |= result;
			 I2Cx->CCR = tempreg;		//Adds the tempreg value to CCR bits
			 
			 /*			Configure Rise time configuration (I2C_TRISE)			*/
			 I2Cx->TRISE = freqrange + 1;
		 }
		 else
		 {
			 //Fast Mode Not Supported Yet
		 }
		 
		 /*				I2C_CR1 Configuration				*/
		 tempreg = I2C1->CR1;										//Get I2C CR1 Value.
		 tempreg |= (uint16_t)(I2C_InitStruct->I2C_Ack_Control | I2C_InitStruct->General_Call_Address_Detection | I2C_InitStruct->I2C_Mode | I2C_InitStruct->StretchMode);
		 I2Cx->CR1 |= tempreg;									//Adds value to CR1
		 
		 /*			I2Cx OAR1 & OAR2 Configuration			*/
		 tempreg = 0;
		 if (I2C_InitStruct->I2C_Slave_Address.Enable_Dual_ADD == 1)
		 {
			 tempreg = I2C_OAR2_ENDUAL;
			 tempreg |= I2C_InitStruct->I2C_Slave_Address.Secondary_slave_address << I2C_OAR2_ADD2_Pos ;
			 I2Cx->OAR2 = tempreg;
		 }
		 
		 
		 tempreg = 0 ;
		 tempreg |= I2C_InitStruct->I2C_Slave_Address.Primary_slave_address << 1 ;
		 tempreg |= I2C_InitStruct->I2C_Slave_Address.I2C_Addressing_Slave_mode ;
		 I2Cx->OAR1 = tempreg;

	 }
	 else
	 {
		 //SMBus Not supported
	 }
	 
	 /*			Interrupt mode: Slave Mode				*/
	 //Checks callback pointer if not set to NULL
	 if (I2C_InitStruct->P_Slave_Event_CallBack != NULL)
	 {
		 //Enable IRQ
		 I2Cx->CR2 |= ( I2C_CR2_ITERREN );
		 I2Cx->CR2 |= ( I2C_CR2_ITEVTEN );
		 I2Cx->CR2 |= ( I2C_CR2_ITBUFEN );
		 if (I2Cx == I2C1)
		 {
			 NVIC_IRQ31_I2C1_EV_Enable ;
			 NVIC_IRQ32_I2C1_ER_Enable ;
		 }
		 else if ( I2Cx == I2C2 )
		 {
			 NVIC_IRQ33_I2C2_EV_Enable ;
			 NVIC_IRQ34_I2C2_ER_Enable ;
		 }
		 I2Cx->SR1 = 0;
		 I2Cx->SR2 = 0;
	 }
	 
	 /*			Enable the selected I2C Peripheral		*/
	 I2Cx->CR1 |= I2C_CR1_PE ;
 }
 
 
 
 
 /**================================================================
  * @Fn							-MCAL_I2C_DeInit
  * @brief 					- De-initializes the selected I2C Register
  * @param [in] 			-I2Cx : where x can be 1 or 2 according to the desired I2C register
  * @retval 					-None
  */
 
 void MCAL_I2C_DeInit(I2C_Typedef* I2Cx)
 {
	 if (I2Cx == I2C1 )
	 {
		 NVIC_IRQ31_I2C1_EV_Disable ;
		 NVIC_IRQ32_I2C1_ER_Disable ;
		 RCC_I2C1_CLK_Reset();
	 }
	 else if ( I2Cx == I2C2 )
	 {
		 NVIC_IRQ33_I2C2_EV_Disable ;
		 NVIC_IRQ34_I2C2_ER_Disable ;
		 RCC_I2C2_CLK_Reset();
	 }
 }
 
 
 
 
 /**================================================================
  * @Fn							-MCAL_I2C_GPIO_Set_Pins
  * @brief 					-Sets the corresponding pins for the given I2C register according to the recommended specs
  * @param [in] 			-I2Cx : where x can be 1 or 2 according to the desired I2C register
  * @retval 					-None
  */
 
 void MCAL_I2C_GPIO_Set_Pins (I2C_Typedef *I2Cx)
 {
	 GPIO_PinConfig_t PinCfg;
	 if ( I2Cx == I2C1 )
	 {
		 //PB6 : I2C1_SCL
		 //PB7 : I2C2_SDA
		 PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
	   PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		 PinCfg.GPIO_PinNumber = GPIO_PIN_6;
		 MCAL_GPIO_Init(GPIOB, &PinCfg);
		 
		 PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
	   PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		 PinCfg.GPIO_PinNumber = GPIO_PIN_7;
		 MCAL_GPIO_Init(GPIOB, &PinCfg);
	 }
	 else if ( I2Cx == I2C2 )
	 {
		 //PB10 : I2C2_SCL
		 //PB11 : I2C2_SDA
		 PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
	   PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		 PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		 MCAL_GPIO_Init(GPIOB, &PinCfg);
		 
		 PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
	   PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		 PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		 MCAL_GPIO_Init(GPIOB, &PinCfg);
	 }
	 
 }
 
 /**================================================================
  * @Fn								-MCAL_I2C_Master_TX
  * @brief 						-Transmit function for the I2C Master Device
  * @param [in] 			-I2Cx 	 : Where x indicates the desired I2C Register (I2C1/I2C2)
  * @param [in] 			-devAddr : Indicates the address required to transmit data
  * @param [in] 			-dataOut : Specifies the data which needs to be transmitted
  * @param [in] 			-dataLen : Specifies the data length
  * @param [in] 			-Stop 	 : Stop condition type
  * @param [in] 			-start 	 : Start Condition Type
  * @retval 					-None
  */
 
 void MCAL_I2C_Master_TX (I2C_Typedef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start start)
 {
	 // 1. Set the START bit in the I2C_CR1 register to generate a start condition.
 }

 
 
 
 
 
 /**================================================================
  * @Fn								-MCAL_I2C_Master_RX
  * @brief 						-Receive function for the I2C Master Device
  * @param [in] 			-I2Cx 	 : Where x indicates the desired I2C Register (I2C1/I2C2)
  * @param [in] 			-devAddr : Indicates the address required to transmit data
  * @param [in] 			-dataOut : Specifies the data which needs to be transmitted
  * @param [in] 			-dataLen : Specifies the data length
  * @param [in] 			-Stop 	 : Stop condition type
  * @param [in] 			-start 	 : Start Condition Type
  * @retval 					-None
  */
 
 void MCAL_I2C_Master_RX (I2C_Typedef *I2Cx, uint16_t devAddr, uint8_t *dataOut, uint32_t dataLen, Stop_Condition Stop, Repeated_Start start)
 {
 }

 
 
 
 
 /**================================================================
  * @Fn							-I2C_GenerateStart
  * @brief 					-Generates start
  * @param [in] 			-I2Cx 		: Where x indicates the desired I2C Register (I2C1/I2C2)
  * @param [in] 			-NewState : NewState Condition
  * @param [in] 			-start 		: Start Condition
  * @retval 					-None
  */
 
 void I2C_GenerateStart(I2C_Typedef* I2Cx, FunctionalState NewState, Repeated_Start start)
 {
	 //Check if start is repeated start or regular
	 if ( start != repeated_start )
	 {
		 //Check if BUS is idle
		 while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));  // Stopped at 4:20:00
	 }
 }
 
 
 
 
 /**================================================================
  * @Fn								-I2C_GetFlagStatus
  * @brief 						-Checks whether the flag status has been set or not
  * @param [in] 			-I2Cx 		: Where x indicates the desired I2C Register (I2C1/I2C2)
  * @param [in] 			-flag 		: The Flag that needs checking
  * @retval 					-None
  */
 
  FlagStatus I2C_GetFlagStatus(I2C_Typedef *I2Cx, Status flag)
 {
	 volatile uint32_t dummyRead ;
	 FlagStatus bitstatus = RESET;
	 switch (flag)
	 {
		 case I2C_FLAG_BUSY:
		 {
			 if ( (I2Cx->SR2) & (I2C_SR2_BUSY) )
				 bitstatus = SET;
			 else
				 bitstatus = RESET;
		 }
	 }
 }

