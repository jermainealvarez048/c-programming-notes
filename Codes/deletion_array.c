/* Deletion of an Element from a Specified Position in an Array */

#include <stdio.h>

#define N 5

int main(void) {
    int A[N];
    int position, i;

    printf("Enter 5 numbers: ");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    printf("Enter position to remove (0-4): ");
    scanf("%d", &position);

    for (i = position; i < N; i++)
        A[i] = A[i+1];

    for (i = 0; i < N-1; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}