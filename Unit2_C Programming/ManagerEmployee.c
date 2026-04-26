#include<stdio.h>
#include<string.h>

struct SPerson
{
    char m_Name[18];
    int m_ID;
    char m_Age;
    short m_Salary;
    double m_weight;
};

int main()
{
    struct SPerson manager = 
    {"Mohamed Hady", 162, 39, 3000, 79.5};
    struct SPerson employee[] =
    {
     {"Mostafa Said",163,30,1500,81.0},
     {"Ahmed Salah",164,25,1200,91.0},
     {"Safa Fayez", 165,28,1400,65.0}
    };
    struct SPerson* p;
    p = &manager;
    printf("manager: %s\t%d\t%d\t%d\t%lf\n",p->m_Name,p->m_ID,(int)p->m_Age,(int)p->m_Salary,p->m_weight);
    p->m_Salary = 4000;
    printf("manager: %s\t%d\t%d\t%d\t%lf\r\n",manager.m_Name, manager.m_ID, (int)manager.m_Age, (int)manager.m_Salary,
    manager.m_weight);
    p = employee;
    for(int i=0; i<sizeof(employee)/sizeof(struct SPerson); i++,p++)
    printf("Employee(%d): %s\t%d\t%d\t%d\t%lf\r\n",i+1,p->m_Name,p->m_ID,(int)p->m_Age,(int)p->m_Salary,p->m_weight);
    return 0;
}
