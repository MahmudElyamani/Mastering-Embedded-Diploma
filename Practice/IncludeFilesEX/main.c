#include <stdint.h>
#include <stdio.h>
#include "a.h"
#include "b.h"
#include "c.h"

int main()
{
    S_H r;
    bf(r);
    af(r);
}

void af(S_H x)
{
    printf("Function af is a success.\n");
}

void bf(S_H x)
{
    printf("Function bf is a success.\n");
}