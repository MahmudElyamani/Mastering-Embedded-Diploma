#define F_CPU 16000000UL
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

ISR(INT0_vect)
{
   //To store ISR at address INT0
   PORTA |= (1<<0);
   _delay_ms(100);
   PORTA &= ~(1<<0);
   _delay_ms(100);
}

ISR(INT1_vect)
{
   //To store ISR at address INT0
   PORTA |= (1<<1);
   _delay_ms(100);
   PORTA &= ~(1<<1);
   _delay_ms(100);
}

ISR(INT2_vect)
{
   //To store ISR at address INT0
   PORTA |= (1<<2);
   _delay_ms(100);
   PORTA &= ~(1<<2);
   _delay_ms(100);
}

int main()
 { 
   /*	GPIO Pirephrals 	*/
   DDRA |= ((1<<0) | (1<<1) | (1<<2));
   
   /*	Interrupt Pirephrals	*/
   MCUCR |= (1<<0);			//Any logic change on INT0 generates an interrupt request   
   MCUCR |= ((1<<2) | (1<<3));		//The rising edge on INT1 generates an interrupt request  
   MCUCSR |= (0<<0);			//The falling edge on INT2 generates an interrupt request
   GICR |= ((1<<5) | (1<<6) | (1<<7));	//Enabling all interrupts
   SREG |= (1<<7);			//enabling interrupt requests

   while (1)
      ;
   return 0;
 }