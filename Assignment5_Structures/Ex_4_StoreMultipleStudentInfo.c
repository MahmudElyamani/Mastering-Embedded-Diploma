#include<stdio.h>
#include<string.h>

struct SStudent
{
    char name[20];
    short roll;
    int marks;
};

struct SStudent GetStudent(struct SStudent x)
{
    printf("For roll number: ");
    scanf("%d",&x.roll);
    printf("Enter name: ");
    scanf("%s",&x.name);
    printf("Enter marks: ");
    scanf("%d",&x.marks);
    return x;
}

struct SStudent DispStudent(struct SStudent x)
{
    printf("Information for roll number %d: \n",x.roll);
    printf("Name: %s\n",x.name);
    printf("Marks: %d\n",x.marks);
}

int main()
{
    struct SStudent students[10];
    printf("Enter information of students: \n");
    for (int i=0; i<10; i++)
    students[i] = GetStudent(students[i]);
    printf("\n");
    printf("Displaying information of students: \n");
    for (int i=0; i<10; i++)
    DispStudent(students[i]);
}
