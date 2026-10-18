/**================================================================
 * @file           :MY_STM32_GPIO.c
 * @author         :Mahmoud Elyamani
 * @Date		   :Oct 11th, 2026
 * @brief          :GPIO Library source code which contains definition for all supported APIs in header file
 *
 *=================================================================*/
#include "MY_STM32_GPIO.h"
#include "MY_STM32_RCC.h"

/**================================================================
 * @Fn				-GPIO_Setup
 * @brief 			-Sets up given GPIO port according to values set in given config_register
 * @param [in] 		-GPIOx : where x can be A,B,C,D,E depending on the desired port
 * @param [in] 		-config_register : The user sets up its parameters individually based on what's needed
 * @retval 			-None
 */

void GPIO_Init(GPIO_t *GPIOx, GPIO_Config_t *config_register)
{
	//Enables the corresponding GPIO clock
	if (GPIOx == GPIOA)
		RCC_CLK_SET(RCC_GPIOA, HIGH);
	else if (GPIOx == GPIOB)
		RCC_CLK_SET(RCC_GPIOB, HIGH);
	else if (GPIOx == GPIOC)
		RCC_CLK_SET(RCC_GPIOC, HIGH);
	else if (GPIOx == GPIOD)
		RCC_CLK_SET(RCC_GPIOD, HIGH);
	else if (GPIOx == GPIOE)
		RCC_CLK_SET(RCC_GPIOE, HIGH);
	
	//First 4 bits which control one pin
	volatile uint8_t PinSettings = 0U;
	
	//Pin Number Value saved
	volatile uint8_t PinNumber = config_register->PinNumber;
	
	//First 2 Bits [MODE] 
	PinSettings |= config_register->OutputSpeed;
	
	//Second 2 Bits [CNF] shifted by 2 for correct spot
	PinSettings |= ( config_register->Mode << 2 );
	
	//checking which register to use CRL or CRH
	if ( PinNumber < PIN_8 )
	{
		GPIOx->CRL &= ~(0xF << ((PinNumber)*4));	//Clearing the bits before setting.
		GPIOx->CRL |= ( PinSettings << ((PinNumber)*4) );	//Multiplying by 4 to step by 4 bits
	}
	else
	{
		GPIOx->CRH &= ~(0xF << (((PinNumber) - 8)*4) );	//Clearing the bits before setting.
		GPIOx->CRH |= ( PinSettings << (((PinNumber) - 8)*4) );  //Subtracting by 8 to get to CRH start
	}
		
}







/**================================================================
 * @Fn				-GPIO_DeSetup
 * @brief 			-Resets the GPIO port to its initial values, and disabling its clock
 * @param [in] 		-GPIOx : where x can be A,B,C,D,E depending on the desired port
 * @retval 			-None
 */

void GPIO_DeSetup(GPIO_t *GPIOx)
{
	//Disables the corresponding GPIO clock
	if (GPIOx == GPIOA)
		RCC_CLK_SET(RCC_GPIOA, LOW);
	else if (GPIOx == GPIOB)
		RCC_CLK_SET(RCC_GPIOB, LOW);
	else if (GPIOx == GPIOC)
		RCC_CLK_SET(RCC_GPIOC, LOW);
	else if (GPIOx == GPIOD)
		RCC_CLK_SET(RCC_GPIOD, LOW);
	else if (GPIOx == GPIOE)
		RCC_CLK_SET(RCC_GPIOE, LOW);
	GPIOx->CRL &= 0;
	GPIOx->CRL |= 0x44444444;
	GPIOx->CRH &= 0;
	GPIOx->CRH |= 0x44444444;
}







/**================================================================
 * @Fn				-GPIO_Set
 * @brief 			-Sets a given pin (PinNumber) in a given GPIO port (GPIOx) to a value high or low (Value)
 * @param [in] 		-GPIOx : where x can be A,B,C,D,E depending on the desired port
 * @param [in] 		-PinNumber : Can be selected based on @ref GPIO_Pins
 * @param [in] 		-Value : can be either HIGH or LOW
 * @retval 			-None
 */

void GPIO_Set(GPIO_t *GPIOx, GPIO_Pins_t PinNumber, uint8_t Value)
{
	if (Value == HIGH)
		GPIOx->BSRR = (1<<PinNumber);
	else
		GPIOx->BRR = (1<<PinNumber);
}







/**================================================================
 * @Fn				-GPIO_Toggle
 * @brief 			-Toggles a given GPIO pin (PinNumber) in a given GPIO Port (GPIOx) between HIGH or LOW states
 * @param [in] 		-GPIOx : where x can be A,B,C,D,E depending on the desired port
 * @param [in] 		-PinNumber : Can be selected based on @ref GPIO_Pins
 * @retval 			-None
 */

void GPIO_Toggle(GPIO_t *GPIOx, GPIO_Pins_t PinNumber)
{
	uint8_t state = GPIO_Read(GPIOx, PinNumber);
	if (state == 1)
		GPIOx->BRR  = (1<<PinNumber);
	else
		GPIOx->BSRR = (1<<PinNumber);

}







/**================================================================
 * @Fn				-GPIO_Read
 * @brief 			-Reads the value of a given pin (PinNumber) on a given port (GPIOx)
 * @param [in] 		-GPIOx : where x can be A,B,C,D,E depending on the desired port
 * @param [in] 		-PinNumber : Can be selected based on @ref GPIO_Pins
 * @retval 			-Value of the selected pin, can be HIGH or LOW.
 */

uint8_t GPIO_Read(GPIO_t *GPIOx, GPIO_Pins_t PinNumber)
{
	return ( (GPIOx->IDR & (1<<PinNumber)) >> PinNumber );
}





/**================================================================
 * @Fn				-GPIO_Lock
 * @brief 			-Locks the settings of a selected pin after configuring to avoid issues
 * @param [in] 		-GPIOx : where x can be A,B,C,D,E depending on the desired port
 * @param [in] 		-PinNumber : Can be selected based on @ref GPIO_Pins
 * @retval 			-None
 */

void GPIO_Lock(GPIO_t *GPIOx, GPIO_Pins_t PinNumber)
{
	//To be implemented.
}




