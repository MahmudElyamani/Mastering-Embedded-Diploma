#define __AVR_ATmega32__
#include "ATmega32GPIO.h"
#define F_CPU 8000000UL
int main()
{
    gpioInit();
    
    while (1)
    {
      /*  Single press on PA0 toggles state on PB1 */
      if (PINA & (1<<0))
      {
        PORTB ^= (1<<1);
        while (PINA & (1<<0));
      }
      
      /*  Single press on PC2 toggles state on PD3 */
      if (PINC & (1<<2))
      {
        PORTD ^= (1<<3);
        while (PINC & (1<<2));
      }
    }

    return 0;
}