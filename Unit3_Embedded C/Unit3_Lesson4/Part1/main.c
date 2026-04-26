/*
Eng.Mahmut_Elyamani
Simple blink code dimenstration for TIVAC from lecture 4 Embedded Diploma
4/6/2026        10:56PM
*/


#define SYSCTL_RCGC2_R       (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R     (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R     (*((volatile unsigned long*)0x4002451C))
#define GPIO_PORTF_DATA_R    (*((volatile unsigned long*)0x400253FC))

int main()
{
    volatile unsigned long delay_count;         //used later in the code to make time delays, volatile identifier used so that the code doesn't remove it 
    SYSCTL_RCGC2_R = 0x20;      //0x20 is in accordance to the specs in order to enable the GPIO ports.
    for (delay_count = 0; delay_count < 200; delay_count++);     //delay to make sure GPIOF is up and running
    GPIO_PORTF_DIR_R |= 1<<3;       //Setting the DIRection of pin 3 in PORTF to be 1 (as in output)
    GPIO_PORTF_DEN_R |= 1<<3;       //Enabling the use of pin 3 in PORTF by setting its value to 1.
    while(1)
    {
        GPIO_PORTF_DATA_R |= 1<<3;      //writing the pin value to be high (1)
        for (delay_count = 0; delay_count < 200000; delay_count++);  //noticible time delay period to see pin during active state.
        GPIO_PORTF_DATA_R &= ~(1<<3);      //writing the pin value to be high (1)
        for (delay_count = 0; delay_count < 200000; delay_count++);  //noticible time delay period to see pin during inactive state.
    }
    
    return 0;
}