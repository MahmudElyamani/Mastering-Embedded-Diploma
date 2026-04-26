//--- ✄ --------- 2026.04.26 11:59 -------------------
//Made by Eng. Mahmood Elyamani

#include "queue.h"

Queue q;

/* ================= Queue Core ================= */

void initQueue() {
    q.front = 0;
    q.rear = -1;
}

int isEmpty() {
    return q.front > q.rear;
}

int isFull() {
    return q.rear == MAX - 1;
}

void enqueue(Student s) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    q.data[++q.rear] = s;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    q.front++;
}

/* ================= Menu Functions ================= */

void ManualAddStudent() {
    Student s;

    printf("Enter Roll: ");
    scanf("%d", &s.roll);

    printf("Enter First Name: ");
    scanf("%s", s.fname);

    printf("Enter Course: ");
    scanf("%s", s.course);

    printf("Enter Grade: ");
    scanf("%f", &s.grade);

    enqueue(s);
    printf("Student added successfully!\n");
}

void fileAddStudent() {
    FILE *fp = fopen("students.txt", "r");
    if (!fp) {
        printf("File not found!\n");
        return;
    }

    Student s;
    while (fscanf(fp, "%d %s %s %f", 
                  &s.roll, s.fname, s.course, &s.grade) != EOF) {
        enqueue(s);
    }

    fclose(fp);
    printf("Students loaded from file!\n");
}

void findDR() {
    int roll;
    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for (int i = q.front; i <= q.rear; i++) {
        if (q.data[i].roll == roll) {
            printf("Found: %s | %s | %.2f\n",
                   q.data[i].fname,
                   q.data[i].course,
                   q.data[i].grade);
            return;
        }
    }
    printf("Student not found!\n");
}

void findDN() {
    char name[50];
    printf("Enter First Name: ");
    scanf("%s", name);

    for (int i = q.front; i <= q.rear; i++) {
        if (strcmp(q.data[i].fname, name) == 0) {
            printf("Found Roll: %d | Course: %s | Grade: %.2f\n",
                   q.data[i].roll,
                   q.data[i].course,
                   q.data[i].grade);
        }
    }
}

void findDC() {
    char course[50];
    printf("Enter Course: ");
    scanf("%s", course);

    for (int i = q.front; i <= q.rear; i++) {
        if (strcmp(q.data[i].course, course) == 0) {
            printf("%d | %s | %.2f\n",
                   q.data[i].roll,
                   q.data[i].fname,
                   q.data[i].grade);
        }
    }
}

void findTOT() {
    if (isEmpty()) {
        printf("Total students: 0\n");
    } else {
        printf("Total students: %d\n", q.rear - q.front + 1);
    }
}

void RDelete() {
    int roll;
    printf("Enter Roll to delete: ");
    scanf("%d", &roll);

    for (int i = q.front; i <= q.rear; i++) {
        if (q.data[i].roll == roll) {
            for (int j = i; j < q.rear; j++) {
                q.data[j] = q.data[j + 1];
            }
            q.rear--;
            printf("Deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void RUpdate() {
    int roll;
    printf("Enter Roll to update: ");
    scanf("%d", &roll);

    for (int i = q.front; i <= q.rear; i++) {
        if (q.data[i].roll == roll) {
            printf("Enter new name: ");
            scanf("%s", q.data[i].fname);

            printf("Enter new course: ");
            scanf("%s", q.data[i].course);

            printf("Enter new grade: ");
            scanf("%f", &q.data[i].grade);

            printf("Updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void SShow() {
    if (isEmpty()) {
        printf("No students available.\n");
        return;
    }

    printf("\n--- Student List (FIFO) ---\n");
    for (int i = q.front; i <= q.rear; i++) {
        printf("Roll: %d | Name: %s | Course: %s | Grade: %.2f\n",
               q.data[i].roll,
               q.data[i].fname,
               q.data[i].course,
               q.data[i].grade);
    }
}