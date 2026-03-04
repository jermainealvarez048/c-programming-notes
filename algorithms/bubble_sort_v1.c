/* Bubble Sort Algorithm */
// - check notebook for explanation

#include <stdio.h>

#define N 10

int main(void) {
    int A[N] = {2, 5, 1, 8, 9, 6, 10, 3, 4, 7};
    int i, j, temp;

    printf("Before Sorting: ");
    for (i = 0; i < N; i++)
        printf("%3d", A[i]);
    printf("\n");

    for (i = 1; i < N; i++) {
        for (j = 0; j < N-i; j++) {
            if (A[j] > A[j+1]) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    printf("After Sorting:  ");
    for (i = 0; i < N; i++)
        printf("%3d", A[i]);
    printf("\n");

    return 0;
}