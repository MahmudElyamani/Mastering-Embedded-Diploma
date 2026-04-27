//--- ✄ --------- 2026.04.26 11:59 -------------------
//Made by Eng. Mahmood Elyamani

#include "queue.h"

/*      Fifo Initialization        */
FIFO_Status_t FIFO_Init(FIFO_Buf_t *fifo, Student_info_t *buffer, int length)
{
    if(!fifo || !buffer)
    return FIFO_NULL;

    fifo->base = buffer;
    fifo->head = buffer;
    fifo->tail = buffer;
    fifo->length = length;
    fifo->count = 0;
    return FIFO_NO_ERROR;
}

/*      Check if fifo is full       */
FIFO_Status_t FIFO_IsFull(FIFO_Buf_t *fifo)
{
    if (!fifo)
    return FIFO_NULL;

    if (fifo->length == fifo->count)
    return FIFO_FULL;

    return FIFO_NO_ERROR;
}

/*      Fifo Enqueue        */
FIFO_Status_t FIFO_Enqueue(FIFO_Buf_t *fifo, Student_info_t item)
{
    if(!fifo->base || !fifo->head || !fifo->tail)
    return FIFO_NULL;

    if (FIFO_IsFull(fifo) == FIFO_FULL)
    return FIFO_FULL;

    (*fifo->head) = item;
    fifo->count++;

    /*      Circulating behaviour       */
    if (fifo->head == fifo->base + (fifo->length-1))
    fifo->head = fifo->base;
    else
    fifo->head++;

    return FIFO_NO_ERROR;
}

/*      Fifo Dequeue        */
FIFO_Status_t FIFO_Dequeue(FIFO_Buf_t *fifo, Student_info_t *item)
{
    if(!fifo->base || !fifo->head || !fifo->tail)
    return FIFO_NULL;

    if (FIFO_IsFull(fifo) == FIFO_FULL)
    return FIFO_FULL;

    if (fifo->count == 0)
    return FIFO_EMPTY;

    *item = *fifo->head;
    fifo->count--;

    /*      Circulating behaviour       */
    if (fifo->tail == fifo->base+(fifo->length-1))
    fifo->tail = fifo->base;
    else 
    fifo->tail++;

    return FIFO_NO_ERROR;
}


/* -------- Helper: Find Student by Roll -------- */
static int findIndexByRoll(int roll)
{
    Student_info_t *temp = gBuffer.tail;

    for (int i = 0; i < gBuffer.count; i++)
    {
        if (temp->roll == roll)
            return i;

        if (temp == (gBuffer.base + gBuffer.length - 1))
            temp = gBuffer.base;
        else
            temp++;
    }
    return -1;
}


/*Option(1): Adds student via a seperate file*/
void fileAddStudent()
{
    FILE *fp = fopen("students.txt", "r");
    if (!fp)
    {
        printf("Error!Cannot open file\n");
        return;
    }

    Student_info_t s;

    while (fscanf(fp, "%d %s %s %f %d %d %d %d %d",
                  &s.roll, s.firstName, s.lastName, &s.GPA,
                  &s.courses[0], &s.courses[1], &s.courses[2],
                  &s.courses[3], &s.courses[4]) != EOF)
    {
        if (findIndexByRoll(s.roll) == -1)
            FIFO_Enqueue(&gBuffer, s);
    }

    fclose(fp);
    printf("Students loaded from file\n");
}


