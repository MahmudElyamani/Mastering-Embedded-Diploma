//--- ✄ --------- 2026.04.26 11:59 -------------------
//Made by Eng. Mahmood Elyamani

#include "queue.h"
#include <stdio.h>

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




/*      Option(1): Adds student via a seperate file     */
void fileAddStudent(FIFO_Buf_t *FIFO)
{
    if (!FIFO->base || !FIFO->tail || FIFO->head)
    printf("Error! data does not exist here yet");
    else if (FIFO_IS_FULL(FIFO) == FIFO_full)
    printf("Error! data base is full");
}



/*      Option(2): Adds student manually via user input     */
void ManualAddStudent(FIFO_Buf_t *FIFO)
{

}



/*      Option(3): Finds student details by role number     */
void findDR(FIFO_Buf_t *FIFO)
{

}



/*      Option(4): Finds student details by name        */
void findDN(FIFO_Buf_t *FIFO)
{

}



/*      Option(5): Finds student details by course ID       */
void findDC(FIFO_Buf_t *FIFO)
{

}



/*      Option(6): Finds the total number of students       */
void findTOT(FIFO_Buf_t *FIFO)
{

}



/*      Option(7): Deletes student details by role number       */
void RDelete(FIFO_Buf_t *FIFO)
{

}



/*      Option(8): Updates student details by role number       */
void RUpdate(FIFO_Buf_t *FIFO)
{

}



/*      Option(9): Shows information for all students in the list       */
void SShow(FIFO_Buf_t *FIFO)
{

}