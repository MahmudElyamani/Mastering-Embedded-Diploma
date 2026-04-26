//Eng. Mahmood

#include <stdint.h>

extern int main(void);

void Reset_Handler();

void Default_Handler()
{
    Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void H_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;

static unsigned long Stack_top[256] ;                                       
//extern unsigned int _stack_top;
// uint32_t vectors[] __attribute__((section(".vectors")))= 
// {
//     (uint32_t)  (&Stack_top[0] + sizeof(Stack_top)),
//     (uint32_t)  &Reset_Handler,
//     (uint32_t)  &NMI_Handler,
//     (uint32_t)  &H_Fault_Handler,
// };
void (*const g_p_fn_vectors[])() __attribute__((section(".vectors")))= 
{
    (void(*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
    &Reset_Handler,
    &NMI_Handler,
    &H_Fault_Handler
};

extern unsigned int _E_text;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler (void)
{
    //copy data section from flash to ram
    unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
    main();
}