#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "MyAtmega32.h"
#include <util\delay.h>

#define KEYPAD_PORT PORTD
#define DATADIR_KEYPAD_PORT DDRD
#define KEYPAD_PIN PIND


#define R0 0
#define R1 1
#define R2 2
#define R3 3

#define C0 4
#define C1 5
#define C2 6
#define C3 7

void KEYPAD_INIT(void);
char KEYPAD_GETCHAR(void);

void myKeypadINIT(void);
char myKeypadgetc(void);

#endif