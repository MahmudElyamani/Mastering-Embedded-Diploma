#include <stdio.h>

int main()
{
    /*  Ex.3    */
    float m[100][100], mt[100][100];
    int i,j,r,c;
    printf("Enter rows of Matrix: ");
    scanf("%d",&r);
    printf("Enter Columns of Matrix: ");
    scanf("%d",&c);
    printf("Enter elements of matrix: \n\r");
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            printf("Enter element a%d%d: ",i+1,j+1);
            scanf("%f",&m[i][j]);
            mt[j][i] = m[i][j];
        }
    }
    printf("Entered Matrix: \n\r");
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("%1.1f  ",m[i][j]);
        }
        printf("\n\r");
    }
    printf("Transpose of Matrix: \n\r");
    for (i=0; i<c; i++)
    {
        for (j=0; j<r; j++)
        {
            printf("%1.1f  ",mt[i][j]);
        }
        printf("\n\r");
    }
    
    return 0;
}