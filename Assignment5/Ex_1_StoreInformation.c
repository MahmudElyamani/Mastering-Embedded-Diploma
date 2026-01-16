#include<stdio.h>
#include<string.h>

struct SStudent
{
    char name[50];
    short roll;
    float marks;
};

struct SStudent getstudent(struct SStudent x)
{
    printf("Name: ");
    scanf("%s",&x.name);
    printf("Roll number: ");
    scanf("%d",&x.roll);
    printf("Marks: ");
    scanf("%f",&x.marks);
    return x;
}

struct SStudent displaystudent(struct SStudent x)
{
    printf("Name: %s\n",x.name);
    printf("Roll: %d\n",x.roll);
    printf("Marks: %.2f",x.marks);
}

int main()
{
    struct SStudent x;
    printf("Enter information of students: \n");
    x = getstudent(x);
    printf("\n");
    printf("Displaying Information: \n");
    displaystudent(x);
}
