//--- ✄ --------- 2026.04.08 14:54 -------------------
//Created by Eng. Mahmoud Elyamani

#include "lifo.h"


int main()
{
    unsigned int i, temp = 0;
    LIFO_Buf_t Uart_Lifo, I2C_Lifo;

    //static allocation: 
    unsigned int buffer1[5];
    LIFO_INIT(&Uart_Lifo, buffer1, 5);

    //dynamic allocation:
    unsigned int* buffer2 =(unsigned int*) malloc(5 * sizeof(unsigned int));
    LIFO_INIT(&I2C_Lifo, buffer2, 5);

    for (i=0 ; i<7 ; i++)
    {
        if(LIFO_ADD_ITEM(&Uart_Lifo, i) == LIFO_no_error)
            printf("UART_LIFO add: %d \n",i);
    }

    for (i=0 ; i<5 ; i++)
    {
        if(LIFO_GET_DATA(&Uart_Lifo, &temp) == LIFO_no_error)
            printf("UART_LIFO get: %d \n",temp);
    }
    return 0;
}