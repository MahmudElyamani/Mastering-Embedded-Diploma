/*
 * main.c
 *
 * Created: 10/29/2026 10:10:45 AM
 *  Author: mah.elyamany
 */ 

#define F_CPU 8000000UL
#include <xc.h>
#include <util/delay.h>
#include "Utils.h"
#include "avr/interrupt.h"	

typedef enum{NORMAL, CTC=0x08}TIMER0_MODE_t;
typedef enum{NO_CLK_PRESCALING, NO_PRESCALING, PRESCALING_CLK8, PRESCALING_CLK64, PRESCALING_CLK265,
			 PRESCALING_CLK1024, EXT_CLK_FALLING, EXT_CLK_RISING}OCMIE_t;
typedef enum{OCIE_DISABLE, OCIE_ENABLE=0x02}TOVFIE0_t;


#define LED_DDR			DDRC
#define LED_PORT		PORTC
#define LED_PIN			0

void WDT_OFF()
{
	WDTCR |= ( (1<< WDTOE) | (1<< WDE) );
	WDTCR = 0x00;
}

void WDT_ON()
{
	WDTCR |= ( (1<< WDP1) | (1<< WDE) | (1<< WDP2) );
	RESET_BIT(WDTCR, WDP0);
}

int main(void)
{
	SET_BIT(LED_DDR, 0);
    while(1)
    {
        //TODO:: Please write your application code 
		WDT_ON();
		TOGGLE_BIT(LED_PORT, LED_PIN);
		_delay_ms(900);
		WDT_OFF();
    }
}