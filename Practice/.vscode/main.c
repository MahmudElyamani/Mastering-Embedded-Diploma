#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

//C function to count number of zeros and ones in the binary of a number.
void CountZerosOnes(uint32_t Number)
{
    int tempNum = Number, zeros=0, ones=0;
    while(tempNum)
    {
        if( (tempNum & 1) == 1 )
        ones++;
        else
        zeros++;

        tempNum >>= 1;
    }
    printf("%d's binary has %d zeros and %d ones.\n",Number,zeros,ones);
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf ("%d",&num);
    CountZerosOnes(num);
    return 0;
}


