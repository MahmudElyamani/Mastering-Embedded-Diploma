/**================================================================
 * @file           :MY_STM32_GPIO.h
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 11th, 2026
 * @brief          :GPIO Library header file which contains all supported APIs user is allowed to use.
 *
 *=================================================================*/
 #ifndef MY_STM32_GPIO_H_
 #define MY_STM32_GPIO_H_
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //Includes:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 #include <stdlib.h>
 #include <stdint.h>
 #include "stm32f103c8.h"
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //Config Register:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 typedef struct
 {
	 uint16_t		PinNumber;		//Specifies the pin number to be configured
									//Can be chosen based on @ref GPIO_Pins
	 
	 uint8_t		Mode;	  		//Specifies the GPIO Input or output mode
									//Can be chosen based on @ref GPIO_MODES
	 
	 uint8_t		OutputSpeed;	//Specifies the output speed in case of output mode
									//Can be chosen based on @ref GPIO_Output_Speed
 }GPIO_Config_t;
 
 
 //@ref GPIO_Pins
 typedef enum
 {
	 PIN_0,
	 PIN_1,
	 PIN_2,
	 PIN_3,
	 PIN_4,
	 PIN_5,
	 PIN_6,
	 PIN_7,
	 PIN_8,
	 PIN_9,
	 PIN_10,
	 PIN_11,
	 PIN_12,
	 PIN_13,
	 PIN_14,
	 PIN_15,
	 PIN_ALL = 0xFFFF
 }GPIO_Pins_t;
 
 //@ref GPIO_MODES
 enum
 {
	Analog,
	Input_floating,
	Input_pull_up_down
 }GPIO_INPUT_MODES;
  enum
 {
	Output_push_pull,
	Output_open_drain,
	Alternate_function_push_pull,
	Alternate_function_open_drain
 }GPIO_OUTPUT_MODES;
 
 //@ref GPIO_Output_Speed
 enum
 {
	 Input,
	 Speed_10MHZ,
	 Speed_2MHZ,
	 Speed_50MHZ
 }GPIO_Output_Speed;
 
 
 enum
 {
	 LOW,
	 HIGH
 }State;
 
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //			APIs Supported by MY_STM32_GPIO.h:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 void GPIO_Setup(GPIO_t *GPIOx, GPIO_Config_t *config_register);
 void GPIO_DeSetup(GPIO_t *GPIOx);
 void GPIO_Set(GPIO_t *GPIOx, GPIO_Pins_t *PinNumber, uint8_t Value);
 void GPIO_Toggle(GPIO_t *GPIOx, GPIO_Pins_t *PinNumber);
 uint8_t GPIO_Read(GPIO_t *GPIOx, GPIO_Pins_t *PinNumber);
 void GPIO_Lock(GPIO_t *GPIOx, GPIO_Pins_t *PinNumber);
 
 
 #endif
 