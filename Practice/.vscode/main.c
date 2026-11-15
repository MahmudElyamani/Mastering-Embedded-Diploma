#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t numArray(uint32_t arr[], uint32_t arraySize)
{
    int result = 0;
    for (int i = 0; i < arraySize; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    

    return 0;
}