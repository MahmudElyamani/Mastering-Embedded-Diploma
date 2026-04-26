#include<stdio.h>

struct SEmployee{
    char name[20];
    int ID;
};

int main()
{
    struct SEmployee emp1 = {"Alex",1002}, emp2 = {"Alexa",1003};
    struct SEmployee *arrptr[] = {&emp1, &emp2};
    struct SEmployee **ptrptr = arrptr;
    printf("Employee Name: %s\nEmployee ID: %d\r\n",ptrptr[0]->name,ptrptr[0]->ID);
}
