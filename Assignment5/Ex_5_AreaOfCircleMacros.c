#include<stdio.h>
#include<string.h>

#define PI 3.14159
#define Area(x) PI*x*x

int main()
{
    int x;
    printf("Enter radius: ");
    scanf("%d",&x);
    printf("Area = %.2f",Area(x));
}
