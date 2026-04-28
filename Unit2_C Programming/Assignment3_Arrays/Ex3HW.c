#include <stdio.h>
#include <string.h>

int main()
{
    /*  Ex.3    */
    char text [100], rev[100];
    int i, j=0;
    printf("Enter the string: ");
    gets(text);
    for (i=strlen(text); i>0; i--)
    {
        rev[j] = text[i-1];
        j++;
    }
    rev[j] = '\0';
    printf("Reverse sting is: %s",rev);
    
    return 0;
}