#include <stdio.h>

int main()
{
    /*  Ex.4    */
    float num;
    printf("Enter a number: ");
    scanf("%f",&num);
    if (num > 0)
    printf("%2.2f is positive",num);
    else if (num == 0)
    printf("%f is zero",num);
    else
    printf("%2.2f is negative.",num);
    
    return 0;
}