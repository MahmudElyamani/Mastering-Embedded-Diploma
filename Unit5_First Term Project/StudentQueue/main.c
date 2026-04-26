//--- ✄ --------- 2026.04.26 11:49 -------------------
//Made by Eng. Mahmoud Elyamani
//2nd Project of the First term
//Unit5

#include "queue.h"

int main()
{
    /*      Selection is for the user input and Exit condition is for condition 10      */
    char selection, exitCondition=0;

    /*      Starting statement. Only performed once on boot up      */
    printf("Welcome to the Student Management System\n");
    while(!exitCondition)
    {
        /*      Presented Options to the user on start      */
        printf("1. Add Student Details From Text File\n");
        printf("2. Add Student Details Manually\n");
        printf("3. Find Student Details by Role Number\n");
        printf("4. Find Student Details by First Name\n");
        printf("5. Find Student Details by Course ID\n");
        printf("6. Find the Total Number of Students\n");
        printf("7. Delete the Student Details by Roll Number\n");
        printf("8. Update the Student Details by Roll Number\n");
        printf("9. Show All information\n");
        printf("10. Exit System\n");
        printf("Choose the task that you want to perform: ");

        /*      Gets the user's selected number     */
        gets(selection);
        switch (selection)
        {
            case '1':
            fileAddStudent();
            break;
            case '2':
            ManualAddStudent();
            break;
            case '3':
            findDR();
            break;
            case '4':
            findDN();
            break;
            case '5':
            findDC();
            break;
            case '6':
            findTOT();
            break;
            case '7':
            RDelete();
            break;
            case '8':
            RUpdate();
            break;
            case '9':
            SShow();
            break;
            case '10':
            printf("=====Thank you for using the Student Queue management System====");
            exitCondition = 1;
            break;
            default:
            printf("!Please input a valid option number!\n");
            break;
        }
    }
}