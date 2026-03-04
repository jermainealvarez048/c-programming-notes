//
// Created by Jermaine Alvarez on 2/19/2026.
//

/* Project: Mini Student Record System (Pointers Edition)
 *
 * Goal:
 * Write a program that:
 * 1. Stores grades for 5 students
 * 2. Each student has 4 subjects
 * 3. Calculates:
 *      - Each student's averate
 *      - Class average
 * 4. Allows modifying grades using pointers
 * 5. Uses:
 *      - 2D arrays
 *      - Pointer to array
 *      - Arrays of pointers
 *      - Pointer to pointer
 */

#include <stdio.h>

#define STUD_NUM 3
#define SUB_NUM 2

void input_grades(int (*p)[SUB_NUM]);
void print_grades(int (*p)[SUB_NUM]);
double student_average(int *stud_row);
double class_average(int (*p)[SUB_NUM]);
void modify_grade(int **stud_ptr, int sub_index, int new_grade);

int main(void) {
    int grades[STUD_NUM][SUB_NUM];
    char op;

    do {
        int choice, stud, sub, grade;
        int *student_ptrs[STUD_NUM];

        printf("\n----Mini Student Record System----\n");
        printf("1] Input Grades\n");
        printf("2] Print Grades\n");
        printf("3] Student Average\n");
        printf("4] Class Average\n");
        printf("5] Modify a Grade\n");
        printf("6] Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: input_grades(grades);
                break;
            case 2: print_grades(grades);
                break;
            case 3: 
                printf("Enter student (1-%d): ", STUD_NUM);
                scanf("%d", &stud);
                printf("Student %d average: %.2f\n", stud, student_average(grades[stud-1]));
                break;
            case 4: 
                printf("Class Average: %.2f\n", class_average(grades));
                break;
            case 5:
                printf("Enter student (1-%d): ", STUD_NUM);
                scanf("%d", &stud);
                printf("Enter subject (1-%d): ", SUB_NUM);
                scanf("%d", &sub);
                printf("New grade: ");
                scanf("%d", &grade);
                for (int i = 0; i < STUD_NUM; i++)
                    student_ptrs[i] = grades[i];
                modify_grade(&student_ptrs[stud-1], sub, grade);
                break;
            case 6: printf("Thank You!\n"); break;
        }

        printf("\nChoose again (Y/n): ");
        scanf(" %c", &op);
    } while (op == 'Y' || op == 'y');

    return 0;
}

void input_grades(int (*p)[SUB_NUM]) {
    int i, j;
    for (i = 0; i < STUD_NUM; i++) {
        printf("\nEnter grades for student %d:\n", i + 1);
        for (j = 0; j < SUB_NUM; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", (*(p + i) + j));
        }
    }
}

void print_grades(int (*p)[SUB_NUM]) {
    int i, j;
    for (i = 0; i < STUD_NUM; i++) {
        printf("\nStudent %d grades:\n", i + 1);
        for (j = 0; j < SUB_NUM; j++)
            printf("Subject %d: %d\n", j + 1, *(*(p + i) + j));
    }
}

double student_average(int *stud_row) {
    int i, total = 0;
    for (i = 0; i < SUB_NUM; i++) {
        total += *(stud_row + i);
    }
    return (double) total / SUB_NUM;
}

double class_average(int (*p)[SUB_NUM]) {
    int i, j, total = 0;
    for (i = 0; i < STUD_NUM; i++) 
        for (j = 0; j < SUB_NUM; j++)
            total += *(*(p + i) + j);
    return (double) total / (STUD_NUM * SUB_NUM);
}

void modify_grade(int **stud_ptr, int sub_index, int new_grade) {
    *(*stud_ptr + sub_index) = new_grade;
}