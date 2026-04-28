#include<stdio.h>

float sqroot (int x)
{
    if (x<0)
    return -1;
    float val=0, out=0;
    for (; out <= x; val++)
    {
        out = val*val;
        if(out == x)
        return val;
        if(out > x)
        {
            for(; out>x; val-=0.001)
            out = val*val;
            return val;
        }
    }
    return 0;
}
int main()
{
    int y;
    printf("Enter an integer: ");
    scanf("%d",&y);
    printf("The Square root of %d is: %3.3f",y,sqroot(y));
}

