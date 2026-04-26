/*
Linker script for the STM32F103C done from scratch
27/3/2026       3:11pm
@Mahmood Elyamani
*/

MEMORY
{
    flash(RX)   :   ORIGIN = 0x08000000, LENGTH = 128k
    sram(RWX)   :   ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
    .text : {
        *(.vectors*)
        *(.text*)
    } > flash
    .data : {
            *(.data)
    }> flash
    .bss : {
            *(.bss)
    }> sram
}