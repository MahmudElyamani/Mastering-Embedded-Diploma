#include<stdio.h>

int ones(int x)
{
    int count = 0,i;
    for (i=x;i>=0;i--)
    {
        if(x & 1 == 1)
        count++;
        x = x>>1;
    }
    return count;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("%d has %d ones in binary.",num, ones(num));
}
