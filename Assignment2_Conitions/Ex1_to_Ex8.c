//Assignment 2
//Unit 2 Lesson 3
//by: Mahmoud Elyamani

#include <stdio.h>
int main()
{
    /*Ex.1:
    int i,o;
    printf("Enter an integer you want to check: ");
    scanf("%d",&i);
    o = i%2;
    if (o == 0)
    printf("%d is even",i);
    else
    printf("%d is odd",i);
    */

    /*Ex.2
    char c;
    printf("Enter an alphabet: ");
    scanf("%c",&c);
    if (c == 'a'||c =='e'||c =='i'||c =='o'||c =='u'||c == 'A'||c =='E'||c =='I'||c =='O'||c =='U')
    printf("%c is a vowel.",c);
    else
    printf("%c is a constant.");
    */

    /*Ex.3
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
    */

    /*Ex.4
    float num;
    printf("Enter a number: ");
    scanf("%f",&num);
    if (num > 0)
    printf("%2.2f is positive",num);
    else if (num == 0)
    printf("%f is zero",num);
    else
    printf("%2.2f is negative.",num);
    */

    /*Ex.5
    char c;
    printf("Enter a character: ");
    scanf("%c",&c);
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
    printf("%c is an alphabet.",c);
    else 
    printf("%c is not an alphabet.",c);
    */

    /*Ex.6
    int j,sum = 0;
    printf("Enter an integer: ");
    scanf("%d",&j);
        for (int i=0;i<=j;i++)
        {
        Sum += i;
        }
        printf("Sum = %d",fac);
    */

    /*Ex.7
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
    */

    /*Ex.8
    float val1,val2,out;
    char operand;
    printf("Enter operator either + or - or * or divide : ");
    scanf("%c",&operand);
    printf("Enter two operands: ");
    scanf("%f \n\r %f",&val1,&val2);
    switch (operand)
    {
        case('+'):
        out = val1+val2;
        break;
        case('-'):
        out = val1-val2;
        break;
        case('*'):
        out = val1*val2;
        break;
        case('/'):
        out = val1/val2;
        break;
    }
    printf("%2.2f %c %2.2f = %2.2f",val1,operand,val2,out);
    */
}
