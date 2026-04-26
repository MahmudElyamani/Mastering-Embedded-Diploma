//--- ✄ --------- 2026.04.26 11:58 -------------------
//made by Eng. Mahmood Elyamani

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct {
    char fname[50];
    char lname[50];
    int roll;
    float GPA;
    int cid[10];
} studentInfo;


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