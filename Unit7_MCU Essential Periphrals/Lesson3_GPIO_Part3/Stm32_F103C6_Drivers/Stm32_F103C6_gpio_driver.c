//--- ✄ --------- 2026.06.06 13:17 -------------------
//Author: Mahmood El Yamani

#include "Inc\Stm32_F103C6_gpio_driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
    switch (PinNumber)
    {
        case GPIO_PIN_0:
        return 0;
        break;
        case GPIO_PIN_1:
        return 4;
        break;
        case GPIO_PIN_2:
        return 8;
        break;
        case GPIO_PIN_3:
        return 12;
        break;
        case GPIO_PIN_4:
        return 16;
        break;
        case GPIO_PIN_5:
        return 20;
        break;
        case GPIO_PIN_6:
        return 24;
        break;
        case GPIO_PIN_7:
        return 28;
        break;
        case GPIO_PIN_8:
        return 0;
        break;
        case GPIO_PIN_9:
        return 4;
        break;
        case GPIO_PIN_10:
        return 8;
        break;
        case GPIO_PIN_11:
        return 12;
        break;
        case GPIO_PIN_12:
        return 16;
        break;
        case GPIO_PIN_13:
        return 20;
        break;
        case GPIO_PIN_14:
        return 24;
        break;
        case GPIO_PIN_15:
        return 28;
        break;   
    }
    return 0;
}

/**============================================================================================
 * @fn                  -MCAL_GPIO_Init
 * @brief               -Initializes the GPIOx Pin y according to the specified parameters in the PinConfig
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @parm [out]          -PinConfig pointer to a GPIO_PinConfig_t structure that contains the configuration information 
 * @retval
 * Note
 */ 
void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
    //Port configuration register low (GPIOx_CRL) configures pins from 0>>7
    //Port configuration register High (GPIOx_CRH) configures pins from 8>>15
    volatile uint32_t* configregister = NULL;
    uint8_t PIN_Config = 0;
    configregister = (PinConfig->GPIO_PinNumber<GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH;

    //clear CNF[1:0] and MODE[1:0]
    (*configregister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

    //if pin is output
    if ( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
    {
        PIN_Config = ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0f );
    }
    //if pin is input
    else    //Mode by default is 00
    {
            if ( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog) )
            {
                PIN_Config = ((((PinConfig->GPIO_MODE) << 2) | 0x0) & 0x0f );
            }
            else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)    //Consider it as input floating
            {
                PIN_Config = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0) & 0x0f );
            }
            else
            {
                PIN_Config = ( (((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0f);
                if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
                {
                    //Table 20 Port bit config PxODR register set to 1
                    GPIOx->ODR |= PinConfig->GPIO_PinNumber;
                }
                else
                {
                    GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
                }
            }
    }
    (*configregister) |= ( (PIN_Config)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));

}

/**============================================================================================
 * @fn                  -MCAL_GPIO_DeInit
 * @brief               -De-initializes the GPIOx Registers
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @parm [out]          -none 
 * @retval              -none
 * Note                 -none
 */ 
 void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
 {
    if (GPIOx == GPIOA)
    {
        RCC->APB2RSTR |=  (1u<<2);
        RCC->APB2RSTR &= ~(1u<<2);
    }
    if (GPIOx == GPIOB)
    {
        RCC->APB2RSTR |=  (1u<<3);
        RCC->APB2RSTR &= ~(1u<<3);
    }
    if (GPIOx == GPIOC)
    {
        RCC->APB2RSTR |=  (1u<<4);
        RCC->APB2RSTR &= ~(1u<<4);
    }
    if (GPIOx == GPIOD)
    {
        RCC->APB2RSTR |=  (1u<<5);
        RCC->APB2RSTR &= ~(1u<<5);
    }
 }

/**============================================================================================
 * @fn                  -MCAL_GPIO_ReadPin
 * @brief               -Read specific pin based on the given port name and pin number
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @parm [in]           -PinNumber: Sets pin number according to @ref GPIO_PINS_Define
 * @retval              -The input pin value, can be either 1 or 0 based on @ref GPIO_PIN_state
 * Note                 -none
 */ 
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
    uint8_t bitstatus;
    if (((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
    bitstatus = GPIO_PIN_SET;
    else
    bitstatus = GPIO_PIN_RESET;
    return bitstatus;
}

/**============================================================================================
 * @fn                  -MCAL_GPIO_ReadPort
 * @brief               -Read specific port based on the given port
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @retval              -The input port value
 * Note                 -none
 */ 
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
    uint16_t port_value;
    port_value = (uint16_t)(GPIOx->IDR);
    return port_value;
}

/**============================================================================================
 * @fn                  -MCAL_GPIO_WritePin
 * @brief               -writes specific pin based on the given port name and pin number and value
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @parm [in]           -PinNumber: Specifies the port bit to read, set be @ref GPIO_PINS_Define
 * @parm [in]           -Value: Pin value, can either be 1 or 0 depending on @ref GPIO_PIN_state
 * Note                 -none
 */ 
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value)
{
    if (Value != GPIO_PIN_RESET)
    GPIOx->BSRR = (uint32_t)PinNumber;
    else
    GPIOx->BRR = (uint32_t)PinNumber;
}

/**============================================================================================
 * @fn                  -MCAL_GPIO_WritePort
 * @brief               -writes specific port based on the given port name and value
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @parm [in]           -Value: Pin value, can either be 1 or 0 depending on @ref GPIO_PIN_state
 * Note                 -none
 */ 
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint8_t Value)
{
    GPIOx->ODR = (uint32_t)Value;
}

/**============================================================================================
 * @fn                  -MCAL_GPIO_TogglePin
 * @brief               -Toggles a specific pin based on the given port name and pin number
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @parm [in]           -PinNumber: Specifies the port bit to read, set be @ref GPIO_PINS_Define
 * Note                 -none
 */ 
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t PinNumber)
{
    GPIOx->ODR ^= (PinNumber);
}

/**============================================================================================
 * @fn                  -MCAL_GPIO_TogglePort
 * @brief               -Toggles a specific port based on the given port name
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * Note                 -none
 */ 
void MCAL_GPIO_TogglePort(GPIO_TypeDef *GPIOx)
{
    GPIOx->ODR ^= GPIOx->ODR;
}

/**============================================================================================
 * @fn                  -MCAL_GPIO_LockPin
 * @brief               -The locking mechanism allows the IO configuration to be frozen
 * @parm [in]           -GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @parm [in]           -PinNumber: Specifies the port bit to read, set be @ref GPIO_PINS_Define
 * @retval              -Ok if locking operation completed, ERROR if not. defined at @ref GPIO_RETURN_LOCK
 * Note                 -none
 */ 
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint8_t PinNumber)
{
    //Sets LCK[16]
    volatile uint32_t temp = 1<<16;

    //Sets the LCKy
    temp |= PinNumber;

    //Locking sequence according to the TRM:
    GPIOx->LCKR = temp;
    GPIOx->LCKR = PinNumber;
    GPIOx->LCKR = temp;
    temp = GPIOx->LCKR;

    //Read 1 (This is optional but confirms lock is active)
    if ( (uint32_t) (GPIOx->LCKR & (1<<16)))
    return GPIO_RETURN_LOCK_Enable;
    else
    return GPIO_RETURN_LOCK_ERROR;
}
