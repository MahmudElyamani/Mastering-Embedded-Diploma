#include <stdio.h>

int main()
{
    /*  Ex.7    */
    int j,fac = 1;
    printf("Enter an integer: ");
    scanf("%d",&j);
    if (j >= 1)
    {
        for (int i=1;i<j;i++)
        {
        fac *= i;
        }
        printf("Factorial = %d",fac);
    }
    else if (j == 0)
    printf("Fractorial of 0 is 1");
    else
    printf("Eroor!!! Factorial of negative number doesn't exist.");
    
    return 0;
}