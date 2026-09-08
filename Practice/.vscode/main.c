#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i=0; i<15; i++)
    {
        printf("/*============================ EXTI%d =========================*/\n",i);
        printf("#define EXTI%dP%c%d                 (EXTI_GPIO_Mapping_t){EXTI%d, GPIO%c, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,'A',i,i,'A',i,i);
        printf("#define EXTI%dP%c%d                 (EXTI_GPIO_Mapping_t){EXTI%d, GPIO%c, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,'B',i,i,'B',i,i);
        printf("#define EXTI%dP%c%d                 (EXTI_GPIO_Mapping_t){EXTI%d, GPIO%c, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,'C',i,i,'C',i,i);
        printf("#define EXTI%dP%c%d                 (EXTI_GPIO_Mapping_t){EXTI%d, GPIO%c, GPIO_PIN_%d, EXTI%d_IRQ}\n",i,'D',i,i,'D',i,i);
        printf("\n\n\n\r");
    }
    return 0;
}