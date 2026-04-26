//--- ✄ --------- 2026.04.11 12:54 -------------------
//Created by Eng. Mahmoud Elyamani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


/*      Effective Data      */
struct Sdata
{
    int ID;
    char name[40];
    float height;

};

/*      Linked List node        */
struct SStudent
{
    struct Sdata student;

    //Pointer of the same type that points to the next student in order  
    struct SStudent* pNextStudent;
};

//The head of our linked list:
struct SStudent *gpFirstStudent = NULL;

void AddStudent()
{
    struct SStudent *pNewStudent;
    struct SStudent *pLastStudent;
    char tempText[40];
    //Checks if the list is empty, if not it navigates to the target position
    if (gpFirstStudent == NULL)
    {
        //create a new record
        pNewStudent = (struct SStudent*)malloc (sizeof(struct SStudent));
        //assign it to gpfirst
        gpFirstStudent = pNewStudent;
    }
    else
    {
        //navigate until we reach last record
        pLastStudent = gpFirstStudent;
        while (pLastStudent->pNextStudent)
        pLastStudent = pLastStudent->pNextStudent;

        //create a new record
        pNewStudent = (struct SStudent*)malloc (sizeof(struct SStudent));
        pLastStudent->pNextStudent = pNewStudent;
    }
    //fill new record
    printf("\n Enter the ID: ");
    gets(tempText);
    pNewStudent->student.ID = atoi(tempText);

    printf("Enter student full name: ");
    gets(pNewStudent->student.name);

    printf("Enter student height: ");
    gets(tempText);
    pNewStudent->student.height = (float)atof(tempText);

    //set the next poiter (new_student) null
    pNewStudent->pNextStudent = NULL;
}

int DeleteStudent()
{
    char tempText[40];
    int selectedID;

    //Gets the selected ID
    printf("\n Ener the student id to be deleted: ");
    gets(tempText);
    selectedID = atoi(tempText);

    //checks to see if the list is empty
    if (gpFirstStudent)
    {
        struct SStudent *pSelectedStudent = gpFirstStudent;
        struct SStudent *pPreviousStudent = NULL;

        //compare each node with the selected ID
        while(pSelectedStudent)
        {
            if (pSelectedStudent->student.ID == selectedID)
            {
                if (pPreviousStudent)
                {
                    pPreviousStudent->pNextStudent = pSelectedStudent->pNextStudent;
                }
                else
                {
                    gpFirstStudent = pSelectedStudent->pNextStudent;
                }
                printf("\nStudent deleted:\n");
                printf("Name: %s\n",pSelectedStudent->student.name);
                printf("ID: %d\n",pSelectedStudent->student.ID);
                free (pSelectedStudent);
                return 1;
            }
            pPreviousStudent = pSelectedStudent;
            pSelectedStudent = pSelectedStudent->pNextStudent;
        }
    }
    //if the input value exceeds the number of nodes in the list, prints out an error message:
    printf("\n Cannot find student ID");
    return 0;
}


void ViewStudents()
{
    struct SStudent *pCurrentStudent = gpFirstStudent;
    unsigned int count = 0;

    //checks if the list is empty
    if (gpFirstStudent == NULL)
    printf("\n This list is empty");
    else
    {
        while (pCurrentStudent)
        {
            printf("\n record number %d ",count+1);
            printf("\n ID: %d",pCurrentStudent->student.ID);
            printf("\n Name: %s",pCurrentStudent->student.name);
            printf("\n Height: %.2f\n",pCurrentStudent->student.height);
            pCurrentStudent = pCurrentStudent->pNextStudent;
            count++;
        }
    }
}


void DeleteAll()
{
    struct SStudent *pCurrentStudent = gpFirstStudent;

    //checks if the list is empty
    if (gpFirstStudent == NULL)
    printf("\n This list is empty");
    else
    {
        while (pCurrentStudent)
        {
            struct SStudent *pTempStudent = pCurrentStudent;
            pCurrentStudent = pCurrentStudent->pNextStudent;
            free(pTempStudent);
        }
        gpFirstStudent = NULL;
    }  
}

