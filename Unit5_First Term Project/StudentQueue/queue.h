//--- ✄ --------- 2026.04.26 11:58 -------------------
//made by Eng. Mahmood Elyamani

#ifndef QUEUE_H_
#define QUEUE_H_



/*      User Definition        */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int roll;
    char fname[50];
    char course[50];
    float grade;
} Student;

typedef struct {
    Student data[MAX];
    int front;
    int rear;
} Queue;

/* Core queue operations */
void initQueue();
int isEmpty();
int isFull();
void enqueue(Student s);
void dequeue();


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