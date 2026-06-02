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
    char i = 0, cond;
    while (1)
    {
      if(i==0)
      cond = 1;
      if (readBit(PINC,1))
      {
        if ((i<8) && cond)
        {
          setBit(PORTA,i);
          i++;
        }
        else
        {
          cond = 0;
          --i;
          clearBit(PORTA,i);
        }
        while (readBit(PINC,1));
      }
      
    }

    return 0;
}