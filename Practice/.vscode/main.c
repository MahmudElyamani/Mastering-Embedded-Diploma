#include <stdio.h>
#include <string.h>
#include <stdlib.h>
atol();
int main()
{
    char c[100];
    printf("Testing\n");
    printf("Enter an equation: ");
    scanf("%s",&c);
    printf("The integer form of your equation is: %d",atoi(c));
    return 0;
}