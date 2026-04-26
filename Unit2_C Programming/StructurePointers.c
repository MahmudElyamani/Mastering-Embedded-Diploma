#include<stdio.h>
#include<string.h>
struct SDataSet
{
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
};
struct SDataSet data1;
void print_memory_range(char* base, int size)
{
    int i = 0;
    for(i=0; i<size; i++)
    {
        printf("%p\t%x\n",base, (unsigned char)*base);
        base++;
    }
}


int main()
{
    data1.data1 = 0x11;
    data1.data2 = 0xFFFFEEEE;
    data1.data3 = 0x22;
    data1.data4 = 0xABCD;
    print_memory_range(&data1, sizeof(data1));
    struct SDataSet* P_struct = &data1;
    P_struct->data1 = 0x12;
    P_struct->data2 = 0xEEEEFFFF;
    P_struct->data3 = 0x55;
    P_struct->data4 = 0xEFBA;
    printf("After editing using pointer structure: \n");
    print_memory_range(&data1, sizeof(data1));
    return 0;
}
