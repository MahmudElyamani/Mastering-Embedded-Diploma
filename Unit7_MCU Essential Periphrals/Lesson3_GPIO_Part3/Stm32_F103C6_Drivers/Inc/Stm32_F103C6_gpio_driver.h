/*--- ✄ --------- 2026.06.06 09:17 -------------------
Author: Mahmood El Yamani
Unit7:Lesson3
Learn-in-depth Diploma
*/

#ifndef STM32_F103C6_GPIO_DRIVER_H_
#define STM32_F103C6_GPIO_DRIVER_H_
//--------------------------------------------------------
//Includes
//--------------------------------------------------------
#include "Stm32F103x6.h"


//--------------------------------------------------------
//User Type Definitions (structures)
//--------------------------------------------------------
typedef struct
{
    uint16_t GPIO_PinNumber;    //Specifies the GPIO pins to be configured, parameter @ref GPIO_PINS_Define
    uint8_t  GPIO_MODE;         //Specifies the operation mode for pins, @ref GPIO_MODE_Define 
    uint8_t  GPIO_Output_Speed; //Specifies the speed for the selected pins, @ref GPIO_SPEED_Define
}GPIO_PinConfig_t;

//--------------------------------------------------------
//Macros Configuration References
//--------------------------------------------------------

//@ref GPIO_PINS_Define
#define GPIO_PIN_0          ((uint16_t)0x0001)  /* PIN 0 Selected */
#define GPIO_PIN_1          ((uint16_t)0x0002)  /* PIN 1 Selected */
#define GPIO_PIN_2          ((uint16_t)0x0004)  /* PIN 2 Selected */
#define GPIO_PIN_3          ((uint16_t)0x0008)  /* PIN 3 Selected */
#define GPIO_PIN_4          ((uint16_t)0x0010)  /* PIN 4 Selected */
#define GPIO_PIN_5          ((uint16_t)0x0020)  /* PIN 5 Selected */
#define GPIO_PIN_6          ((uint16_t)0x0040)  /* PIN 6 Selected */
#define GPIO_PIN_7          ((uint16_t)0x0080)  /* PIN 7 Selected */
#define GPIO_PIN_8          ((uint16_t)0x0100)  /* PIN 8 Selected */
#define GPIO_PIN_9          ((uint16_t)0x0200)  /* PIN 9 Selected */
#define GPIO_PIN_10         ((uint16_t)0x0400)  /* PIN 10 Selected */
#define GPIO_PIN_11         ((uint16_t)0x0800)  /* PIN 11 Selected */
#define GPIO_PIN_12         ((uint16_t)0x1000)  /* PIN 12 Selected */
#define GPIO_PIN_13         ((uint16_t)0x2000)  /* PIN 13 Selected */
#define GPIO_PIN_14         ((uint16_t)0x4000)  /* PIN 14 Selected */
#define GPIO_PIN_15         ((uint16_t)0x8000)  /* PIN 15 Selected */
#define GPIO_PIN_ALL        ((uint16_t)0xFFFF)  /* All pins selected */

//@ref GPIO_Mode_Define 
#define GPIO_MODE_Analog               0x00     /* Analog Mode */
#define GPIO_MODE_INPUT_FLO            0x01     /* Input Floating Mode */
#define GPIO_MODE_INPUT_PU             0x02     /* Input Pull-Up */
#define GPIO_MODE_INPUT_PD             0x03     /* Input Pull-Down*/
#define GPIO_MODE_OUTPUT_PP            0x04     /* Output Push-Pull*/
#define GPIO_MODE_OUTPUT_OD            0x05     /* Output Open-Drain*/
#define GPIO_MODE_OUTPUT_AF_PP         0x06     /* Output Alternate Function Push-Pull */
#define GPIO_MODE_OUTPUT_AF_OD         0x07     /* Output Alternate Function Open-Drain */
#define GPIO_MODE_AF_INPUT             0x08     /* Alternate Function Input mode  */

//@ref GPIO_SPEED_Define
#define GPIO_SPEED_10M                 0x01     /*  Output mode, Max 10Mhz speed */
#define GPIO_SPEED_2M                  0x02     /*  Output mode, Max 2Mhz speed  */
#define GPIO_SPEED_50M                 0x03     /*  Output mode, Max 50Mhz speed */

//@ref GPIO_PIN_state
#define GPIO_PIN_SET                    1
#define GPIO_PIN_RESET                  0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enable         1
#define GPIO_RETURN_LOCK_ERROR          0

/*
 * ===================================================
 * APIs Supported by "MCAL $(PeripheralName) DRIVER"
 * ===================================================
 */

void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint8_t Value);
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t PinNumber);
void MCAL_GPIO_TogglePort(GPIO_TypeDef *GPIOx); 
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint8_t PinNumber);

#endif
