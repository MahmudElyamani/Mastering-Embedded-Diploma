//Mastering Embedded System Online Diploma
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS
#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned int uint32;

#define THREE               (uint8)(3)
#define ONE                 (uint8)(1)
#define ZERO                (uint8)(0)

uint8 u8IsPowerOfThree(uint32 u32_Number)
{
    if (u32_Number == ZERO)
        return ZERO;

    while (u32_Number % THREE == ZERO)
    {
        u32_Number /= THREE;
    }

    if (u32_Number == ONE)
        return ONE;
    else
        return ZERO;
}

int main()
{
    uint32 i = 0 ;
    scanf("%d",&i);
    printf("u8IsPowerOfThree=%d\n",u8IsPowerOfThree(i));
    return 0;
}
