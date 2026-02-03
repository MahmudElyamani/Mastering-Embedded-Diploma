#include<stdio.h>

int main()
{
    int m = 29, *ab;
    ab = &m;
    printf("Adress of m: 0x%x\nValue of m: %d\n",&m,m);
    m = 34;
    printf("The value of m assigned to 34 now.\n");
    printf("Adress of pointer ab: 0x%x\nContent of pointer ab: %d\n",ab,*ab);
    *ab = 7;
    printf("The pointer variable ab is assigned with value 7 now.\n");
    printf("Adress of m: 0x%x\nValue of m: %d\r\n",&m,m);
}

