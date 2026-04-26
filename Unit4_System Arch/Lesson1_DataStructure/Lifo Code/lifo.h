//--- ✄ --------- 2026.04.08 14:53 -------------------
//Created by Eng. Mahmoud Elyamani
#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

/* type definitions: */


//for ease of use we made the buffer a structure in case the user wants to use one for
//UART, I2C, CAN or any different communicaton protocol module.
typedef struct {
    unsigned int length;
    unsigned int count;
    unsigned int *base;
    unsigned int *head;
}LIFO_Buf_t;

//Defining different states of possible outcomes from LIFO using enum
typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_Null
}LIFO_Status;

//APIs
LIFO_Status LIFO_ADD_ITEM (LIFO_Buf_t* LIFO_buf, unsigned int item);

//API to accept items so we use a pointer next to item so that the value is modifyible.
LIFO_Status LIFO_GET_DATA (LIFO_Buf_t* LIFO_buf, unsigned int *item);

//Takes the Lifo you want to initialize and the array that it's going to use as a buffer.
LIFO_Status LIFO_INIT (LIFO_Buf_t* LIFO_buf, unsigned int *buf, unsigned int length);



#endif  /* LIFO_H_ */