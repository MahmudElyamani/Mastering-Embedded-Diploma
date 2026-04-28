#include <stdio.h>

int main()
{
    /*  Ex.8    */ 
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
    
    return 0;
}