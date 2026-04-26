/*
Eng.Mahmoud Elyamani
24-3-2026       8:34AM
*/
#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:<Mahmut>";
unsigned char const string_buffer_2 [20] = "RoDATA Finally";
void main(void)
{
    UART_SEND_STRING(string_buffer);
}