//Created by Mahmoud Elyamani
#include <stdio.h>

int main()
{
    /*  Ex.7:   */
    float a,b;
    printf("Enter value of a: ");
    scanf("%f",&a);
    printf("Enter value of b: ");
    scanf("%f",&b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping, value of a = %2.2f\n\r",a);
    printf("After swapping, value of b = %2.2f",b);
    return 0;
}