//Mastering Embedded System Online Diploma
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS

#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned int uint32;

#define ONE                 (uint8)(1)
#define ZERO                (uint8)(0)

uint32 getNumbitsize(uint32 u32InputNumber)
{
    int count = 0;
    while(u32InputNumber/2 != 0)
    {
        count++;
        u32InputNumber /= 2;
    }
    return count+1;
}

uint32 u8CountOnes(uint32 u32InputNumber)
{
    uint32 u32OnesCounter = ZERO;
    //------------------------
   // Write your Code Here
    //-----------------------
    int size = getNumbitsize(u32InputNumber);
    for (int i=0; i<size; i++)
    {
        if ( ((u32InputNumber&(1<<i))>>i) == 1 )
        u32OnesCounter++;
    }
    return u32OnesCounter;
}

uint32 u8CountZeros(uint32 u32InputNumber)
{
    uint32 u32ZerosCounter = ZERO;

       //------------------------
   // Write your Code Here
    //-----------------------
    int size = getNumbitsize(u32InputNumber);
    for (int i=0; i<size; i++)
    {
        if ( ((u32InputNumber&(1<<i))>>i) == 0 )
        u32ZerosCounter++;
    }
    return u32ZerosCounter;
}

int main()
{
    uint32 Number;
    scanf("%d",&Number);

    printf("Number: %d, ONES: %u, ZEROS: %u\n", Number, u8CountOnes(Number), u8CountZeros(Number));


    return 0;
}