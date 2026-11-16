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


void sortArray(int arr[], int size)
{
   //------------------------
   // Write your Code Here
    //-----------------------
    int temp,Largest=0;
    //find the largest number out of the 7
    for (int i = size-1; i>=0; i--)
    {
        for (int j = 0; j<i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int arr[7] ;
    int n = 7 ;
    int i =0 ;
    for(i=0 ; i<7 ; i++)
        scanf("%d",&arr[i]);
    sortArray(arr,n);
    printArray(arr, n);
    return 0;
}
