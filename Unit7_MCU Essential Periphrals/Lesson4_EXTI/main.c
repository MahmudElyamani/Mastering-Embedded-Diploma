#include "Inc\Stm32F103x6.h"
#include "Inc\Stm32_F103C6_gpio_driver.h"

void Delayms(unsigned int time)
{
    time = time*1000;
    for (unsigned int i = time; i>0; i--);
}
void GPIO_init()
{
    GPIO_PinConfig_t PinCfg;

    //PA1 input HighZ floating input
    PinCfg.GPIO_PinNumber = GPIO_PIN_1;
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(GPIOA, &PinCfg);

    //PB1 output push-pull mode
    PinCfg.GPIO_PinNumber = GPIO_PIN_1;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(GPIOB, &PinCfg);

    //PA13 Input highZ floating input
    PinCfg.GPIO_PinNumber = GPIO_PIN_13;
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    MCAL_GPIO_Init(GPIOA, &PinCfg);

    //PB13 output push-pull mode
    PinCfg.GPIO_PinNumber = GPIO_PIN_13;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(GPIOB, &PinCfg);
}

int main(void)
{
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
	GPIO_init();

	while(1)
	{
		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 ) //single press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);		//Toggling LED B1
			while ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0 );
		}

		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1 ) //multi press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);		//Toggling LED B13
			Delayms(1000);
		}
	}
    return 0;
}