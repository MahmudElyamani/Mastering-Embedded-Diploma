#ifndef MYATMEGA32_H_
#define MYATMEGA32_H_

/*  address size is 1 byte = 8 bits */
typedef volatile unsigned char vuint8_t;    

//DDRX sets the port to either input or output
//PORTX sets the port to either output high or output low
//PINX reads the value on port x
/* For more explanation check page 50 of the TRM */

/*      Port A      */
#define DDRA    *(vuint8_t*)0x3A
#define PORTA   *(vuint8_t*)0x3B
#define PINA    *(vuint8_t*)0x39

/*      Port B      */
#define DDRB    *(vuint8_t*)0x37
#define PORTB   *(vuint8_t*)0x38
#define PINB    *(vuint8_t*)0x36

/*      Port C      */
#define DDRC    *(vuint8_t*)0x34
#define PORTC   *(vuint8_t*)0x35
#define PINC    *(vuint8_t*)0x33

/*      Port D      */
#define DDRD    *(vuint8_t*)0x31
#define PORTD   *(vuint8_t*)0x32
#define PIND    *(vuint8_t*)0x30

#define setBit(reg,bit)     (reg |= (1<<bit))
#define clearBit(reg,bit)   (reg &= ~(1<<bit))
#define toggleBit(reg,bit)  (reg ^= (1<<bit))
#define readBit(reg,bit)    (reg & (1<<bit))

#define setPort(reg)         (reg |= 0xFF)
#define clearPort(reg)       (reg &= 0x00)
#define togglePort(reg)      (reg ^= 0xFF)
#define readPort(reg)        (reg & 0xFF)

void gpioInit(void)
{
    DDRA  |= (0<<0);
}

#endif