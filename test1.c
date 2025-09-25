/* Find the smallest and largest element in an Array */

#include <stdio.h>

#define N 5

int main(void) {
    int A[N];
    int small, large, i;

    printf("Enter 5 numbers: ");
    for (i = 0; i < N; i++) 
        scanf("%d", &A[i]);
    
    small = A[0];
    large = A[0];
    for (i = 1; i < N; i++) {
        if (A[i] < small)
            small = A[i];
        if (A[i] > large)
            large = A[i];
    }

    printf("small = %d\n", small);
    printf("large = %d\n", large);

    return 0;
}