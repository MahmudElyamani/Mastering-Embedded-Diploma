//Mastering Embedded System Online Diploma
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS

#include <stdio.h>
#include <stdlib.h>

void a2i(char*);

int main()
{
    char string[5];

    // Enter a string value:
    scanf("%4s", string);

    a2i(string);

    return 0;
}

/* Function definition: a2i() */
void a2i(char* txt)
{
    int sum, digit, i;

    for (i = 0; txt[i] != '\0'; i++)
    {
        digit = txt[i] - '0';

        printf("Integer Value:%d\n", digit);
    }
}
