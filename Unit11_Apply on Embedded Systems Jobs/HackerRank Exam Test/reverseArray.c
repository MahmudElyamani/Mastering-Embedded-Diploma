//Mastering Embedded System Online Diploma
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS
#include <stdio.h>

void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);

  printf("\n");
}

void rvereseArray(int arr[], int size)
{
    //------------------------
   // Write your Code Here
    //-----------------------
    int temp[size];
    for (int i=0; i<size/2; i++)
    {
        temp[i] = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp[i];
    }
    
}

int main()
{
    int arr[7] ;
    int n = 7 ;
    int i =0 ;
    for(i=0 ; i<7 ; i++)
        scanf("%d",&arr[i]);
    rvereseArray(arr,n);
    printArray(arr, n);
    return 0;
}