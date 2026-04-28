//Assignment 3
//Arrays and string (Lesson 4)
//by Mahmoud Elyamani.


#include <stdio.h>
#include <string.h>
int main()
{
    /*  Ex.1    */
    float m1[2][2], m2[2][2], ms[2][2];
    int i,j;
    printf("Enter the elements of 1st matrix: \n\r");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter a%d%d: ",i+1,j+1);
            scanf("%f",&m1[i][j]);
        }
    }
    printf("Enter the elements of 2nd matrix: \n\r");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter b%d%d: ",i+1,j+1);
            scanf("%f",&m2[i][j]);
            ms[i][j]= m1[i][j]+m2[i][j];
        }
    }
    printf("Sum of Matrix: \n\r");
     for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%1.1f   ",ms[i][j]);
        }
        printf("\n\r");
    }
    return 0;
}
