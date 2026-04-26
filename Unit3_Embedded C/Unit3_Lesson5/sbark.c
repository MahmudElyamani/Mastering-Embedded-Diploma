#include <stdio.h>

#define heap_width 100
void* _sbark(int incr)
{
    //defining the start of the heap
    static unsigned char* heap_ptr = NULL;      

    //Placeholder for the previous address of memory in heap
    unsigned char* prev_heap_ptr = NULL;      

    extern unsigned int* _E_bss;        

    //First time initialization
    if (heap_ptr == NULL)          
    heap_ptr = (unsigned char*)&_E_bss;
    
    prev_heap_ptr = heap_ptr;

    //safety measure to assure the memory allocation doesn't exceed its limitation
    if (heap_ptr + incr > ((unsigned char*)&_E_bss + heap_width ))      
    return (void*)NULL;

    //Booking a size equals to: incr
    heap_ptr += incr;       

    return (void*)prev_heap_ptr;
}

