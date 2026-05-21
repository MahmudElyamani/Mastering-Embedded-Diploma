//--- ✄ --------- 2026.05.21 09:37 -------------------
//Author: Eng. Mahmood El Yamani
//Task1: connect 8 LEDs on port A and have them turn on sequentially and turn off in reverse order.

#define __AVR_ATmega32__
#include "MyAtmega32.h"
#include "util\delay.h"
#define F_CPU 8000000UL

unsigned char SegmentNumber[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

#define enableRight()  clearBit(PORTB,0)
#define enableLeft()  clearBit(PORTB,1)

#define disableRight() setBit(PORTB,0)
#define disableLeft() setBit(PORTB,1)

void showNum(int num, int pos)
{
  switch(pos)
  {
    case 0:
    disableLeft();
    enableRight();
    PORTA = SegmentNumber[num];
    break;
    case 1:
    disableRight();
    enableLeft();
    PORTA = SegmentNumber[num];
    break;
  }
}


int main()
{
  char i,j;
  setPort(DDRA);
  setBit(DDRB,0);
  setBit(DDRB,1);
  PORTA = SegmentNumber[0];   /*  set both displays numbers to 0 */
  while(1)
  {
    for (j=0; j<10; j++)
    {
        for (i=0; i<10; i++)
        {
          for (int period = 0; period <150; period++)
          {
            showNum(i,0);
            _delay_ms(1);
            showNum(j,1);
            _delay_ms(1);
          }
        }
    }
  }
  return 0;
}