#include<stdio.h>

int main()
{
    int arr[15], aSize, *p, i;
    p = arr;
    printf("Enter the number of elements to store in the array (max 15): ");
    scanf("%d",&aSize);
    printf("Input the %d numbers of the array: \n",aSize);
    for(i=0; i<aSize; i++)
    {
        printf("element(%d): ",i+1);
        scanf("%d",p);
        p++;
    }
    printf("The elements of the array in reverse order are: \n");
    for(i=0; i<aSize; i++)
    {
        p--;
        printf("element(%d) : %d\n",i,*p);
    }
}
