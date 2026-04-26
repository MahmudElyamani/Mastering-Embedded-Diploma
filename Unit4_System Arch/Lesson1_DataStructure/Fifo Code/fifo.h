//--- ✄ --------- 2026.04.09 14:29 -------------------
//Created by Eng. Mahmoud Elyamani

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"


/* USER CONFIGURATION */

//select element type
#define element_type uint8_t

//create buffer
#define width 5
element_type buff[width];


//FIFO data types
typedef struct{
    unsigned int length;
    unsigned int count;
    element_type *base;
    element_type *head;
    element_type *tail;
}FIFO_Buf_t;


//Status of FIFO:
typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_Buf_Status;


/* FIFO APIS */
//Explanations provided in Lifo.h for similar code.
FIFO_Buf_Status FIFO_init (FIFO_Buf_t* fifo, element_type *buf, uint32_t length);
FIFO_Buf_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type *item);

//In case we wanted to check the size at any time without having to rely on other variables.
FIFO_Buf_Status FIFO_IS_FULL (FIFO_Buf_t* fifo);

//Prints everything for a given fifo
void FIFO_print (FIFO_Buf_t* fifo);

#endif  /* FIFO_H_ */