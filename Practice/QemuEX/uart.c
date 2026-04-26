/*
Eng.Mahmoud Elyamani
24-3-2026       11:28AM
*/
#include "uart.h"
#define UART0DR  *((volatile unsigned int* const)((unsigned int *)0x101f1000))
void UART_SEND_STRING(unsigned char *P_tx_string)
{
    while(*P_tx_string != '\0')
    {
        UART0DR = (unsigned int)(*P_tx_string);
        P_tx_string++;
    }
}