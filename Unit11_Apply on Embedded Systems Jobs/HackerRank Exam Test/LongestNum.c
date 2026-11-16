//Mastering Embedded System Online Diploma 
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda 
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS
#include <stdio.h>
#include <stdlib.h>
int func ( int arr[] , int num)
{
    //------------------------
   // Write your Code Here
    //-----------------------
    int long_occur=0,i=0,count=0;
    while(i<15)
    {
        long_occur = long_occur>=count? long_occur:count;
        if (arr[i] == num)
        count++;
        else
        count = 0;
        i++;
    }
    return long_occur;
}
int main(void) {
    int array[15] ,Input_Number,result;
    scanf("%d@%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&Input_Number,&array[0],&array[1],&array[2],&array[3],&array[4],&array[5],&array[6],&array[7],&array[8],&array[9],&array[10],&array[11],&array[12],&array[13],&array[14]);

    result = func (array,Input_Number);
    printf("%d",result);
    return 0;
}