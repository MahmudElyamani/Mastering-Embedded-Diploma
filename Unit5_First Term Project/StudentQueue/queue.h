//--- ✄ --------- 2026.04.26 11:58 -------------------
//made by Eng. Mahmood Elyamani

#ifndef QUEUE_H_
#define QUEUE_H_

/*      User Definition        */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/* -------- Student Structure -------- */
typedef struct
{
    int roll;
    char firstName[50];
    char lastName[50];
    float GPA;
    int courses[5];
} Student_info_t;

/* -------- FIFO Buffer Structure -------- */
typedef struct
{
    int length;
    int count;
    Student_info_t *base;
    Student_info_t *head;
    Student_info_t *tail;
} FIFO_Buf_t;

/* -------- FIFO Status -------- */
typedef enum
{
    FIFO_NO_ERROR,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL
} FIFO_Status_t;

/* -------- FIFO APIs -------- */
FIFO_Status_t FIFO_Init(FIFO_Buf_t *fifo, Student_info_t *buffer, int length);
FIFO_Status_t FIFO_Enqueue(FIFO_Buf_t *fifo, Student_info_t item);
FIFO_Status_t FIFO_Dequeue(FIFO_Buf_t *fifo, Student_info_t *item);
FIFO_Status_t FIFO_IsFull(FIFO_Buf_t *fifo);

/* -------- Global Buffer -------- */
extern FIFO_Buf_t gBuffer;

/*      Function Declaration        */

/*Option(1): Adds student via a seperate file*/
void fileAddStudent();

/*Option(2): Adds student manually via user input*/
void ManualAddStudent();

/*Option(3): Finds student details by role number*/
void findDR();

/*Option(4): Finds student details by name*/
void findDN();

/*Option(5): Finds student details by course ID*/
void findDC();

/*Option(6): Finds the total number of students*/
void findTOT();

/*Option(7): Deletes student details by role number*/
void RDelete();

/*Option(8): Updates student details by role number*/
void RUpdate();

/*Option(9): Shows information for all students in the list*/
void SShow();

#endif

