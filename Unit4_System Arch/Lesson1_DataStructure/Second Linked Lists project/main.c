//--- ✄ --------- 2026.04.12 08:36 -------------------
//Created by Eng. Mahmoud Elyamani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct SData{
    unsigned int ID;
    unsigned char name[40];
    float height;
};

struct SStudent{
    struct SData student;
    struct SStudent *pNextStudent;
};

struct SStudent *gpFirstStudent = NULL;

void AddStudent()
{
    struct SStudent *pNewStudent;
    struct SStudent *pLastStudent;
    unsigned char tempText[40];

    //If there are no students in the list -> preform if statement
    if (gpFirstStudent == NULL)
    {
        pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
        gpFirstStudent = pNewStudent;
    }
    else
    {
    //If there are students, start the count from the very first student
        pLastStudent = gpFirstStudent;
    //point towards the next student of the last student
        while (pLastStudent->pNextStudent){
    //keep pointing until it reaches NULL, i.e the value of pNextStudent = NULL
        pLastStudent = pLastStudent->pNextStudent;
        }
    //Allocates memory the size of SStudent at that place
        pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
    //      IDK
        pLastStudent->pNextStudent = pNewStudent;
    }
    //We get inputs from the user via gets() function and then later convert it to whatever meets out needs
    printf("\nEntering New Student details:\n");
    printf("ID: ");
    gets(tempText);
    pNewStudent->student.ID = (unsigned int)atoi(tempText);

    printf("Name: ");
    gets(pNewStudent->student.name);

    printf("Height: ");
    gets(tempText);
    pNewStudent->student.height = (float)atof(tempText);

    pNewStudent->pNextStudent = NULL;
}

int DeleteStudent()
{
    if (gpFirstStudent == NULL)
    {
        printf("\nThere are no students on this list.");
        return 0;
    }
    struct SStudent *pSelectedStudent = gpFirstStudent;
    struct SStudent *pPreviousStudent = NULL;
    unsigned char tempText[40];
    int SelectedID;

    printf("\nEnter the student ID to be deleted:");
    gets(tempText);
    SelectedID = atoi(tempText);
    while(pSelectedStudent->student.ID != SelectedID)
    {
        if (pSelectedStudent)
        pSelectedStudent = pSelectedStudent->pNextStudent;
        else
        {
            printf("\nThe ID you entered doesn't exist in the list.");
            return 0;
        }
    }
    pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
    free(pSelectedStudent);
}
void ViewStudents()
{
    int count = 0;
    struct SStudent *pCurrentStudent = gpFirstStudent;
    if (pCurrentStudent == NULL)
    printf("The list is empty!\n");
    else{
        while (pCurrentStudent)
        {
            printf("Student no.%d: \n",count);
            printf("ID: %d\n",pCurrentStudent->student.ID);
            printf("Name: %s\n",pCurrentStudent->student.name);
            printf("Height: %.2f\n\n",pCurrentStudent->student.height);
            pCurrentStudent = pCurrentStudent->pNextStudent;
            count++;
        }
    }
}

void DeleteAll()
{
    struct SStudent *pCurrentStudent = gpFirstStudent;
    struct SStudent *pTempStudent = NULL;
    if (pCurrentStudent == NULL)
    printf("The list is empty\n");
    else
    {
        while(pCurrentStudent)
        {
            pTempStudent = pCurrentStudent;
            pCurrentStudent = pCurrentStudent->pNextStudent;
            free(pTempStudent);
        }
        gpFirstStudent = NULL;
        printf("Students have all been deleted.\n");
    }
}

int main()
{
    char tempText[40];
    while(1)
    {
        printf("\n =====================================");
        printf("\n   Choose one of the following options: ");
        printf("\n   1: Add a Student ");
        printf("\n   2: Delete a Student ");
        printf("\n   3: View Students ");
        printf("\n   4: Delete All Students ");
        printf("\n -Enter option number: ");

        gets(tempText);
        printf("\n =====================================\n");
        switch(atoi (tempText))
        {
            case 1:
            AddStudent();
            break;
            case 2:
            DeleteStudent();
            break;
            case 3:
            ViewStudents();
            break;
            case 4:
            DeleteAll();
            break;
            default:
            printf("\n Please input a valid number!");
            break;
        }
    }
    return 0;
}