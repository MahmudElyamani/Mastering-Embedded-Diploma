//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS

typedef unsigned int uint32;
typedef unsigned char uint8;
typedef int sint32;

#include "stdio.h"

#define TWO                 (uint8)(2)
#define ONE                 (uint8)(1)
#define ZERO                (uint8)(0)
#define EMPTY               (uint8)(0xFF)
#define STRING_END          (uint8)('\0')

sint32 au8OutputArray[256];

sint32* vidPrintReverseExclusive(sint32 u8LowerNumber, sint32 u8HigherNumber, sint32* result_size)
{
    uint32 i = u8HigherNumber-1, j = 0;
    while (i>u8LowerNumber)
    {
        au8OutputArray[j] = i;
        j++;
        i--;
        *result_size += 1;
    }
    return au8OutputArray;
}



int main()
{
    sint32 upperVal , LowerVal ;
    sint32 i = ZERO;
    sint32 resultSize = 0;
    scanf ("%d,%d",&LowerVal,&upperVal);
    vidPrintReverseExclusive(LowerVal, upperVal, &resultSize);
    while(resultSize--)
    {
        printf("%d,", au8OutputArray[i++]);
    }
    return 0;
}