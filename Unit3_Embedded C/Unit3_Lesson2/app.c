#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth: Mahmood";
unsigned char const string_buffer2[100] = "learn-in-depth: Mahmood";


void main(void)
{
    Uart_Send_String(string_buffer);
}