/* Insertion of an element at specified position in an Array */

#include <stdio.h>

#define N 5

int main(void) {
    int A[N+1];
    int position, element, i;

    printf("Enter 5 numbers: ");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    printf("Enter position: ");
    scanf("%d", &position);
    printf("Enter element: ");
    scanf("%d", &element);

    for (i = N; i > position; i--) // 
        A[i] = A[i-1]; // moves the element to the right
    A[position] = element; 

    for (i = 0; i < N+1; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}