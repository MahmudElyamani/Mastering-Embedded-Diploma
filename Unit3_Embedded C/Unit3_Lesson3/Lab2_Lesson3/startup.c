//Eng. Mahmood

#include <stdint.h>
#define STACK_Start_SP 0x20001000
extern int main(void);

void Reset_Handler();

void Default_handler()
{
    Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void H_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_Fault(void) __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;

uint32_t vectors[] __attribute__((section(".vectors")))= 
{
    (uint32_t)  0x2001000,
    (uint32_t)  &Reset_Handler,
    (uint32_t)  &NMI_Handler,
    (uint32_t)  &H_Fault_Handler,
    (uint32_t)  &Bus_Fault,
    (uint32_t)  &Usage_Fault_Handler
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