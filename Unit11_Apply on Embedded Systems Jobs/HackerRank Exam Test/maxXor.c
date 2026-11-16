
#include <stdio.h>

typedef unsigned int uint32;
typedef unsigned char uint8;

#define ZERO  (uint8)(0)

uint32 maximum_XOR(uint32 a, uint32 b)
{
    uint32 max_xor = ZERO;
    uint32 temp = a ^ b;

    while (temp)
    {
        max_xor = (max_xor << 1) | 1;
        temp >>= 1;
    }

    return max_xor;
}

int main()
{
    uint32 L, R;

    scanf("%u", &L);
    scanf("%u", &R);

    printf("%u\n", maximum_XOR(L, R));

    return 0;
}
