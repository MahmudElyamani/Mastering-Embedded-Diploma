#include <stdio.h>

int main()
{
    /*  Ex.5    */
    int n, loc, i, j, operation = 0;;
    float elements[30], srchd;
    printf("Enter no. elements: ");
    scanf("%d",&n);
    printf("Enter The elements: ");
    for (i=0; i<n; i++)
    scanf("%f",&elements[i]);
    printf("Enter element to be searched: ");
    scanf("%f",&srchd);
    for (i=n; i>=0; i--)
    {
        if (elements[i] == srchd)
        {
            printf("Number found at the location: %d",i+1);
            operation = 1;
        }
    }
    if (!operation)
    printf("Number not found in array!");
    
    return 0;
}