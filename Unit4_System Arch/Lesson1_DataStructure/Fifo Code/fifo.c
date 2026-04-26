//--- ✄ --------- 2026.04.09 14:29 -------------------
//Created by Eng. Mahmoud Elyamani

#include "fifo.h"

/*       FIFO_init        */
FIFO_Buf_Status FIFO_init (FIFO_Buf_t* fifo, element_type *buf, uint32_t length)
{
    if (buf == NULL)
    return FIFO_null;

    fifo->base = buf;
    fifo->head = buf;
    fifo->tail = buf;
    fifo->length = length;
    fifo->count = 0;

    return FIFO_no_error;
}

/*       FIFO_enqueue        */
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item)
{
    //checks if all these parameter are present or not
    if (!fifo->base || !fifo->head || !fifo->tail)
    return FIFO_null;

    if(FIFO_IS_FULL(fifo) == FIFO_full)
    return FIFO_full;

    *(fifo->head) = item;
    fifo->count++;

    /* we can't simply increase fifo->head because we want a circular buffer, so we want
    to make sure that it points to the first element of the array once it reaches the end.*/

    //checks if the head adress has reached the maximum point
    if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
    fifo->head = fifo->base;
    else
    fifo->head++;

    return FIFO_no_error;
}

/*      FIFO_dequeue     */
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type *item)
{
    //checks if all these parameter are present or not
    if (!fifo->base || !fifo->head || !fifo->tail)
    return FIFO_null;

    //checks if fifo is empty or not
    if (fifo->count == 0)
    return FIFO_empty;

    //Returns the last element of he FIFO back to the user and empties it 
    *item = *(fifo->tail);
    fifo->count--;

    //checks if the tail adress has reached the minimum point
    if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
    fifo->tail = fifo->base;
    else
    fifo->tail++;

    return FIFO_no_error;
}

/*      FIFO_IS_FULL        */
FIFO_Buf_Status FIFO_IS_FULL (FIFO_Buf_t* fifo)
{
    //checks if all these parameter are present or not
    if (!fifo->base || !fifo->head || !fifo->tail)
    return FIFO_null;

    //checks if the current count exceeds the length 
    if(fifo->count == fifo->length)
    return FIFO_full;

    return FIFO_no_error;
}

/*      FIFO_print      */
void FIFO_print (FIFO_Buf_t* fifo)
{
    //we don't want to manipulate data so we will create a temp variable to copy the data to itself
    element_type *temp;
    unsigned int i;

    //checks if fifo is empty, if not it prints the value stored in tail.
    if (fifo->count == 0)
    printf("Fifo is empty\n");
    else
    {
        temp = fifo->tail;
        printf("\n ============fifo_print=============\n");
        for (i=0; i<fifo->count; i++)
        {
            printf("\t %X \n",*temp);
            temp++;
        }
        printf("============Printing Done==============\n");
    }
}