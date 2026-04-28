#include <stdio.h>

int main()
{
    /*  Ex.3    */
    float num1,num2,num3;
    printf("Enter three numbers: ");
    scanf ("%f\n\r %f\n\r %f",&num1,&num2,&num3);
    if (num1 >= num2)
    {
        if (num1 >= num3)
        printf("Largest number = %2.2f",num1);
        else
        printf("Largest number = %2.2f",num3);
    }
    else if (num2 >= num3)
    printf("Largest number = %2.2f",num2);
    else
    printf("Largest number = %2.2f",num3);

    return 0;
}