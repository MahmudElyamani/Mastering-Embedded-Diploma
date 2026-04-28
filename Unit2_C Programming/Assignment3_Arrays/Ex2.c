#include <stdio.h>

int main()
{
    /*  Ex.2    */
    float a[100],sum=0;
    int i,j,num;
    printf("Enter the number of data: ");
    scanf("%d",&num);
    for (i=0; i<num; i++)
    {
        printf("%d. Enter number: ",i+1);
        scanf("%f",&a[i]);
        sum += a[i];
    }
    printf("Average = %2.2f",sum/num);
    
    return 0;
}