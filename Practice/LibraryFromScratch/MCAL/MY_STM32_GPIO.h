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
 
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 //Config Register:
 //-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 typedef struct
 {
	 uint16_t		PinNumber;//Specifies the pin number to be configured
							  //Can be a value between 0 and 15
	 
	 uint8_t		Mode;	  //Specifies the GPIO Input or output mode
							  //Can be chosen based on @ref GPIO_MODES
 }GPIO_Config_t;
 
 
 
 
 //@ref GPIO_MODES
 enum
 {
	Input_floating,
	Input_pull_up,
	Input_pull_down,
	Analog,
	Output_open_drain,
	Output_push_pull,
	Alternate_function_push_pull,
	Alternate_function_open_drain
 }GPIO_MODES;
 
 #endif
 