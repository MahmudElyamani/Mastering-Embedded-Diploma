#include<stdio.h>

int factorial(int x)
{
    if (x != 0)
    return x * factorial(x-1); 
    else
    return 1;
}

int main()
{
    printf("%d",factorial(5));
}

