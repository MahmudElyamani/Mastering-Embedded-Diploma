#include <stdio.h>

int main()
{
    /*  Ex.4    */
   int i,j,n;
   float a[100], newnum, numloc;
   printf("Enter number of elements: ");
   scanf("%d",&n);
   printf("Enter the elements one by one: ");
   for(i=0; i<n; i++)
   {
    scanf("%f",&a[i]);
   }
   printf("Enter the element to be inserted: ");
   scanf("%f",&newnum);
   printf("Enter its location: ");
   scanf("%f",&numloc);
   for (i=n; i>0; i--)
   {
    a[i+1] = a[i];
    if(i == numloc-1)
    {
        a[i] = newnum;
        continue;
    }
   }
   for(i=0; i<=n; i++)
   printf("%1.1f  ",a[i]);
   
    return 0;
}