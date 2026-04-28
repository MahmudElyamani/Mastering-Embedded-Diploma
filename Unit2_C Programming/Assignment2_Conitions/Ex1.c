//Assignment 2
//Unit 2 Lesson 3
//by: Mahmoud Elyamani

#include <stdio.h>
int main()
{
    /*  Ex.1:   */
    int i,o;
    printf("Enter an integer you want to check: ");
    scanf("%d",&i);
    o = i%2;
    if (o == 0)
    printf("%d is even",i);
    else
    printf("%d is odd",i);
    
    return 0;
}
