//--- ✄ --------- 2026.04.09 14:29 -------------------
//Created by Eng. Mahmoud Elyamani

#include "fifo.h"
int main()
{
    element_type uart_buffer[5];
    element_type i, temp = 0;
    FIFO_Buf_t FIFO_UART;

    //Initialization check for FIFO:
    if (FIFO_init(&FIFO_UART ,uart_buffer,5) == FIFO_no_error)
    printf("Fifo init ---Done---\n");

    //Enqueue process and check for FIFO:
    for (i=0; i<7; i++)
    {
        printf("FIFO Enqueue (%x): \n",i);
        if (FIFO_enqueue(&FIFO_UART, i) == FIFO_no_error)
        printf("\t Fifo enqueue ---Done---\n");
        else
        printf("\t Fifo enqueue ---FAILED---\n");
    }

    //Printing the values inside the given FIFO:
    //We dequeued twice for some reason.. ask Keroles.          
    FIFO_print(&FIFO_UART);
    if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
    printf("Fifo dequeue (%x) ---Done---\n",temp);
    if (FIFO_dequeue(&FIFO_UART, &temp) == FIFO_no_error)
    printf("Fifo dequeue (%x) ---Done---\n",temp);
    FIFO_print(&FIFO_UART);

    return 0;
}

