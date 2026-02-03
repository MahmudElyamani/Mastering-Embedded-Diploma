#include<stdio.h>

int main()
{
    char A = 'A', *pA;
    int i;
    pA = &A;
    printf("The Alphabets are: \n");
    for(i=0; i<26; i++)
    {
        printf("%c\t",*pA);
        A++;
    }
    return 0;
}
