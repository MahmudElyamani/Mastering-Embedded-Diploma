//Mastering Embedded System Online Diploma 
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda 
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS
#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef int sint32;

#define ONE                                 (uint8)(1)
#define ZERO                                (uint8)(0)

sint32 CheckEvenOrOdd(uint32 u32InputNumber)
{
 // .................Enter Your Code............
 return u32InputNumber % 2 == 0? 0:1;
}
int main()
{
    int x = 0 ;
    scanf ("%d",&x);
   if (CheckEvenOrOdd( x) == 1) 
       printf ("odd");
    else 
        printf("even");
    
    return 0;
}
