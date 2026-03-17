#include<stdio.h>
#include<string.h>

int power(int n, int p)
{
    if (p == 0)
    return 1;
    else
    return n * power(n, p-1);
}

int main()
{
    int n,p;
    puts("Enter base number: ");
    scanf("%d",&n);
    puts("Enter power number(positive integer): ");
    scanf("%d",&p);
    printf("%d^%d = %d",n, p, power(n,p));
}

