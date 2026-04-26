#include<stdio.h>

int findunique(int arr[], int n)
{
    n = n-1;
    int temp;
    for (; n>0; n--)
    {
        for(temp=0; temp<n; temp++)
        {
            if(arr[n]-arr[temp] == 0)
            break;
        }
        if (temp == n)
        return arr[n];
    }
}

int main()
{
    int a[8] = {4,2,5,2,5,7,4};
    int b[4] = {4,2,4};
    printf("Unique number for array a is: %d\n",findunique(a, 7));
    printf("Unique number for array b is: %d\n",findunique(b, 3));
}
