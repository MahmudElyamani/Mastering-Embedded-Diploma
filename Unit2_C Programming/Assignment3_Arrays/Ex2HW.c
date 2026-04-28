#include <stdio.h>

int main()
{
  /*    Ex.2    */
    char text[100];
    int count=0, i;
    printf("Enter a string: ");
    gets(text);
    for (i=0; i<sizeof(text); i++)
    {
        if(text[i] == '\0')
        break;
        count++;
    }
    printf("Length of string: %d",count);
    
    return 0;
}