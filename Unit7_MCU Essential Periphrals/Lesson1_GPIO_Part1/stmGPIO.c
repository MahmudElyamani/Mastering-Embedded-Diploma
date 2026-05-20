#include "stlib.h"
#include <system_stm32f10x.h>
int main(void)
{
	clockinit();
	GPIO_init();

	while(1)
	{
		if ( ((GPIOA_IDR & (1<<1)) >> 1) == 0 ) //single press
		{
			GPIOB_ODR ^= (1<<1);		//Toggling LED B1
			while ( ((GPIOA_IDR & (1<<1)) >> 1) == 0 );
		}

		if ( ((GPIOA_IDR & (1<<13)) >> 13) == 1 ) //multi press
		{
			GPIOB_ODR ^= (1<<13);		//Toggling LED B1
			Delayms(1000);
		}
	}
}