/*Option(2): Adds student manually via user input*/
void ManualAddStudent()
{
    Student_info_t s;

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    if (findIndexByRoll(s.roll) != -1)
    {
        printf("Error!Roll number already exists\n");
        return;
    }

    printf("Enter First Name: ");
    scanf("%s", s.firstName);

    printf("Enter Last Name: ");
    scanf("%s", s.lastName);

    printf("Enter GPA: ");
    scanf("%f", &s.GPA);

    printf("Enter 5 Course IDs: ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &s.courses[i]);

    if (FIFO_Enqueue(&gBuffer, s) == FIFO_NO_ERROR)
        printf("Student added successfully\n");
    else
        printf("Error!Queue is full\n");
}


/*Option(3): Finds student details by role number*/
void findDR()
{
    int roll;
    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    Student_info_t *temp = gBuffer.tail;

    for (int i = 0; i < gBuffer.count; i++)
    {
        if (temp->roll == roll)
        {
            printf("Found: %s %s | GPA: %.2f\n",
                   temp->firstName, temp->lastName, temp->GPA);
            return;
        }

        temp = (temp == (gBuffer.base + gBuffer.length - 1)) ? gBuffer.base : temp + 1;
    }

    printf("Error!Student not found\n");
}


/*Option(4): Finds student details by name*/
void findDN()
{
    char name[50];
    int found = 0;

    printf("Enter First Name: ");
    scanf("%s", name);

    Student_info_t *temp = gBuffer.tail;

    for (int i = 0; i < gBuffer.count; i++)
    {
        if (strcmp(temp->firstName, name) == 0)
        {
            printf("Roll: %d | GPA: %.2f\n", temp->roll, temp->GPA);
            found = 1;
        }

        temp = (temp == (gBuffer.base + gBuffer.length - 1)) ? gBuffer.base : temp + 1;
    }

    if (!found)
        printf("Error!No student found\n");
}


/*Option(5): Finds student details by course ID*/
void findDC()
{
    int course, found = 0;

    printf("Enter Course ID: ");
    scanf("%d", &course);

    Student_info_t *temp = gBuffer.tail;

    for (int i = 0; i < gBuffer.count; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (temp->courses[j] == course)
            {
                printf("Roll: %d | Name: %s\n", temp->roll, temp->firstName);
                found = 1;
                break;
            }
        }

        temp = (temp == (gBuffer.base + gBuffer.length - 1)) ? gBuffer.base : temp + 1;
    }

    if (!found)
        printf("Error!No students in this course\n");
}


/*Option(6): Finds the total number of students*/
void findTOT()
{
    printf("Total Students = %d\n", gBuffer.count);
}


/*Option(7): Deletes student details by role number*/
void RDelete()
{
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    int index = findIndexByRoll(roll);

    if (index == -1)
    {
        printf("Error!Student not found\n");
        return;
    }

    Student_info_t tempArr[50];
    int newCount = 0;

    Student_info_t *temp = gBuffer.tail;

    for (int i = 0; i < gBuffer.count; i++)
    {
        if (temp->roll != roll)
            tempArr[newCount++] = *temp;

        temp = (temp == (gBuffer.base + gBuffer.length - 1)) ? gBuffer.base : temp + 1;
    }

    FIFO_Init(&gBuffer, gBuffer.base, gBuffer.length);

    for (int i = 0; i < newCount; i++)
        FIFO_Enqueue(&gBuffer, tempArr[i]);

    printf("Student deleted\n");
}


/*Option(8): Updates student details by role number*/
void RUpdate()
{
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    Student_info_t *temp = gBuffer.tail;

    for (int i = 0; i < gBuffer.count; i++)
    {
        if (temp->roll == roll)
        {
            printf("Enter new First Name: ");
            scanf("%s", temp->firstName);

            printf("Enter new Last Name: ");
            scanf("%s", temp->lastName);

            printf("Enter new GPA: ");
            scanf("%f", &temp->GPA);

            printf("Updated successfully\n");
            return;
        }

        temp = (temp == (gBuffer.base + gBuffer.length - 1)) ? gBuffer.base : temp + 1;
    }

    printf("Error!Student not found\n");
}


/*Option(9): Shows information for all students in the list*/
void SShow()
{
    Student_info_t *temp = gBuffer.tail;

    printf("==== Student List ====\n");

    for (int i = 0; i < gBuffer.count; i++)
    {
        printf("Roll: %d | Name: %s %s | GPA: %.2f\n",
               temp->roll, temp->firstName, temp->lastName, temp->GPA);

        temp = (temp == (gBuffer.base + gBuffer.length - 1)) ? gBuffer.base : temp + 1;
    }
}