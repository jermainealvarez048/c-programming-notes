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
 *
 * Program Requirements:
 * 1. Data Storage
 *      - Use a 2D array:
 *          - int grades[5][4]'
 *      - represents:
 *          - 5 students
 *          - 4 subjects each
 * 2. Functions You Must Implement
 *      - Function 1: Input Grades
 *          - void inputGrades(int (*p)[4]);
 *          - use a pointer to array
 *          - fill all grades using loops
 *          - use pointer notation inside
 *      - Function 2: Print Grades
 *          - void printGrades(int (*p)[4]);
 *          - print table format
 *          - use pointer arithmetic (not arr[i][j] style only)
 *      - Function 3: Student Average
 *          - double studentAverage(int *studnetRow);
 *          - Takes pointer to one row
 *          - Compute average of 4 subjects
 *          - Return Average
 *
 */