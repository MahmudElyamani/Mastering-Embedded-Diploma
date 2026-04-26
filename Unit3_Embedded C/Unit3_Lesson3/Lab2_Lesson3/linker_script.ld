/*
    Linker script for the STM32F103C done from scratch
    16/3/2026       9:25am
    @Mahmood Elyamani
*/

MEMORY
{
    flash(RX)   :   ORIGIN = 0x08000000, LENGTH = 128k
    sram(RWX)   :   ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = . ;
    } > flash
    .data : {
        _S_DATA = . ;
        *(.data)
        . = ALIGN(4) ;
        _E_DATA = . ;
    }> sram AT> flash

    .bss : {
    _S_bss = . ;
    *(.bss)
    _E_bss = . ;
    }> sram
}