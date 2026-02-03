#include<stdio.h>

int main()
{
    char c[100], *pC;
    printf("Input a string: ");
    scanf("%s",c);
    pC = c;
    while(*pC != '\n' && *pC != '\0')
    pC++;
    do
    {
        pC--;
        printf("%c",*pC);
    } while (pC != c);
}
