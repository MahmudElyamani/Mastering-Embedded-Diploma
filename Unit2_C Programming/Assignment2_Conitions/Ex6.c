#include <stdio.h>

int main()
{
    /*    Ex.6    */
    int j,sum = 0;
    printf("Enter an integer: ");
    scanf("%d",&j);
        for (int i=0;i<=j;i++)
        {
        sum += i;
        }
        printf("Sum = %d",sum);
    
    return 0;
}