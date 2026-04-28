//Created by Mahmoud Elyamani
#include <stdio.h>

int main()
{
    /*  Ex.6:   */
    float a,b,c;
    printf("Enter value of a: ");
    scanf("%f",&a);
    printf("Enter value of b: ");
    scanf("%f",&b);
    c = b;
    b = a;
    a = c;
    printf("After swapping, value of a = %2.2f\n\r",a);
    printf("After swapping, value of b = %2.2f",b);
    return 0;
}