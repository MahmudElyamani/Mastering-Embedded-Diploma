#include "MyAtmega32.h"
#include "LCD.h"
#include "keypad.h"
#include <stdlib.h>

int main(void)
{
  LCD_INIT();
  myKeypadINIT();

  char c ;

  while(1)
  {
    c = myKeypadgetc();
    if (c) LCD_WRITE_CHAR(c);
  }
  return 0;
}