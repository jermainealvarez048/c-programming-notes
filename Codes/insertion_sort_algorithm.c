/* Insertion Sort Algorithm */

#include <stdio.h>

#define N 10

int main(void) {
    int A[N] = {5, 2, 1, 10, 7, 9, 4, 8, 3, 6};
    int i, j, temp;

    printf("Before Sorting: ");
    for (i = 0; i < N; i++)
        printf("%3d", A[i]);
    printf("\n");

    for (i = 1; i < N; i++) {
        temp = A[i];
        for (j = i; j > 0 && temp < A[j-1]; j--) {
            A[j] = A[j-1];
        }
        A[j] = temp;
    }

    printf("After Sorting:  ");
    for (i = 0; i < N; i++)
        printf("%3d", A[i]);
    printf("\n");

    return 0;
}