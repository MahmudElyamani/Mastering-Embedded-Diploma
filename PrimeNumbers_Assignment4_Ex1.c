#include<stdio.h>
#include<string.h>

int isprime(int x)
{
    int num=x;
    int i;
    if (x==2 || x==3 || x==5 || x==7)
    return 1;
    else if (x % 2 == 0 || x % 3 ==0 || x % 5 == 0 || x % 7 == 0)
    return 0;
    else
    {
        for (i=x-1; i>1; i--)
        {
            if (num%i == 0.0)
            {
            return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int n1,n2;
    printf("Enter two numbers: ");
    scanf("%d %d",&n1,&n2);
    printf("Prime numbers between %d and %d are: ",n1,n2);
    for (; n1<=n2; n1++)
    {
        if(isprime(n1) == 1)
        printf("%d ",n1);
    }
}

