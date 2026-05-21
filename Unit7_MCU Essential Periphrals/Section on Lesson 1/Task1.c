//--- ✄ --------- 2026.05.21 09:37 -------------------
//Author: Eng. Mahmood El Yamani
//Task1: connect 8 LEDs on port A and have them turn on sequentially and turn off in reverse order.

#define __AVR_ATmega32__
#include "MyAtmega32.h"
#include "util\delay.h"
#define F_CPU 8000000UL


int main()
{
    setPort(DDRA);
    char i;
    while (1)
    {
      for(i=0; i<8; i++)
      {
        setBit(PORTA,i);
        _delay_ms(100);
      }

      _delay_ms(500);

      for(; i>=0; i--)
      {
        clearBit(PORTA,i);
        _delay_ms(100);
      }
    }

    return 0;
}