//--- ✄ --------- 2026.04.26 11:58 -------------------
//made by Eng. Mahmood Elyamani

#ifndef QUEUE_H_
#define QUEUE_H_



#include <stdint.h>




/*      User Definition        */
typedef struct {
    char fname[50];
    char lname[50];
    int roll;
    float GPA;
    int cid[10];
} studentInfo;

typedef struct {
    unsigned int length;
    unsigned int count;
    studentInfo *base;
    studentInfo *head;
    studentInfo *tail;
    int StudentNumber;
}FIFO_Buf_t;

//Status of FIFO:
typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_Buf_Status;








/*      Declarations for FIFO       */
#define element_type uint8_t
#define width 5
element_type buff[width];

FIFO_Buf_Status FIFO_init (FIFO_Buf_t* fifo, element_type *buf, uint32_t length);
FIFO_Buf_Status FIFO_IS_FULL (FIFO_Buf_t* fifo);







/*      Function Declaration        */

/*Option(1): Adds student via a seperate file*/
void fileAddStudent(FIFO_Buf_t *FIFO);

/*Option(2): Adds student manually via user input*/
void ManualAddStudent(FIFO_Buf_t *FIFO);

/*Option(3): Finds student details by role number*/
void findDR(FIFO_Buf_t *FIFO);

/*Option(4): Finds student details by name*/
void findDN(FIFO_Buf_t *FIFO);

/*Option(5): Finds student details by course ID*/
void findDC(FIFO_Buf_t *FIFO);

/*Option(6): Finds the total number of students*/
void findTOT(FIFO_Buf_t *FIFO);

/*Option(7): Deletes student details by role number*/
void RDelete(FIFO_Buf_t *FIFO);

/*Option(8): Updates student details by role number*/
void RUpdate(FIFO_Buf_t *FIFO);

/*Option(9): Shows information for all students in the list*/
void SShow(FIFO_Buf_t *FIFO);



#endif