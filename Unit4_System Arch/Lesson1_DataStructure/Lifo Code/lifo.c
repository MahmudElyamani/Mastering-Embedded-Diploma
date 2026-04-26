//--- ✄ --------- 2026.04.08 15:29 -------------------
//Created by Eng. Mahmoud Elyamani

#include "lifo.h"
LIFO_Status LIFO_ADD_ITEM (LIFO_Buf_t* LIFO_buf, unsigned int item)
{
    //check if lifo is valid
    if(!LIFO_buf->base || !LIFO_buf->head)
    return LIFO_Null;

    //check if lifo is full?
    if (LIFO_buf->count >= LIFO_buf->length)
    return LIFO_full;

    //add value
    *(LIFO_buf->head) = item;
    LIFO_buf->head++;
    LIFO_buf->count++; 
    return LIFO_no_error;
}

LIFO_Status LIFO_GET_DATA (LIFO_Buf_t* LIFO_buf, unsigned int *item)
{
    //check if lifo is valid
    if(!LIFO_buf->base || !LIFO_buf->head)
    return LIFO_Null;

    //check if lifo is empty?
    if(LIFO_buf->count == 0)
    return LIFO_empty;

    //Go back one step then return the value at that location.
    LIFO_buf->head--;
    *item = *(LIFO_buf->head);
    LIFO_buf->count--;

    return LIFO_no_error;

}


//Init or initializing is supposed to point at the base and make it equivalent to the adress of buf[0]
LIFO_Status LIFO_INIT (LIFO_Buf_t* LIFO_buf, unsigned int *buf, unsigned int length)
{
    if(buf == NULL)
    return LIFO_Null;

    LIFO_buf->base = buf;
    LIFO_buf->head = buf;
    LIFO_buf->length = length;
    LIFO_buf->count = 0;
    return LIFO_no_error;
}