int getNth()
{
    char tempText[10];
    int solNum, indexNumber, count = 1, count2= 1;
    struct SStudent *pTempStudent = gpFirstStudent;
    struct SStudent *mainPtr      = gpFirstStudent;
    struct SStudent *refPtr       = gpFirstStudent;
    if(!pTempStudent)
    {
        printf("\nThere are no students on this list.\n");
        return 0;
    }
    printf("\nPlease pick a solution method:");
    printf("\n1. From start ");
    printf("\n2. From End ");
    printf("\n3. Exit\n");
    gets(tempText);
    solNum = atoi(tempText);
    switch (solNum)
    {
        case 1:
        printf("\nEnter an index number: ");
        gets(tempText);
        indexNumber = atoi(tempText);
        while(count != indexNumber)
        {
            if (pTempStudent->pNextStudent)
            {
                pTempStudent = pTempStudent->pNextStudent;
                count++;
            }
            else
            {
                printf("The index number(%d) exceeds the number of nodes(%d)!\n",indexNumber,count);
                return 0;
            }
        }
        printf("The index number %x has node ID of: %d",indexNumber,pTempStudent->student.ID);
        break;
        case 2:
        printf("\nEnter an index number: ");
        gets(tempText);
        indexNumber = atoi(tempText);
        while (refPtr)
        {
            refPtr = refPtr->pNextStudent;
            count++;
        }
        if ((count - indexNumber) < 0)
        {
            printf("The index number(%d) exceeds the number of nodes(%d)!\n",indexNumber,count);
            return 0;
        }
        while (count2 != (count-indexNumber))
        {
            mainPtr = mainPtr->pNextStudent;
            count2++;
        }
        printf("The index number %x has node ID of: %d",indexNumber,mainPtr->student.ID);
        break;
        case 3:
        break;
        default:
        printf("\nThe number you entered is not valid, try again.");
        getNth();
        break;
    }
    return 1;
}

int lengthRecursive(struct SStudent *pStudent)
{
    if (pStudent == NULL)
    return 0;
    else
    {
        return 1 + lengthRecursive(pStudent->pNextStudent);
    }
}

int findLength()
{
    char tempText[10];
    int solNum, count = 0;
    struct SStudent *pTempStudent = gpFirstStudent;
    printf("\nPlease pick a solution method:");
    printf("\n1. Iterative");
    printf("\n2. Recursive");
    printf("\n3. Exit\n");
    gets(tempText);
    solNum = atoi(tempText);
    if(pTempStudent == NULL)
    {
        printf("\nLength = 0");
        return 0;
    }
    switch (solNum)
    {
        case 1:
        while (pTempStudent)
        {
            pTempStudent = pTempStudent->pNextStudent;
            count++;
        }
        printf("\nLength = %d using iteritve mehod.\n",count);
        break;
        case 2:
        count = lengthRecursive(pTempStudent);
        printf("\nLength = %d using recursive mehod.\n",count);
        break;
        case 3:
        break;
        default:
        printf("\nThe number you entered is not valid, try again.");
        findLength();
        break;
    }
    return 1;
}

void findMiddle()
{
    struct SStudent *refPtr     = gpFirstStudent;
    struct SStudent *mainPtr   = gpFirstStudent;
    int count=1, count2=1;
    char condition = 1;
    if  (!gpFirstStudent)
    printf("\nThere's no students on this list.");
    else
    {
        while (refPtr->pNextStudent)
        {
            refPtr = refPtr->pNextStudent;
            count++;
        }
        while (count2 <= (count/2))
        {
            if (count < 3)
            {
                printf("\nThere's no sufficient amount of nodes to find the middle.\n");
                condition = 0;
                break;
            }
            mainPtr = mainPtr->pNextStudent;
            count2++;
        }
        if (condition)
        {
            printf("\n The middle of the list is node no.%d",count2);
            printf("\n ID: %d",mainPtr->student.ID);
            printf("\n Name: %s",mainPtr->student.name);
            printf("\n Height: %.2f",mainPtr->student.height);
        }
    }
}

void reverseList()
{
    struct SStudent *pPreviousStudent   = NULL;
    struct SStudent *pCurrentStudent    = gpFirstStudent;
    struct SStudent *pNextAddress       = gpFirstStudent;
    struct SStudent *pHolder            = gpFirstStudent;
    if (!gpFirstStudent)
    printf("\nThere are no students on this list.");
    else
    {
        while (pNextAddress)
        {
            //moved to the next element of old list
            pNextAddress = pNextAddress->pNextStudent;
            //redirecting the element to reverse direction  
            pCurrentStudent->pNextStudent = pPreviousStudent;
            //moving our location mover to a new location
            pPreviousStudent = pCurrentStudent;
            //moving our location reference to a new location
            pCurrentStudent = pNextAddress;
        }
        pNextAddress = pHolder;
        printf("\nReversing the list is now complete, please select 3 to check.");
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
        printf("\n   5: get node ID through index number ");
        printf("\n   6: Calculate length of list ");
        printf("\n   7: Find the middle of the list ");        
        printf("\n   8: Reverse list (Not Working)");        
        printf("\n -Enter option number: ");

        gets(tempText);
        printf("\n =====================================");
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
            case 5:
            getNth();
            break;
            case 6:
            findLength();
            break;
            case 7:
            findMiddle();
            break;
            case 8:
            reverseList();
            break;
            default:
            printf("\n Please input a valid number!");
            break;
        }
    }
    return 0;
}